#! /bin/bash

#Name : Ding Ma
#ID: 260871301

projectName=$1 #first arg is the project name
projectOwner=$2 #second arg is the project owner
numberofArgument=$# #gets the number of argument when running the scripts
subdirList=("archive backup docs assets database source") #list of subdirectories that has to be created
folderName="Projects" # if ever the project folder name is changed, easier to deal with later

#checks the number of cmd argumts
if [ 2 -ne "$numberofArgument" ]; then
	echo "Error: Wrong number of arguments. Please type ./mkproj ARGUMENT OWNER. The argument is the name of the project. The OWNER is the user name the project belongs to."
else
	#if it only has 2, do the making of project
	if [ ! -d "$folderName" ]; then
	mkdir "$folderName"
	fi
	
	cd "$folderName"
	
	# if the projectName does not exist, create it and create the sub folders, else terminate script
	if [ ! -d $projectName ]; then
		mkdir "$projectName"
		
		cd "$projectName"
		
		# creates all the subdirectories with a loop
		for subdir in $subdirList; do
			mkdir "$subdir"
		done
		
		echo $(eval ls) # step 8, displays the list of directories
		
		# creates a file with the name of the owner as content
		echo "Created by: $projectOwner " > docs/readme.txt
		
	# if the projectName does exist, error
	else
		echo "Error: The project name has already been used. Please select another project name and try again."
	fi
	
fi
