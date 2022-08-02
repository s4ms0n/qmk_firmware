Use docker build to flash the keyboard:
For left half:
util/docker_build.sh ergodox_infinity:samsons_layout:dfu-util
For right half:
util/docker_build.sh ergodox_infinity:samsons_layout:"dfu-util MASTER=right"

Delete
-       --user $(id -u):$(id -g) \
line from the util/docker_build.sh script
