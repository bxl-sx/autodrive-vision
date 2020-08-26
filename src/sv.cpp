#include "sv.h"
using namespace std;
using namespace cv;

namespace autodrive {
namespace vision {

SurroundView& SurroundView::GetInstance() noexcept {
  static SurroundView instance;
  return instance;
}

//在一幅图像上显示多张图像
void SurroundView::showManyImages(std::vector<Mat>& src, cv::Size imgSize, cv::Mat& dst)
{
	int nNumImages = src.size();
	Size nSizeWindows;
	if (nNumImages > 12)
	{
		std::cout << "Not more than 12 images!" << endl;
		return;
	}
	//根据图片数量确定分割小窗口的排布
	switch (nNumImages)
	{
	case 1:nSizeWindows = Size(1, 1); break;
	case 2:nSizeWindows = Size(2, 1); break;
	case 3:
	case 4:nSizeWindows = Size(2, 2); break;
	case 6:nSizeWindows = Size(3, 2); break;
	case 8:nSizeWindows = Size(4, 2); break;
	case 9:nSizeWindows = Size(3, 3); break;
	default:nSizeWindows = Size(4, 3); break;
	}
	//设置图像的大小，图像之间的间隔以及边界
	int nShowImageSize = 200;
	int nSplitLineSize = 15;
	int nAroundLineSize = 50;
	// //创建输出图像的大小
	// int imageWidth = nShowImageSize*nSizeWindows.width + (nShowImageSize - 1)*nSplitLineSize + nAroundLineSize;
	// int imageHeight = nShowImageSize*nSizeWindows.height + (nShowImageSize - 1)*nSplitLineSize + nAroundLineSize;
	// Mat showWindowImages(imageHeight, imageWidth, CV_8UC3, Scalar::all(0));
	//提取小图像左上角坐标
	int posX = nAroundLineSize / 2;
	int posY = nAroundLineSize / 2;
	cout << "posX: " << posX << " posY: " << posY << endl;
	int tempPosX = posX;
	int tempPosY = posY;
	//将每张小图整合到大图中
	for (int i = 0; i < nNumImages; i++)
	{
		if ((i%nSizeWindows.width == 0) && (tempPosX != posX))
		{
			tempPosX = posX;
			tempPosY += (nSplitLineSize + nShowImageSize);
		}
		//利用Rect区域将小图像置于大图像相应区域
		Mat tempImage = dst(Rect(tempPosX, tempPosY, nShowImageSize, nShowImageSize));
		//利用resize实现图像缩放
		resize(src[i],tempImage,Size(nShowImageSize,nShowImageSize));
		tempPosX += nSplitLineSize + nShowImageSize;
	}
	imshow("showWindowImages",dst);
	// imwrite("/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/picturemerge.jpg", dst);

}
}

}  // namespace autodrive

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */
 
