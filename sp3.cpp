#include <iostream>
#include <random>
#include <ctime>

using namespace std;

extern "C" {

        const int razmer = 10; //Указываем количество строк и столбцов
        int tempRazmer = razmer; // Для ASM кода

        int newArray[razmer];    // Массив для ASM кода

        int array[razmer][razmer]; //Двумерный массив
};

int main()
{
        srand(time(0));

        for (int i = 0; i < razmer; ++i)
        {
                for (int j = 0; j < razmer; ++j)
                {
                        array[i][j] = 0 + rand() % 1000; //Генерация случайных чисел до 1000
                }
        }

        cout << "Matrix:" << endl; //Вывод массива
		for (int i = 0; i < razmer; i++)
		{
			for (int j = 0; j < razmer; j++)
			{
			cout << array[i][j] << " ";
			}
			cout << endl;
		}

        //Код на ассемблере
        __asm
        (
        R"(
                .intel_syntax noprefix ; //используем синтаксис intel
                ;//{
                mov esi, 0                              ; //Регистр где храним адрес элементов одномерного массива
                mov ecx, 0                              ; //Регистр где указываем адрес элементов двумерного массива
                mov dl, 0                               ; //Регистр где считаем количество пройденных строк

                        Start:
                mov dh, 0                               ; //Регистр где считаем количество пройденных элементов массива
                mov ebx, 1001               ; //Хранение минимального элемента

                        Main:
                mov eax, array[ecx]         ; //Место для проверяемого элемента
                cmp eax, ebx                ; // Сравнение проверяемого с минимальным на данный момент
                jl Min                      ; // Если меньше, то в метку Min

                jmp Inc                     ; // Переход к метке

                        Min:
                mov ebx, eax                ; // Кладём текущее минимальное значение

                        Inc:
                add ecx, 4                  ; // Переход к следующему элементу
                add dh, 1                   ; // Увеличиваем значение dh
                
						Check:
                cmp dh, BYTE PTR tempRazmer ; // Если есть строки, то к метке Main
                jl Main

                mov newArray[esi], ebx      ; // Заносим новое значение в созданный массив
                add esi, 4                  ; // Переход к другому элементу массива

                        CheckEnd:
                add dl, 1                   ; // Увеличиваем количество пройденых строк
                cmp dl, BYTE PTR tempRazmer ; // Сравнение, есть ли ещё строки
                jl Start                    ; // Если есть, то к метке старт
        ;//}
        .att_syntax
        )"
        );

        //Вывод минимальных элементов массива
        cout << "Minimum elements in a matrix:" << endl;
        for (int i = 0; i < razmer; i++)
        {
                cout << newArray[i] << " ";
        }
        cout << endl;

        return 0;
}	
            
