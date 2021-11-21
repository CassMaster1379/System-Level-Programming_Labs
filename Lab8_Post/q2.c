#include <stdio.h>

int main(){
 
	int letters;
	int words;
	char character;

	printf("Enter a Sentence: ");

	while((character=getchar()) != '\n'){
		 if(character != ' '){
			letters++;
		}
		else
			words++;
	}

  	printf("Average word length : %.1f", (float)letters/(float)words);

	return 0;
}
