#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#define MAX_SIZE 20000
char passage[MAX_SIZE] = {0};
void reserve()
{
	int i, j;
	char temp;
	for(i = 0, j = strlen(passage) - 1;i < j; i++, j--)
	{
		temp = passage[i];
		passage[i] = passage[j];
		passage[j] = temp;	
	}
	
}
int main()
{
	FILE *fp = NULL;
	int len = 0;
	fp = fopen("test.txt", "r");
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	rewind(fp);
	fread(passage, 1, len, fp);
	fclose(fp);
	reserve();
	fp = fopen("test.txt", "wb");
	fwrite(passage, 1, strlen(passage), fp);
	fclose(fp);
	return 0;
}
