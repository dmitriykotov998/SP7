from socket import *

TIMEOUT = 10
HOST = 'localhost'
PORT = 7777

sock = socket(AF_INET, SOCK_DGRAM)
sock.bind((HOST, PORT))
sock.settimeout(TIMEOUT)

while True:
    try:
        print('Wait data...')

        data, addr = sock.recvfrom(1024)
        data = bytes.decode(data)
        print('Addr:', addr, '\tMess:', data)
        
        data = 'OK'
        sock.sendto(data.encode(), addr)

        select = input("Exit? [y/n]: ")
        if select == 'y':
            break

    except timeout:
        print('Timeout!')
        break

        
  
sock.close()
