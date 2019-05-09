znak=$( bc <<< "n^($1-1)%$1" )
 if [ $znak = 1 ];
  then echo "Chislo $1 prostoe";
   else echo "Chislo $1 sostavnoe";
 fi
