#include <iostream>
#include <sys/wait.h>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
        char buff[100]; // Буфер
        int Sot, SotSteal = 30; //Переменная хранения и переменная сколько ворует медведь

        ifstream file; //Переменные для вывода и записи
        ofstream file1;

        pid_t bear; //Определяем идентификатор процесса
        bear = fork(); //Порождаем процесс
        //Бесконечный цикл
        for(;;) {
                file.open("honey.txt");// Открыли
                file >> buff; // Считали с файла и записали в буфер
                file.close(); // Закрыли
                Sot=atoi(buff); // Перевели в int и приравняли значение буфера к Sot
                // Если процесс запущен и значение Sot больше или равно 30
                if(!bear && Sot>=30) {
                        Sot-=SotSteal; // Минусуем от нашей переменной значение которое ворует медведь

                        cout << "ID Bear: " << getpid() << endl; // Вывели id процесса
                        cout << "Bear steal sot: " << Sot << endl << endl; // Вывели значение после воровства
                        sprintf(buff, "%d", Sot); // Записали в буффер

                        file1.open("honey.txt"); // Открыли
                        file1 << buff; // Записали с буффера в файл
                        file1.close(); // Закрыли

                        sleep(4); // Спим 4 секунды
                }
                
                if (Sot<30)
                {
                	cout << "Honey empty" << endl; 
                	return 0;
				}

                pid_t bee; // Идентификатор процесса
                bee = fork(); // Породили процесс пчелы
                wait(0); // С ним цикл работает не слишком быстро
                // Если процесс запущен
                if(!bee) {
                        cout << "ID Bee: " << getpid() << endl; // Вывели id процесса
                        execl ("bee", "NULL" , NULL, NULL); // Вызываем первую программу
                        kill(getpid(), SIGKILL); // Немедленно убили процесс
                }
        }
        return 0;
}


