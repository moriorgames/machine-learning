Machine Learning in C++
=======================

This repository is intended to be a Machine Learning written in C++ for I+D purposes.
The aim is be able to create a Machine Learning full performance, create a docker image from this code and deploy it into a production server easily.

As a single developer I'm not an expert about this topic, my goal is to share this project with the community and be able to improve the repository to have a full featured Machine Learning in C++.

Do not hesitate to email me at *moriorgames@gmail.com* if there is any issue with the project. 

## Installation

Create a docker container, install all dependencies and build the project with cmake.
This will give us an image with the compiled application ready to *run* and *test*.

* To create the docker image
```
$ docker build -t moriorgames/ml .
```

* Run the container
```
$ docker run -td --name machine_learn moriorgames/ml
```

* Execute the program
```
$ docker exec -ti machine_learn ./main
```

* Execute the Tests
```
$ docker exec -ti machine_learn ./tests/testsuite
```

## Docker Images

I like to preserve information about tagging and pushing images to docker

* First login at dockerhub
```
$ docker login
username
password
```

* Tag an existing image
```
$ docker tag moriorgames/ml moriorgames/ml:commit_sha
```

* Push the image to the public repository
```
$ docker push moriorgames/ml:commit_sha
$ docker push moriorgames/ml:latest
```
