/* Programmer Name: Cassandra Lundberg  Date: 10/28/21
 * Title: splitTime.c
 * This program takes a users input in a numberial value then splits the number
 * into hours, minutes, and seconds */

#include <stdio.h>

void split_time(long, int *, int *, int *);

int main(){
	int n, hr, min, sec;
	printf("Enter seconds: ");
	scanf("%d", &n);
	split_time(n, &hr, &min, &sec);
	
	printf("Converted format: %d hour %d min %d secs\n", hr, min, sec);
	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec){
	*hr = total_sec / 3600;
	*min = (total_sec -(*hr * 3600)) / 60;
	*sec = (total_sec - (*hr * 3600))- (*min * 60);
}	
