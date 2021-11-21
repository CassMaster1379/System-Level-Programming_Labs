#!/bin/bash
# Name of Programmer: Cassandra Lundberg  Email of Programmer: clundberg3@student.gsu.edu
#Title: numberstatements.sh
# This shell script is designed to search for the number of statements in the file "myexamfile.txt" and display the number as well as
# find the number of words and letters of each statement in the file.

wiki="myexamfile.txt" #assigned the file to a variable named "wiki"

echo "The number of sentences separeated by a (.) is: " #prompt

sentence="$(grep -oc ^\..*\.$ $wiki)" #the variable sentence is the searched number of sentences in the file by finding any number of
			              #characters in between two periods
echo "$sentence"  #outputs the number of sentences in the file
echo " "

actual_sentence="$(grep ^\..*\.$  $wiki)" #variable "actual_sentence" finds the all the statements where characters are in between two
					  #periods.

for x  in $actual_sentence  #for every statement in the list of statements, do
do
	echo "The number of letters are: "
	echo $x | wc -c #print the number of character for every statement

	echo "The number of words are: "
	echo $x | wc -w #print the number of words for every statement
done
