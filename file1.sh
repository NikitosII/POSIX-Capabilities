#!/bin/bash

# Компиляция программы
gcc -o file1 file1.c
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции "
    exit 1
fi
FILE="/root/file.txt"
if [ ! -f "$FILE" ]; then
    sudo touch "$FILE"
fi

# Проверка работы без привилегий
echo "Запуск без привилегий:"
./file1

# Установка возможностей
sudo setcap cap_dac_override=+eip file1
if [ $? -ne 0 ]; then
    echo "Ошибка установки возможностей "
    exit 1
fi

# Проверка работы с привилегиями
echo "Запуск с привилегиями:"
./file1

# Просмотр возможностей
echo "Возможности file1:"
getcap file1

