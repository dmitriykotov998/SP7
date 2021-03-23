#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
	    char buff[100]; // Буфер
        int Sot, BeeHoney = 10; // Переменная хранения и переменная в которой пчела складывает мёд

        ifstream file; // Переменные для вывода и записи
        ofstream file1;

        file.open("honey.txt"); // Открыли
        file >> buff; // Считали и записали в буфер
        file.close(); // Закрыли

        Sot = atoi(buff);// Перевели в int и приравняли значение буфера к Sot
        Sot += BeeHoney;// Увеличиваем перменную хранения на переменную складывания мёда
        sprintf(buff, "%d", Sot); // Записали в буффер

        cout << "Honey: " << Sot << endl; // Вывели

        file1.open("honey.txt"); // Открыли
        file1 << buff; // Записали с буффера в файл
        file1.close();// Закрыли

        sleep(1); // Спим 1 секунду
}
