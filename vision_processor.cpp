// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-24
#include "vision_processor.h"
// #include "framework/ad_resource_manager.h"
#include <log4cxx/logger.h>

// #include <opencv2/opencv.hpp>

namespace autodrive{
namespace vision{

VisionProcessor& VisionProcessor::GetInstance() noexcept {
    static VisionProcessor instance;
    return instance;
}

VisionProcessor::VisionProcessor() noexcept
    : AdService{}{}

VisionProcessor::~VisionProcessor() {Destroy();}

void VisionProcessor::Init(std::string const& config_file_path, std::string const& yml_file_dir) noexcept(false) {
  AdService::Init(config_file_path);
  
  // Init surround view
  SurroundView::GetInstance().Init(yml_file_dir);

  SetStatus(AdService::Status::INITIALIZED);
  Vps_printf("Status INITIALIZED\n");
  LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
}

// void VisionProcessor::Init_(std::string const& yml_file_dir) {
//   // Init surround view
//   SurroundView::GetInstance().Init(yml_file_dir);
//   SetStatus(AdService::Status::INITIALIZED);
//   Vps_printf("Status INITIALIZED\n");
//   LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
// }

void StartUp() noexcept(false) {
  AdScheduler& scheduler{AdScheduler::GetInstance();
  if (GetStatus() == AdService::Status::INITIALIZED ||
      GetStatus() == AdService::Status::STOPPED) {
    auto now{std::chrono::system_clock::now()};
    AdScheduler::Task task{std::bind(&VisionProcessor::image_task, this), now, 0,
      resource_manager.GetPriority(CommonSettings::kCameraServiceTaskName),
      resource_manager.GetCpuMask(CommonSettings::kCameraServiceTaskName)};
    //start surround view stitch
    // SurroundView::GetInstance().stitch();
    // image_task();
    scheduler.Schedule(std::move(task));
    }

    Vps_printf("Status RUNNING\n");
    LOG4CXX_DEBUG(GetLogger(), "Status RUNNING");
    SetStatus(AdService::Status::RUNNING);
}

void VisionProcessor::Destroy noexcept {
  AdService::Destroy();
  SetStatus(AdService::Status::DESTROYED);
}

void VisionProcessor::GracefulExit() noexcept{
  graceful_exit_ = true;
}

void VisionProcessor::image_task() {
  cv::Mat in_Mat, out_Mat;
  // SurroundVIew::Image dst_img;
  std::vector<SurroundView::Image> cam_imgs(4);
  for (i = 0; i < 4; i++) c{
    in_Mat = cv::imread(cam_filepath[i]);
    if (in_Mat.empty()) {
      Vps_printf("Error! Input image cannot be read...\n");
  }
    if (in_Mat.isContinuous()) {
      cam_imgs[i].data_ptr = in_Mat.data;
    }
  }
  // in_Mat = cv2.imread(path, flags = 1);

  SurroundView::GetInstance().stitch(dst_img, cam_imgs);
  // write image file
  std::uint8_t* data_ptr_ = dst_img.data_ptr;
  std::uint8_t** array = new std::unit8[dst_img.width][dst_img.height];
  for (std::int32_t i = 0; i < dst_img.width) {
    for (std::int32_t j = 0; j < dst_img.height) {
      array[i][j] = dst_ptr[i * dst_img.height + j];
    }
  }
  cv::Mat img(dst_img.width, dst_img.height, CV_8UC1, array);
  delete array;
  cv2.imwrite(dst_filepath, dst_img);
}

}
}  // namespace autodrive

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */