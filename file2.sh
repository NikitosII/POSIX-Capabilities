#!/bin/bash

# Компиляция программы
gcc -o file2 file2.c -lcap
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции"
    exit 1
fi

# Проверка работы 
echo "Запуск file2 для управления возможностями file1:"
sudo ./file2 ./file1 cap_dac_override=+eip
if [ $? -ne 0 ]; then
    echo "Ошибка выполнения"
    exit 1
fi

