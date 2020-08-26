// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Xiaoling Bao
// Update: 2020-08-26
#ifndef AUTODRIVE_VISION_VISION_PROCESSOR_H_
#define AUTODRIVE_VISION_VISION_PROCESSOR_H_

#include <framework/ad_service.h>

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<cmath>
#include<iostream>
#include<vector>

namespace autodrive {
namespace vision {

class SurroundView final : public AdService {
 public:
  /// @brief Get instance
  ///
  /// @return service instance
  static SurroundView& GetInstance() noexcept;

  /// @brief merge function
  void showManyImages(std::vector<cv::Mat>& src, cv::Size imgSize, cv::Mat& dst);
};

}
}

#endif AUTODRIVE_VISION_VISION_PROCESSOR_H_

/* vim: set ts=2 sw=2 sts=2 tw=100 et: */