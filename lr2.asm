section .data
    summsg db 'Sum:' ; Строка Sum
    summsg_len equ $-summsg ; Размер строки

    nextline db 10 ; Переход на новую строку

    mas dw 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ; Массив
    mas_len equ 1 ; Длина массива 

    sum dw 0 ; Сумма элементов

; Макрос с двумя параметрами, который реализует системный вызов sys_write
%macro print 2 ; Макрос - выводит на экран данные которые передаёт в качестве аргумента 
    mov eax, 4  
    mov ebx, 1 
    mov ecx, %1 
    mov edx, %2
    int 80h ;
%endmacro

section .text ; сегмент кода
global _start ; метка старт

_start:

    mov esi, mas ; Первый элемент массива
    mov ecx, mas_len ; Кол-во элементов массива

    xor eax, eax ; Обнуление переменных для вычисления
    xor ebx, ebx 
    

top:
    add eax, [esi] ; Прибавляем к регистру первое значение массива
    or al, 00001000b ; Операция И, если в 4м бите 0, то будет 1
    add ebx, eax ; Суммируем наш обнулённый регистр
    xor eax, eax ; Снова обнуляем
    

    add esi, 2 ; Переход к следующему элементу с прибавлением 2 байта
    dec ecx ; Уменьшаем счётчик переменных
    
    jnz top ; Проверяем, есть ли в счетчике значение отличное от 0, если да, то к метке топ
    
    ;Вывод
    
    add ebx, '0' ; Преобразование в ASCII
    mov [sum], ebx ; Записываем в переменную Sum
    
    


    print summsg, summsg_len ; Печатаем сообщение
    print sum, 1 ; Выводим сумму

    print nextline, 1 ; Новая строка
;Выход
exit:
    mov eax, 01 
    mov ebx, 0 
    int 80h 