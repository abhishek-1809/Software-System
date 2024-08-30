/*
============================================================================
Name : 7.c
Author : Abhishek Sahu
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 22th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

int main(){

	FILE *fptr1,*fptr2;
	int c;

	fptr1 = fopen("f1.txt","r");

	fptr2 = fopen("f2.txt","w");
	while((c = fgetc(fptr1)) != EOF){
		fputc(c,fptr2);
	}
	
	printf("File copied successfully.")

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}
/*
Output:
File copied successfully.
*/