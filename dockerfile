FROM alpine
COPY bear.py .
COPY bee.py .
COPY main.py .
RUN apk add python3
CMD python3 main.py
