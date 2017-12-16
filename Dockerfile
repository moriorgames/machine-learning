# Build command:
# docker build -t moriorgames/ml .
FROM ubuntu:17.10
MAINTAINER MoriorGames "moriorgames@gmail.com"

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y software-properties-common wget make git curl vim
RUN apt-get install -y gcc
RUN apt-get install -y cmake
RUN apt-get install -y build-essential

# Install some C++ libraries needed for the project
RUN apt-get install -y liblapack-dev
RUN apt-get install -y libblas-dev
RUN apt-get install -y libboost-all-dev
RUN apt-get install -y libarmadillo-dev

# Create Application directory
RUN mkdir -p /app
COPY . /app
WORKDIR /app

RUN cmake .
RUN make
