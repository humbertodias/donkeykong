FROM ubuntu
RUN apt update -y && \
    apt install -y libsdl1.2-compat-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev \
    make build-essential