FROM alpine
COPY Bear.cpp .
COPY Bee.cpp .
RUN apk add gcc
RUN apk add g++
RUN g++ Bee.cpp -std=c++11 -o bee
RUN g++ Bear.cpp -std=c++11
CMD ./a.out
