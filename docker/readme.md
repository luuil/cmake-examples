## Docker

Docker allows you to package software in a container which contains a filesystem with all dependencies. This allows having containers which include everything needed to run and test our examples. And as a result of packaging all dependencies we can create containers to include different versions of cmake so that it is possible to easily make sure our examples work for many cmake versions.

## Build a docker image

To build a image from the this directory run the following:

```bash
sudo docker build --rm -f <Dockerfile> -t <container tag> .
```

for example:

```bash
sudo docker build --rm -f Dockerfile-ubuntu16.04-cmake3.10.3 -t luuil/cmake-examples:16.4-3.10
```

Where the tag is:

```
<docker user id>/<repository>:<ubuntu version>-<cmake version>
```

## Run a docker container with volume mount

Run a docker container to test all projects in this repo:

```
sudo docker run -it -v /home/luuil/cmake-examples:/cmake-examples luuil/cmake-examples:16.4-3.10
git clone https://github.com/luuil/cmake-examples.git
cd cmake-examples
```

Where `-v /home/luuil/cmake-examples:/cmake-examples` means map the local location `/home/luuil/cmake-examples` into container's location `/cmake-examples`.

## Exit container

If you have done testing, and want to exit, type:

```bash
exit
```

## Reuse the last container

Every time we run the command

```
sudo docker run -it luuil/cmake-examples:16.4-3.10
```

will create a new container. If you want to reuse the last container, doing this:

```
sudo docker ps -a # this command will show containers info, we use the <CONTAINER ID>
sudo docker start <previous CONTAINER ID>
sudo docker exec -it <previous CONTAINER ID> /bin/bash
```