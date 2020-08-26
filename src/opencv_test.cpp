// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-26
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/logmanager.h>
#include<iostream>
#include<vector>

// #include <framework/ad_exception.h>
#include "sv.h"
int main()
{
//   try {
    autodrive::vision::SurroundView& service{
        autodrive::vision::SurroundView::GetInstance()};
    
  //}
	std::vector<cv::Mat> src(4);
    int nNumImages = src.size();
	cv::Size nSizeWindows = cv::Size(2, 2);

	//设置图像的大小，图像之间的间隔以及边界
	int nShowImageSize = 200;
	int nSplitLineSize = 15;
	int nAroundLineSize = 50;
	//创建输出图像的大小
	int imageWidth = nShowImageSize*nSizeWindows.width + (nShowImageSize - 1)*nSplitLineSize + nAroundLineSize;
	int imageHeight = nShowImageSize*nSizeWindows.height + (nShowImageSize - 1)*nSplitLineSize + nAroundLineSize;        
    cv::Mat dst(imageHeight, imageWidth, CV_8UC3, cv::Scalar::all(0));
    const std::string img_dir = "/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/";
    
    // std::string img0_path = img_dir + "img0.jpg";
    // std::cout << img0_path << std::endl;

	src[0] = cv::imread(img_dir + "img0.jpg");
	src[1] = cv::imread(img_dir + "img1.jpg");
	src[2] = cv::imread(img_dir + "img2.jpg");
	src[3] = cv::imread(img_dir + "img3.jpg");

    // /home/xl/projects/autodrive/autodrive-vision/images/picturemerge
	// src[0] = imread("/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/img0.jpg");
	// src[1] = imread("/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/img1.jpg");
	// src[2] = imread("/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/img2.jpg");
	// src[3] = imread("/home/xl/projects/autodrive/autodrive-vision/images/picturemerge/img3.jpg");    

	for (int i = 0; i < src.size(); i++)
	{
		if (!src[i].data){
          std::cout << "read image file img" << i << " fail!" << std::endl;
          return -1;
        }
			// return -1;
	}
	
	service.showManyImages(src, cv::Size(512, 400), dst);
    cv::imwrite(img_dir + "picturemerge.jpg", dst);
	cv::waitKey(0);
//   }
  return 0;
}
 
 
/* vim: set ts=2 sw=2 sts=2 tw=100 et: */
// posX: 25 posY: 25