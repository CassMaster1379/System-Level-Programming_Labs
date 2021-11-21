//Name: Cassandra Lundberg  Date: 11/05/21
//Title: strcpy.c
//This program creates a prototype strcpy where the source string is copied
//into the destination string via char* as the return value


#include <stdio.h>

char *strcpy(char *strDest, const char *strSrc){

	//create pointer p and assign to the pointer strDest
	char *p = strDest;	
	
	//while the pointer strScr pointing to the string does not reach the end of the string, or the
	//end of the array of characters  
	while(*strSrc != '\0'){
		//the p pointer position is equal to the position of the strSrc
		*p = *strSrc;
		//increment the position of the p pointer
		p++;
		//incremeent the position of the strSrc pointer
		strSrc++;
	}
	//set the p pointer to the end of the array of characters or string
	*p = '\0';
	//return the strDest variable
	return strDest;
}

main(){
	//the source string which is to be copied
	char str1[4] = "abc"; 
	//the destination string which will contain the copied string
	char str2[4];

	//call the strcpy method, where str1 is copied into str2
	strcpy(str2, str1);
	//the string str2 is printed
	puts(str2);
	//exit main function
	return 0 ;
}

