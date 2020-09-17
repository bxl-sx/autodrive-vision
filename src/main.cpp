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
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#include <framework/ad_exception.h>
#include "vision_processor.h"
// #include "surround/surround_view.h"

// void vision_shutdown(){
//   log4cxx::LogManager::shutdown();
// }

int main(int argc, char* argv[])
{
  // atexit(vision_shutdown);
  log4cxx::PropertyConfigurator::configureAndWatch("../log4cxx.properties");
  log4cxx::LoggerPtr logger{log4cxx::Logger::getLogger("vision")};
  try {
    autodrive::vision::VisionProcessor::CheckMode();
    autodrive::vision::VisionProcessor::SetLogger("vision");
    autodrive::vision::VisionProcessor& service{
        autodrive::vision::VisionProcessor::GetInstance()};
    service.Init("vision.cfg");
    service.StartUp();
  } catch (autodrive::AdException& e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  } catch (...) {
    std::cout << "Internal error" << std::endl;
  }
  return 0;

//   return 0;
}
 
 
/* vim: set ts=2 sw=2 sts=2 tw=100 et: */
// posX: 25 posY: 25