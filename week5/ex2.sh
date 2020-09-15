#kindly ask the reference below for some materials! 
#https://unix.stackexchange.com/questions/309010/how-to-do-locking-a-file-from-a-shell-script
COUNTER_FILE="ex2.txt"
tempfile=$(mktemp ./lock.XXXX)
lockfile=./lockfile
if  ln "$tempfile" $lockfile  ; then
    count=$( tail -n 1 ex2.txt )
	((count++))
	echo "$count" >> $COUNTER_FILE
    rm $lockfile
else 
    echo 1
fi
rm "$tempfile"