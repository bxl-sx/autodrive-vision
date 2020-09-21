// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-24
#include "vision_processor.h"
#include "framework/ad_resource_manager.h"
#include <log4cxx/logger.h>

#include <opencv2/opencv.hpp>
// #include <common_settings.h>

namespace autodrive{
namespace vision{

VisionProcessor& VisionProcessor::GetInstance() noexcept {
    static VisionProcessor instance;
    return instance;
}

VisionProcessor::VisionProcessor() noexcept
    : AdService{}{}

VisionProcessor::~VisionProcessor() {Destroy();}

void VisionProcessor::Init(std::string const& config_file_path) noexcept(false) {
  AdService::Init(config_file_path);

  SetStatus(AdService::Status::INITIALIZED);
  std::cout << "Status INITIALIZED" << std::endl;
  LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
}

void VisionProcessor::Init(std::string const& config_file_path, std::string const& yml_file_dir) {
  AdService::Init(config_file_path);
  
  // Init surround view
  // SurroundView::GetInstance().Init(yml_file_dir);
  SurroundView::GetInstance().Init(yml_file_dir);
  SetStatus(AdService::Status::INITIALIZED);
  std::cout << "Status INITIALIZED" << std::endl;
  LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
}

void VisionProcessor::StartUp() noexcept(false) {
  // AdScheduler& scheduler{AdScheduler::GetInstance()};
  // AdResourceManager& resource_manager{AdResourceManager::GetInstance()};
  if (GetStatus() == AdService::Status::INITIALIZED ||
      GetStatus() == AdService::Status::STOPPED) {
  //   auto now{std::chrono::system_clock::now()};
    // AdScheduler::Task task{std::bind(&VisionProcessor::mat_task, this), now, 0,
    //   resource_manager.GetPriority(CommonSettings::kCameraServiceTaskName),
    //   resource_manager.GetCpuMask(CommonSettings::kCameraServiceTaskName)};
    // //start surround view stitch
    autodrive::vision::SurroundView& sv{
      autodrive::vision::SurroundView::GetInstance()};
    std::vector<cv::Mat> src(4);
    // int nNumImages = src.size();
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

	  src[0] = cv::imread(img_dir + "img0.jpg");
	  src[1] = cv::imread(img_dir + "img1.jpg");
	  src[2] = cv::imread(img_dir + "img2.jpg");
	  src[3] = cv::imread(img_dir + "img3.jpg");  

  	for (std::uint8_t i = 0; i < src.size(); i++)
	  {
	  	if (!src[i].data){
          std::cout << "read image file img" << i << " fail!" << std::endl;
          
        }
	  }
	  //cv::Size(512, 400)
	  sv.stitch(src, dst);
    cv::imwrite(img_dir + "picturemerge.jpg", dst);
	  // cv::waitKey(0);
    // scheduler.Schedule(std::move(task));
    }

  std::cout << "Status RUNNING" << std::endl;
  LOG4CXX_DEBUG(GetLogger(), "Status RUNNING");
  SetStatus(AdService::Status::RUNNING);
}

void VisionProcessor::Destroy() noexcept {
  AdService::Destroy();
  SetStatus(AdService::Status::DESTROYED);
}

void VisionProcessor::GracefulExit() noexcept{
  graceful_exit_ = true;
}

void VisionProcessor::mat_task() noexcept {
  std::vector<cv::Mat> in_Mat;
  cv::Mat out_Mat;
  // SurroundVIew::Image dst_img;
//   std::vector<cv::Mat> cam_imgs(4);
  for (std::uint8_t i = 0; i < 4; i++) {
    in_Mat.push_back(cv::imread(cam_filepath[i]));
//     if (in_Mat.empty()) {
//       std::cout << "Error! Input image cannot be read..." << std::endl;
//   }
//     if (in_Mat.isContinuous()) {
//       cam_imgs[i].data_ptr = in_Mat.data;
//     }
  }
  // in_Mat = cv2.imread(path, flags = 1);

  SurroundView::GetInstance().stitch(in_Mat, out_Mat);
  // write image file
//   std::uint8_t* data_ptr_ = dst_img.data_ptr;
//   std::uint8_t** array = new std::unit8[dst_img.width][dst_img.height];
//   for (std::int32_t i = 0; i < dst_img.width) {
//     for (std::int32_t j = 0; j < dst_img.height) {
//       array[i][j] = dst_ptr[i * dst_img.height + j];
//     }
//   }
//   cv::Mat img(dst_img.width, dst_img.height, CV_8UC1, array);
//   delete array;
  cv::imwrite(dst_filepath, out_Mat);
}

}
}  // namespace autodrive

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */