#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define MAX_SIZE 2000
char words[MAX_SIZE] = {0};
int k = 0;
typedef struct word
{
	string haha;
	int a;
}shouji;
shouji sumwords[MAX_SIZE];

int check(string temp)
{
	int ii;
	for(ii = 0; ii < k; ii++)
	{
		if(sumwords[ii].haha == temp)
		{
			sumwords[ii].a+=1;
			return 1;
		}
	}
	return 0;
}
void counts()
{
	int i, j;
	int flag = 0;
	int ok = 0;
	string str = "";
	int cal = 0;
	for(i = 0; i <= strlen(words); i++)
	{
		if(words[i] != ' ' && words[i] != '\0' && words[i] != ',' &&words[i] != '\n'&&words[i] != '.')
		{
			str += words[i];
			flag = 1;
		}
		else
		{	
			if(flag == 1)
			{	ok = check(str);
				if(ok == 0)
				{
					sumwords[k].haha = str;
					sumwords[k].a++;
					k++;
					flag = 0;
				}
				str = "";
			}
			str = "";	
		}		
	}
}
int main()
{
	int q = 0;
	int len;
	FILE *fp = NULL;
	fp = fopen("test.txt", "r");
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	rewind(fp);
	fread(words, 1, len, fp);
	counts();
	for(q = 0; q < k; q++)
		cout << sumwords[q].haha << "---------" << sumwords[q].a << endl;
	fclose(fp);
	return 0;
}
