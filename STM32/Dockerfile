FROM ubuntu:16.04
RUN apt-get -y update && \
    apt-get -y install software-properties-common && \
    add-apt-repository -y ppa:team-gcc-arm-embedded/ppa && \
    apt-get -y update && \
    apt-get install -y gcc-arm-embedded && \
    apt-get -y install git cmake && \
    apt-get purge -y --auto-remove
RUN apt-get install -y --no-install-recommends git make cmake autoconf libusb-1.0.0-dev \
    && apt-get install -y --no-install-recommends ca-certificates
RUN arm-none-eabi-gcc --version
COPY ./stm32f103c8t6 /STM32
RUN apt-get -y --reinstall install python-minimal
WORKDIR /STM32
RUN pwd && make
RUN git clone https://github.com/texane/stlink.git && cd ./stlink && make && cd build/Release && make install && ldconfig
