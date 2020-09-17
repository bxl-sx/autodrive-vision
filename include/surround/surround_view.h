// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-26
#ifndef AUTODRIVE_VISION_SURROUND_VIEW_H_
#define AUTODRIVE_VISION_SURROUND_VIEW_H_
#include <framework/ad_service.h>

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<cmath>
#include<iostream>
#include<vector>

namespace autodrive {
namespace vision {

class SurroundView {
 public:
  /// @brief Get instance
  ///
  /// @return service instance
  static SurroundView& GetInstance() noexcept;

  /// @brief Initialize SurroundView
  ///
  /// @param yml_file_dir  yml file path
  void Init(std::string const& yml_file_dir) noexcept(false);

  /// @brief merge function
  void stitch(std::vector<cv::Mat>& src, cv::Mat& dst);
};

}
}

#endif // AUTODRIVE_VISION_SURROUND_VIEW_H_

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */