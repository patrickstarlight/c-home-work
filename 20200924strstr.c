#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char *mystrstr(char *s,char *pat)
{
	char *s1=s;
	char *pat1=pat;
	char *s2;
	while(*s1!='\0')
	{
		s2=s1;
		pat1=pat;
		while(*s2!='\0' && *pat1!='\0' && *s2==*pat1)
		{
			s2++;
			pat1++;
		}
		if(*pat1=='\0')
		{
			return (char *)s1;
		}
		s1++;
	}
	return NULL;
}
 int main(){
 	char str1[20]="abc";
 	char str2[20]="abwsaabcdf3452af";
	char *ret=mystrstr(str2,str1);
	printf("%p\n",str2);
 	printf("%p\n%s",ret,ret);
 	return 0;
 }

