FROM tensorflow/tensorflow:latest-gpu-py3
RUN apt-get update && apt-get install -y --no-install-recommends git
RUN apt-get install python3-pip -y
RUN apt-get install libsndfile1 -y
RUN pip install --upgrade pip
RUN pip3 --no-cache-dir install \
    Pillow \
    h5py \
    keras_preprocessing \
    matplotlib \
    mock \
    numpy \
    scipy \
    sklearn \
    pandas \
    future \
    portpicker\
    librosa\
    numba==0.48.0\
    notebook
    # Add Tini. Tini operates as a process subreaper for jupyter. This prevents
# kernel crashes.
EXPOSE  6666
ENV TINI_VERSION v0.18.0
ADD https://github.com/krallin/tini/releases/download/${TINI_VERSION}/tini /usr/bin/tini
RUN chmod +x /usr/bin/tini
ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["bash", "-c", "source /etc/bash.bashrc && jupyter notebook --notebook-dir=/tf --ip 0.0.0.0  --allow-root"]

