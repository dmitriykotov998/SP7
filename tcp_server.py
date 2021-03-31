from socket import *

HOST = 'localhost'
PORT = 7777
# время ожидания запроса
TIMEOUT = 60    

# создание сокета TCP
sock = socket(AF_INET, SOCK_STREAM)     
# установка времени ожидания
sock.settimeout(TIMEOUT)
# связать адрес и порт с сокетом
sock.bind((HOST, PORT))
# установить максимальное кол-во соединений
sock.listen(5)

while True:
    try:
        print('Wait data...')
        # устанавливает соединение
        conn, addr = sock.accept()
        print('Addr connect:', addr)

        # получает сообщение 
        data = conn.recv(1024)
        if not data:
            conn.close()
            break
        else:
            print(data.decode())
            # отправить сообщение
            conn.send(b'Ok')
            conn.close()

        select = input("Exit? [y/n]: ")
        if select == 'y':
            break
    
    # истекло время ожидания
    except timeout:
        print('Timeout!')
        break
  
sock.close()