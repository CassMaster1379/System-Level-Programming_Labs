#!/bin/bash
# Name of Programmer: Cassandra Lundberg  Email of Programmer: clundberg3@student.gsu.edu
# Title: calculator.sh
# This shell script asks a user for two numbers and an operator and performs operations on the two numbers based on the specified
#operation.

operation_prompt(){ #operation prompt method to ask user which operation to use
	echo " "
	echo "Which operation would you like to perform?" #prompt for operation
	echo "Please enter an operation:"
	echo "Addition (+)"
	echo "Subtraction (-)"
	echo "Multiplication (*)"
	echo "Division (/)"
	echo "Modulo (%)"
	echo "Enter exit anytime to exit!"
	echo "Enter clear to clear entrys | Enter cancel to reenter entry"
	echo " "
	read operation #reads the users input for an operation

	if [ "$operation" = "exit" ] #if the user's input is exit then the program exists the calulator shell script
	then
		exit
	elif [ "$operation" = "clear" ] #if the user's input is clear then the program returns to the beginning of the prompt
	then
		operation_prompt
	elif [ "$operation" = "cancel" ] #if the user's input is cancel then the program returns to the beginning of the entry
	then
		operation_prompt
	else #otherwise the prompt continues to the number1 prompt method
		number1_prompt
	fi
}
number1_prompt(){ #the number1 prompt gets the first number from the user's input		
	echo "Please enter the first number: "
	echo " "
	read number1  #get user's input
	echo "You entered: " "$number1" #tells the user what they entered

	if [ "$number1" = "exit" ] #if the value of number1 is exit then the program exits
	then
		exit
	elif [ "$number1" = "clear" ] #if the value of number1 is clear then the program starts from the beginning of operation prompt
	then
		operation_prompt
	elif [ "$number1" = "cancel" ] #if the value of number1 is cancel then the method number1 prompt begins again
	then
		number1_prompt
	else #otherwise continue to method number2 prompt
		number2_prompt
	fi
}
number2_prompt(){ #the number2 prompt method gets the second number from the user's input
	echo "Please enter the second number: "
	echo " "
	read number2 #get the user's input
	echo "You entered: " "$number2" #repeat the user's entry
 
	if [ "$number2" = "exit" ] #if the value if number2 is exit then the program exits
	then
		exit
	elif [ "$number2" = "clear" ] #if the value of number2 is clear then the program starts from the beggining of operation prompt
	then
		operatin_prompt
	elif [ "$number2" = "cancel" ] #if the value of number2 is cancel then the method number2 prompt begins again
	then
		number2_prompt
	fi
}
echo " "
echo "Welcome to Cassie's Calculator!!" #beginning text for flare
echo "********************************"
operation_prompt #calls on operation prompt

while [ "$operation" != "exit" ] #while the operation entered from user is not exit then perform the following
do

	if [ "$operation" = "+" ] #if the operation entered is "+"
	then
		add=`echo $number1 + $number2 | bc` #output the value of number1 + number2 to the input of the basic calculator command
		echo " "
		echo "$number1 + $number2 = $add" #print the expression and the result
		operation_prompt  #jump to operation prompt method
	elif [ "$operation" = "-" ] #if the operation the user entered is "-"
	then
		sub=`echo $number1 - $number2 | bc` #output the value of number1 - number2 to the input of basic calculator command
		echo " "
		echo "$number1 - $number2 = $sub" #output the string expresion and result in sub variable
		operation_prompt #jump to operation prompt method
	elif [ "$operation" = "*" ] #if the operation the user entered is "*"
	then
		mul=`echo $number1 \* $number2 | bc` #output the value of number1 * number2 to the input of basic calculator command
		echo " "
		echo "$number1 * $number2 = $mul" #output the string expression along with result of variable mul
		operation_prompt #returnt to operation prompt method
	elif [ "$operation" = "/" ] #if the operation the user entered is a "/"
	then
		div=`echo $((number1 / number2)) | bc` #the expression number1 / number2 must be a variable before outputting to basic
						       #calculator command
		echo " "
		echo "$number1 / $number2 = $div" #output the string expression along with the result of variable div
		operation_prompt #return to operation promot method
	elif [ "$operation" = "%" ] #if the operation entered by the user is "%"
	then
		mod=`echo $number1 % $number2 | bc` #output the value of number1 % number2 into the input of basic calculator command
		echo " "
		echo "$number1 % $number2 = $mod" #output the string expression and result variable mod
		operation_prompt #return to the operarion prompt method
	else #otherwise the operation is invalid
		echo " "
		echo "Operation Invalid"
		operation_prompt #return to the operation prompt method
	fi
done #close while loop
exit #exit program




