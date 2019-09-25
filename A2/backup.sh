#! /bin/bash

#Name : Ding Ma
#ID: 260871301


# todo, check if the first argument is also a capitcal D
containsDash="^-"
argumentsIn=$@
argslist=($argumentsIn)
workingdir=$(pwd)
lengthArguments=$# # gets number of cmd arguments
echo $lengthArguments
if [[ $argumentsIn =~ $containsDash ]]; then

#check if inputs are ok
	if [ $lengthArguments -le 3 ] || [ $1 != "-D" ]; then
		echo "You have the incorrect number of arguments. The correct syntax is: ./backup SWITCH FILES DEST MESSAGE. Please try again."
		exit 0
	fi
	
	dirtoBk=${argslist[1]}
	pathout=${argslist[2]}
	text=${argslist[@]:3:$lengthArguments}
	bkDate="$(date +'%Y%m%d')"
	# check if directory exists, if not create it
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
	
	
else

	if [ $lengthArguments -le 2 ]; then
		echo "You have the incorrect number of arguments. The correct syntax is: ./backup SWITCH FILES DEST MESSAGE. Please try again."
		exit 0
	fi

	pathin=${argslist[1]}
	pathout=${argslist[2]}
	text=${argslist[@]:3:$lengthArguments}
	
	
fi