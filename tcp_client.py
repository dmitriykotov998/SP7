from socket import *
import sys

TIMEOUT = 10
HOST = 'localhost'
PORT = 7777
addr = (HOST, PORT)

sock = socket(AF_INET, SOCK_STREAM)
sock.settimeout(TIMEOUT)
sock.connect(addr)

while True:
    try:
        data = input('Enter mess to server: ')
        if not data : 
            sock.close() 
            sys.exit(1)

        data = str.encode(data)
        sock.send(data)

        data = bytes.decode(data)
        data = sock.recv(1024)
        print('Response:', data)

    except timeout:
        print('Timeout!')
        break

    # ошибка подключения
    except ConnectionResetError:
        print('Error connetion to server')

sock.close()