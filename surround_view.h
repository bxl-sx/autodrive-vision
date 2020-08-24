// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Peixin Hou
// Created: 2019-09-19

#ifndef AUTODRIVE_VISION_SURROUND_H_
#define AUTODRIVE_VISION_SURROUND_H_
#include <iomanip>
#include <iostream>
#include <GL/glu.h>
#include <boost/filesystem.hpp>
#include <log4cxx/logger.h>


namespace autodrive {
namespace vision {

class SurroundView{
 public:
  // Image
  struct Image {
    /// @brief Width
    std::uint16_t width;
    /// @brief Height
    std::uint16_t height;
    /// @brief Element size
    std::unit8_t element_size;
    /// @brief Image pointer
    std::uint8_t* data_ptr;
  }

  /// @brief Single mode of class SurroundView
  ///
  /// @return the single object reference of class SurroundView
  static SurroundView& GetInstance() noexcept;

  /// @brief Initialize SurroundView
  ///
  /// @param yml_file_dir  yml file path
  void Init(std::string const& yml_file_dir) noexcept(false);

  /// @brief stitch the four cam images
  ///
  /// @param dst_img the output surround view image
  /// @param cam_imgs stores the front camera img, the left camera img, the back camera img and the right camera img
  void stitch(Image& dst_img, std::vector<Image>& cam_imgs);

  /// @brief get cam position in the car coordinate system
  ///
  /// @param 
  void get_cam_position_in_car_coordinate();

private:
  SurroundView() noexcept(false) = default;
  ~SurroundView() noexcept = default;
  SurroundView(SurroundView const&) = delete;
  SurroundView& operator=(SurroundView const&) = delete;
  SurroundView(SurroundView&&) = delete;
  SurroundView& operator=(SurroundView&&) = delete;


  const void perspective_to_maps(const Image perspective_mat, 
                                          Image& map1, Image& map2);
  
private:
  /// @brief Max config line length
  static constexpr std::uint16_t kMaxConfigLineLength{1000U};
  /// @brief Logger
  static log4cxx::LoggerPtr logger_;
  /// @brief opencv intrinsic parameters K
  std::map<uint,Image> cam_intrinsic_K_;
  /// @brief opencv intrinsic parameters D
  std::map<uint,Image> cam_intrinsic_D_;
  /// @brief  extrinsic parameters: from car center coordinate system to camera coordinate system
  std::map<uint, cv::Affine3d> car2cam_extrinsic_;
  /// @brief the final birdview picture size (width ,height)
  Size birdviewSize_;
  /// @brief the physical car size (width, length) in cm;
  Size carSize_;
  /// @brief the rectify Look Up Tabel (LUT) maps (intrinsic parameters)
  std::map<uint, Image> cam_rectifyMap1_;
  std::map<uint, Image> cam_rectifyMap2_;
  /// @brief transform from the car center coordinate system to the final birdview coordinate system
  cv::Affine3d aff_car2birdview_;
  /// @brief the inverse perspective mapping (IPM) LUT maps
  std::map<uint, Image> cam_ipm_map1_;
  std::map<uint, Image> cam_ipm_map2_;
  /// @brief rectification transformation in the object space
  Image r_mat_;
  /// @brief scale factor (far or near from the camera to the object) for the rectification transformation in the object space
  double scale_factor_;//possible values are:0.33, 0.7, 0.5, 1
  /// @brief the roi picture of each camera in the final birdview picture
  std::map<uint, Image> cam_roi_mat_;
  /// @brief four corners in the car center coordinate
  std::map<uint, std::vector<cv::Point3f>> cornerInCar_;
  /// @brief four corners in the image
  std::map<uint, std::vector<cv::Point2f>> cornerInPixel_;
  /// @brief four corners in the birdview image
  std::map<uint, std::vector<cv::Point2f>> cornerInBirdview_;
  /// @brief cam position in car coordinate
  std::map<uint, cv::Vec3d> cam_in_car_coordinate_;
  /// @brief cam position in birdview coordinate
  std::map<uint, cv::Point2f> cam_in_birdview_coordinate_;
};

} // namespace vision
} // namespace autodrive
#endif 
