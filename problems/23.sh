<<<<<<< HEAD
znak=$( bc <<< "n^($1-1)%$1" )
 if [ $znak = 1 ];
  then echo "Chislo $1 prostoe";
   else echo "Chislo $1 sostavnoe";
 fi
=======
n<< awk { sqrt(4) }
echo $n
>>>>>>> 6f273149a531b7bf7c5f60f52699a8d7ec36fc99
