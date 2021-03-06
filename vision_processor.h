// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
//Update: 2020-08-17
#ifndef AUTODRIVE_VISION_VISION_PROCESSOR_H_
#define AUTODRIVE_VISION_VISION_PROCESSOR_H_

#include <framework/ad_service.h>

#include "framework/ad_redis_manager.h"
#include "framework/ad_resource_manager.h"
#include "surround/surround_view.h"

#include <opencv2/opencv.hpp>
#include <vector>
#include <functional>
#include <utility>
#include <chrono>

namespace autodrive {
namespace vision {

class VisionProcessor final : public AdService {
 public:
  /// @brief Get instance
  ///
  /// @brief service instance
  static VisionProcessor& GetInstance() noexcept;

  ~VisionProcessor() noexcept final;
  VisionProcessor(VisionProcessor const&) = delete;
  VisionProcessor& oprator=(VisionProcessor const&) = delete;
  VisionProcessor(VisionProcessor&&) = delete;
  VisionProcessor& oprator=(VisionProcessor&&) = delete;

  /// @brief Initialize the service before start up
  ///
  /// @param config_file_path  config file for the service
  ///
  /// @throw InvalidConfigException  when config file is not valid
  /// @throw FileNotFoundException  when config file does not exist
  /// @throw std::bad_alloc  when memory not enough  
  void Init(std::string const& config_file_path, std::string const& yml_file_dir) noexcept(false) final;

  // void Init_();


  /// @brief Start up the service
  ///
  /// @throw SensorInitFailedException  when sensor opening failed
  void StartUp() noexcept(false) final;

  /// @brief Only override this when resources need to be released
  /// Stop the service after all current work cleared and release all resources
  /// Remember to call AdService::Destroy() in this function
  void Destroy() noexcept final;

  /// @brief graceful exit
  void GracefulExit() noexcept;

  //*****************************************
  /// @brief Task function of surround view
  void image_task() noexcept;
  // void write_image() noexcept;
//  protected:
 private:
  /// @brief Constructor
  VisionProcessor() noexcept;

//   void sv_callback(SurroundView::Image& vision_data) noexcept;
  
 private:
  // std::string const& image_file_dir = ...;
  vector<std::string> cam_filepath(4);
  std::string dst_filepath;
  /// @brief the output surround view image 
  SurroundView::Image dst_img;
  /// @brief cam_imgs stores four camera images
  std::vector<SurroundView::Image> cam_imgs;
  /// @brief graceful exit
  bool graceful_exit_{false};  
};

}
}

#endif //AUTODRIVE_VISION_VISION_PROCESSOR_H_

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */
