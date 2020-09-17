aux_source_directory(. DIRSRCS)
aux_source_directory(./surround DIRSRCS_SURROUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
message("PROJECT_BINARY_DIR = " ${PROJECT_BINARY_DIR})
message("PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR})
add_executable(vision 
${DIRSRCS}
${DIRSRCS_SURROUND}
)

add_library(advision SHARED
${DIRSRCS}
${DIRSRCS_SURROUND}

)

set_target_properties(advision PROPERTIES OUTPUT_NAME "advision")
set_target_properties(advision PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(advision PROPERTIES VERSION 1 SOVERSION 1)

# if(BUILD_ATOM)
# target_link_libraries(
#  vision 
#  adinterface adalgorithm adsensormodel adframework adpublic adcalibrationapi
#	hiredis log4cxx rt boost_thread protobuf zmq jpeg
#	adsensorcommon adcalmcarcamera admobileyecamera adleopardcamera
#	icsneocpp calmcar_sdk canlib restbed jsoncpp
#	${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${OpenCV_LIBS}
#)
#else()
target_link_libraries(
  vision 
#   adinterface 
#   adalgorithm 
	adsensormodel 
	adframework adpublic 
#	adcalibrationapi
	hiredis log4cxx rt boost_thread protobuf zmq jpeg
#	adsensorcommon adcalmcarcamera admobileyecamera adleopardcamera
	icsneocpp calmcar_sdk canlib restbed jsoncpp
	${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${OpenCV_LIBS}
)
#endif()

