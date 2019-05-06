#!/bin/bash
echo "Введите систему, из которой переводим (2,8,10,16) : "
read inp
echo "Введите систему, в которую переводим (2,8,10,16) : "
read out
echo "Введите число, которое обрабатываем: "
read num
echo -n "Результат: "
echo "obase=$out;ibase=$inp;$num" | bc -l

