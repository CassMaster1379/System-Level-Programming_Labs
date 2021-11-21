#!/bin/bash  
# Name of Programmer: Cassandra Lundberg  Email of Programmer: clundberg3@student.gsu.edu 
#Title: helpme.sh
#Prints the manual page of any command a user inputs

echo " "
echo "Please type a command: "  #prompt for command
echo " "
read entry  #user input an entry

database="mandatabase.txt"  #assign the mandatabase.txt to a variable called database

entry=$(echo "$entry" | tr a-z A-Z) #the value of variable entry is changed to all uppercase characters 


if [ -n "$(sed -n "/^$entry(1)/,/$entry(1)$/p" "$database" | more)" ] #if the user's input begins with a command listed in the database
                                                                      
then
	sed -n "/^$entry(1)/,/$entry(1)$/p" "$database" | more # then print the database where the input matches a line with the
							       # command followed by (1), then supress the rest of the database
else
	echo " "
	echo "sorry, I cannot help you." #otherwise print to user prompt
fi
