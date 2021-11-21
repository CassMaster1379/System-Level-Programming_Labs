//Name: Cassandra Lundberg   Date: 11/08/21
//Title: checkPasswd.c
//This program checks the length of a given password by input. Then the length
//is compared to 10 or not. For every missing character 5 points will be
//deducted. If the total deduction is greater than 30 then prompt for new
//password


#include <stdio.h>
#include <string.h> //call string class
#define PASS_LEN 10 //define a constant  variable for required password length

main(){ //main method
	char password[PASS_LEN+1]; //create array of characters called password
	
 	//prompt for entering password
	printf("Please enter a password 10 characters long: ");
	//scan input password 
	scanf("%s", password);
 
	//find length of the string password
	int len = strlen(password);	
	
	//while the length of the password is less than 10
	while(len < PASS_LEN){
			//create variable n to count number of missing characters
			int n = PASS_LEN - len;
			//create variable point_deduct
			int point_deduct = 0;

			//deduction of points is the missing characters times 5
			point_deduct = n * 5;
			//the total final score of points is 100 minus the points deducted
			int total_point = 100 - point_deduct;

			//if the points lost are greater than 30
			if(point_deduct > 30){
				//print the points deducted, total points, and prompt
				//to reset the password
				printf("%d points were deducted\n", point_deduct);
				printf("%d total points remain\n", total_point);
				printf("The password is unsafe! Please reset.\n");
			}
			else{//otherwise the points deducted are not greater than 30
				//print the points deducted and the total points
				printf("%d points were deducted.\n", point_deduct);
				printf("%d total points remain\n", total_point);
			}
			
			//prompt to enter another password
			printf("Please enter a password 10 characters long: ");
			scanf("%s", password);
			len = strlen(password);
		
	}
	//if the length of the password entered is equal to the required length of 10
	if(len >= PASS_LEN ){
		//then print the password is safe
		printf("The password is safe.\n");
	}	
	//exit the main method	
	return 0;
}
