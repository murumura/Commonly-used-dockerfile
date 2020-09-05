#!/bin/bash
# Expose the X server on the host.
sudo xhost +local:root
# --rm: Make the container ephemeral (delete on exit).
# -it: Interactive TTY.
# --gpus all: Expose all GPUs to the container.
docker run \
  --rm \
  -it \
  --gpus all \
  -v /home/steven/桌面/Commonly-used-dockerfile/openGL-GPU/opengl_test:/home/opengl_test \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -e DISPLAY=$DISPLAY \
  -e QT_X11_NO_MITSHM=1 \
  glvnd-x \
  bash