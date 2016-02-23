FROM ubuntu
MAINTAINER Julien Karst contact@julienkarst.com

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y libxss1
RUN apt-get install -y libappindicator1
RUN apt-get install -y libindicator7
RUN apt-get install -y wget
RUN apt-get install -y htop
RUN apt-get install -y xterm
RUN apt-get install -y emacs

RUN export uid=1000 gid=1000 && mkdir -p /home/developer && echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
echo "developer:x:${uid}:" >> /etc/group && echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && chmod 0440 /etc/sudoers.d/developer && chown ${uid}:${gid} -R /home/developer

USER developer
ENV HOME /home/developer

VOLUME ["/home/developer/malloc"]
WORKDIR /home/developer/malloc
ADD ./ .
