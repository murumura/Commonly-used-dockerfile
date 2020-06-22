FROM ubuntu:18.04
RUN apt-get -y update && \
    apt-get -y install gcc build-essential && \
    apt-get -y install software-properties-common && \
    add-apt-repository -y ppa:team-gcc-arm-embedded/ppa && \
    apt-get -y update && \
    apt-get install -y gcc-arm-embedded && \
    apt-get -y install git cmake
#install Debugging dependancies

RUN apt-get install -y --no-install-recommends git make cmake autoconf libusb-1.0.0-dev \
    && apt-get install -y --no-install-recommends ca-certificates
RUN apt-get install -y mlocate
RUN updatedb && locate libusb.h
RUN arm-none-eabi-gcc --version
RUN apt-get install -y automake 
RUN apt-get install -y pkg-config
RUN apt-get install -y autoconf automake libtool
RUN apt-get install -y libsysfs-dev
COPY ./stm32f103c8t6 /STM32
RUN apt-get -y --reinstall install python-minimal
WORKDIR /STM32
RUN pwd && make

RUN git clone https://github.com/texane/stlink.git && cd ./stlink && make && cd build/Release && make install && ldconfig


