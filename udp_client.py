from socket import *
import sys

TIMEOUT = 60  
HOST = 'localhost'
PORT = 7777
addr = (HOST, PORT)


# создание сокета UDP
sock = socket(AF_INET, SOCK_DGRAM)
sock.settimeout(TIMEOUT)

while True:
    try:
        data = input('Enter mess to server: ')
        if not data : 
            sock.close() 
            sys.exit(1)

        sock.sendto(data.encode(), addr)

        data, addr = sock.recvfrom(1024)
        data = bytes.decode(data)
        print('Response:', data)

    except timeout:
        print('Timeout!')
        break

    except ConnectionResetError:
        print('Error connetion to server')

udp_socket.close()