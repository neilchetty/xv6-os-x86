FROM --platform=linux/amd64 ubuntu:latest
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y nano vim make qemu-system-x86 git micro gcc
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
WORKDIR /home/ubuntu
CMD ["/bin/bash"]