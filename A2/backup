#! /bin/bash

#Name : Ding Ma
#ID: 260871301


containsDash="^-"
argumentsIn=$@
argslist=($argumentsIn)
workingdir=$(pwd)
lengthArguments=$# # gets number of cmd arguments
bkDate="$(date +'%Y%m%d')"
if [[ $argumentsIn =~ $containsDash ]]; then

#check if inputs are ok
	if [ $lengthArguments -le 3 ] || [ $1 != "-D" ]; then
		echo "You have the incorrect number of arguments. The correct syntax is: ./backup SWITCH FILES DEST MESSAGE. Please try again."
		exit 0
	fi
	
	dirtoBk=${argslist[1]}
	pathout=${argslist[2]}
	text=${argslist[@]:3:$lengthArguments}
	# check if directory exists, if not create it
	if [ ! -d "$pathout" ]; then
		mkdir "$pathout"
	fi

	# changes dir to the files dir and back up all the files in there
	cd "$dirtoBk"
	tar -cf $pathout/backup$bkDate.tar *
	# removes all files in current directory
	rm -f ./* 
	cd "$workingdir"
	#makes it only into RW for owner
	chmod 600 $pathout/backup$bkDate.tar  
	
	# appends msg to logs
	echo $text $bkDate >> $pathout/backups.log
	
	
else

	if [ $lengthArguments -le 2 ]; then
		echo "You have the incorrect number of arguments. The correct syntax is: ./backup SWITCH FILES DEST MESSAGE. Please try again."
		exit 0
	fi
	
	#what is different from this one is the simple index change
	dirtoBk=${argslist[0]}
	pathout=${argslist[1]}
	text=${argslist[@]:2:$lengthArguments}
	
	if [ ! -d "$pathout" ]; then
		mkdir "$pathout"
	fi
	
	# changes dir to the files dir and back up all the files in there
	cd "$dirtoBk"
	tar -cf $pathout/backup$bkDate.tar *
	cd "$workingdir"
	chmod 600 $pathout/backup$bkDate.tar  
	
	# appends msg to logs
	echo $text $bkDate >> $pathout/backups.log
	
	
fi