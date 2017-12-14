# Build command:
# docker build -t moriorgames/cpp14 .
FROM ubuntu:17.10
MAINTAINER MoriorGames "moriorgames@gmail.com"

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y software-properties-common wget make git curl vim
RUN apt-get install -y gcc
RUN apt-get install -y cmake
RUN apt-get install -y build-essential

# Create Application directory
RUN mkdir -p /app
COPY . /app
WORKDIR /app

RUN cmake .
RUN make
