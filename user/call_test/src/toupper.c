#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#include <sys/types.h>
#include <regex.h>

int isValidMac(char *value)
{
	int r; //r=0:valid, else not valid
	char *reg="^[0-9A-F]\\([0-9A-F]\\:[0-9A-F]\\)\\{5\\}[0-9A-F]$";
	r=ereg(reg,value);
	return r;
}

int isValidIp(char *value)
{
	int r; //r=0:valid, else not valid
	char *reg="^[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}$";
	r=ereg(reg,value);
	return r;
}
 
int ereg(char *pattern, char *value)
{
	int r,cflags=0;
	regmatch_t pm[10];
	const size_t nmatch = 10;
	regex_t reg;
	
	r=regcomp(&reg, pattern, cflags);
	if(r==0)
	{
		r=regexec(&reg, value, nmatch, pm, cflags);
	}
	regfree(&reg);
	
	return r;
} 


