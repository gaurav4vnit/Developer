FROM gcc:latest

COPY . /var/tmp/docker1

WORKDIR /var/tmp/docker1

RUN g++ -std=c++20 -o test main.cpp

CMD ["./test"]
