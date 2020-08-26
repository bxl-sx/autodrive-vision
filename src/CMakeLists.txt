aux_source_directory(. DIRSRCS)
aux_source_directory(./adapter DIRSRCS_ADAPTER)
aux_source_directory(./data-task DIRSRCS_DATA_TASK)
aux_source_directory(./light DIRSRCS_TRAFFIC_LIGHT)
aux_source_directory(./calibration DIRSRCS_CALIBRATION)
aux_source_directory(../proto DIR_PROTO_SRCS)
aux_source_directory(./lane DIRSRCS_LANE)
aux_source_directory(./obstacle DIRSRCS_OBSTACLE)
aux_source_directory(./sign DIRSRCS_SIGN)
aux_source_directory(./obstacle/common DIRSRCS_OBSTACLE_COMMON)
aux_source_directory(./obstacle/common/preprocess DIRSRCS_OBSTACLE_COMMON_P)
aux_source_directory(./obstacle/frbsd DIRSRCS_OBSTACLE_FRBSD)
aux_source_directory(./obstacle/sur DIRSRCS_OBSTACLE_SUR)
aux_source_directory(./obstacle/supplier DIRSRCS_OBSTACLE_SUPPLIER)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_executable(vision 
${DIRSRCS}
${DIRSRCS_ADAPTER}
${DIRSRCS_DATA_TASK}
${DIR_PROTO_SRCS}
${DIRSRCS_CALIBRATION}
${DIRSRCS_OBSTACLE}
${DIRSRCS_LANE}
${DIRSRCS_SIGN}
${DIRSRCS_TRAFFIC_LIGHT}
${DIRSRCS_OBSTACLE_COMMON}
${DIRSRCS_OBSTACLE_COMMON_P}
${DIRSRCS_OBSTACLE_FRBSD}
${DIRSRCS_OBSTACLE_SUR}
${DIRSRCS_OBSTACLE_SUPPLIER}
)

add_library(advision SHARED
${DIRSRCS}
${DIRSRCS_ADAPTER}
${DIRSRCS_DATA_TASK}
${DIR_PROTO_SRCS}
${DIRSRCS_CALIBRATION}
${DIRSRCS_OBSTACLE}
${DIRSRCS_LANE}
${DIRSRCS_SIGN}
${DIRSRCS_TRAFFIC_LIGHT}
${DIRSRCS_OBSTACLE_COMMON}
${DIRSRCS_OBSTACLE_COMMON_P}
${DIRSRCS_OBSTACLE_FRBSD}
${DIRSRCS_OBSTACLE_SUR}
${DIRSRCS_OBSTACLE_SUPPLIER}
)

set_target_properties(advision PROPERTIES OUTPUT_NAME "advision")
set_target_properties(advision PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(advision PROPERTIES VERSION 1 SOVERSION 1)

if(BUILD_ATOM)
target_link_libraries(
  vision 
  adinterface adalgorithm adsensormodel adframework adpublic adcalibrationapi
	hiredis log4cxx rt boost_thread protobuf zmq jpeg
	adsensorcommon adcalmcarvision admobileyevision adleopardvision
	icsneocpp calmcar_sdk canlib restbed
	${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${OpenCV_LIBS}
)
else()
target_link_libraries(
  vision 
  adinterface adalgorithm adsensormodel adframework adpublic adcalibrationapi
	hiredis log4cxx rt boost_thread protobuf zmq jpeg
	adsensorcommon adcalmcarvision admobileyevision adleopardvision
	icsneocpp calmcar_sdk canlib restbed 
	${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${OpenCV_LIBS}
)
endif()
