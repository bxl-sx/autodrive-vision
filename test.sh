car_project_name = picturemerge

img_path = ./images/${car_project_name}

# if the project directory do not exist, we create the directory and copy the template yml file to the project directory
if [ -d ./data/${car_project_name} ]; then
    echo "We are woking in the ${car_project_name} project!"
else
    echo "Creating our new project: ${car_project_name}"
    mkdir -p ./data/${car_project_name}/init_extrinsic_imgs #this directory stores the extrinsic initialization calibration images
    mkdir -p ${extrinsic_optimization_img_path} #this cross_imgs directory stores the extrinsic calibration images in the overlapping area of nearby cameras
    cp ./data/ruler_frame_template.yml ./data/${car_project_name}/ruler_frame.yml
    return
fi

# ##拼接
# ./opencv_test -save_yml_dir=./data/${car_project_name} -img_dir=${extrinsic_optimization_img_path}
./opencv_test