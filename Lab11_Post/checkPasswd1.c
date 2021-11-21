//Name: Cassandra Lundberg   Date: 11/08/21
//Title: checkPasswd1.c
//This program checks the length of a given password by input. Then the length
//is compared to 10 or not. For every missing character 5 points will be
//deducted. If the total deduction is greater than 30 then prompt for new
//password. This program also checks for missing lower case letters, lack of capital 
//letters, missing numbers, and more than 2 consecutive characters.


#include <stdio.h> //include standard input function
#include <string.h> //include string function liabrary
#include <ctype.h> //include liabrary for testing characters
#include <stdlib.h> //include standard liabrary
#define PASS_LEN 10 //define constant variable called PASS_LEN 

//function to check for uppercase and lowercase characters, digits, and consecuative characters with
//input parameters of the input string and the int variable of the points deducted so far
int password_safety(char password[], int point_deduct){ 
	//create variable i for indexing and variables found_digit, found_upper, and found_lower
	//to flag when found
	int i;
	int found_digit = 0;
	int found_upper = 0;
	int found_lower = 0;
	//for the entire string when an element is not a null character(when the string has not
	//ended)
	for(i = 0; password[i] != '\0'; i++){
		//if an element is a digit then flag the found_digit variable
		if(isdigit(password[i])){
			found_digit = 1;
		}
		//if an element is an uppercase character then flag the found_upper variable
		if(isupper(password[i])){
			found_upper = 1;
		}
		//if an element is a lowercase character then flag then found_lower variable
		if(islower(password[i])){
			found_lower = 1;
		}
	}
	//for every element in the string
	for(i = 0; password[i] != '\0'; i++){
		//if a character is equal to the next character then
		if(password[i] == password[i+1]){
			//add 20 points to the point_deduct variable
			point_deduct = point_deduct + 20;
			//and break out of the loop
			break;
		}
	}
	//create variable total to hold the total number of flags not found
	//all the flags are added together and subtracted from 3
	//if a flag is not true then 20 points is added to the variable point_deduct 
	//for every flag that is not true add 20 points to the variable
	int total = 3 - (found_digit + found_upper + found_lower);
	point_deduct = point_deduct + (20 * total);	
	//return the variable point_deduct with the total number of points to be deducted
	return point_deduct;
}
int main(){ //main function

	//create variables deduct, total_deduct, and final to indicate the number of points deducted
	//and final points remaining
	int deduct = 0;
	int total_deduct = 0;
	int final = 0;
	
	//while the final points remaining is not 100 then continue prompting for a password reset
	while(final != 100){
		
		//create string password to hold 20 characters 
		char password[20];
	
		//prompt the user to input a password
		printf("Please enter a password 10 characters long: ");
		//scan input and store in the array of characters called password
		scanf("%s", password);

		//create len to find the length of the string
		int len = strlen(password);
	
		//if the length of the string is less than 10 
		if(len < PASS_LEN ){
			//ensure the final points remaining is 0 when prompt resets
			final = 0;
				//create variable missing to calculate the absolute value
				//of mssing characters
				int missing = abs(PASS_LEN - len);

				//the variable deduct the number of missing characters times 5
				deduct = missing * 5;
				//the total deduct is the return int value of the method
				//password_safety when the string and current points deducted are
				//input as arguments
				total_deduct = password_safety(password, deduct);

				//final is the total points deducted subtracted from 100
				final = 100 - total_deduct;

				//if the total points deducted is less than 30
				if(total_deduct > 30){
					//then print to the user the passweord is not safe
					printf("The password is unsafe! Please reset\n");
				}
				//tell user the points deducted and the final remaining points
				printf("%d points were deducted.\n", total_deduct);
				printf("%d total points remain.\n", final);
		}
		else{ //otherwise the length of the string is greater than or equal to 10

			//the total points deducted current is 0 
			total_deduct = 0;
			//the total points deducted is now the return in value of the method
			//password_safety with input arguments the input string and 0
			total_deduct = password_safety(password, 0); 

			//the final points remaining are the total points deducted subtracted from
			//100
			final = 100 - total_deduct;
			//the points deducted and final points remaining are printed
			printf("%d points were deducted.\n", total_deduct);
			printf("%d total points remain.\n", final);

			//if the total points deducted is greater than 30
			if(total_deduct > 30){
				//than tell the user that the password is unsafe
				printf("The password is unsafe! Please reset\n");
			}
		}
	}
	//otherwise no points are deducted and the final points remaining are 0
	//the password is safe
	printf("The password is safe.\n");
	
	//exit the main method
	return 0;
}
