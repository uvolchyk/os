echo Выберите операцию\:
echo 1. Найти количество файлов и каталогов в текущем расположении
echo 2. Вывести 10 подряд идущих строк в данном файле
echo 3. Список всех процессов, принадлежащих пользователю
read n

case $n in
	1) 	
		echo Количество файлов\:
		find . -type f | wc -l
		echo Количество папок\:
		d= find . -type d | wc -l
		;;
	2)
		echo Введите имя файла:
		read file
		cat $file | sed -n 1,10p
		;;
	3) 
		ps -u
		;;
	*) 
		echo Не знаю такого пункта
	;;
esac