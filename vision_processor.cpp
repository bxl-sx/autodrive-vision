// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-20
#include "vision_processor.h"
#include <log4cxx/logger.h>

#include <opencv2/opencv.hpp>

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
  AdService::Init(config_file_path, );
  SurroundView::Init(yml_file_dir);
  SetStatus(AdService::Status::INITIALIZED);
  std::cout << "Status INITIALIZED" << sed::endl;
  LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
}

void VisionProcessor::Init_() {
  SetStatus(AdService::Status::INITIALIZED);
  std::cout << "Status INITIALIZED" << sed::endl;
  LOG4CXX_INFO(GetLogger(), "INIT SUCCESS");
}

void StartUp() noexcept(false) {
  if (GetStatus() == AdService::Status::INITIALIZED ||
      GetStatus() == AdService::Status::STOPPED) {
    
    //start surround view stitch
    // SurroundView::GetInstance().stitch(std::bind(&VisionProcessor::read_image, ));
    SurroundView::GetInstance().stitch();
    }

    std::cout << "Status RUNNING" << std::endl;
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

void VisionProcessor::read_image(std::string const& image_file_dir, std::vector<SurroundView::Image>& cam_imgs) {
  cv::Mat in_image, out_image;
  in_image = cv2.imread(path, flags = 1);
  if (in_image.empty()) {
    std::cout << "Error! Input image cannot be read..." << std::endl;
  }
}
//**********************************

}

}
}  // namespace autodrive

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */