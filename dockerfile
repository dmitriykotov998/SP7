FROM alpine
COPY sp3.cpp .
RUN apk add gcc
RUN apk add g++
RUN g++ sp3.cpp -static
CMD ./a.out
