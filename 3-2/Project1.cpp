#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///////////////////////////////////////////////////////////////////////////////////////////
char * intToRoman(int num)
{
	
	int i=0,digits=0,tens=0,hundreds=0,thousands=0,len=0,charlen=1;
	
	thousands = num / 1000;
	hundreds = (num / 100 ) % 10;
	tens =  (num / 10 ) % 10;
	digits = (num % 10);
	
	if(thousands != 0)
		len = 5;
	else if(hundreds != 0)
		len = 4;
	else if(tens != 0)
		len = 3;
	else
		len = 2;
	
	char ha[25];
	memset(ha, '\0', 25);
	//printf("%d %d %d %d %d\n",thousands,hundreds,tens,digits,len);
///////////////////////////////////////////////////////////////////////////////////////////
	if(len == 5)
	{
		for(i=0;i<thousands;i++)
		{
			strcat(ha,"M");
			charlen++;
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////
	if(len >= 4)
	{
		if(hundreds == 9)
		{
			strcat(ha,"CM");
			charlen = charlen+2;
		}
		else if(hundreds == 8 || hundreds == 7 || hundreds == 6)
		{
			strcat(ha,"D");
			for(i=0;i<(hundreds-5);i++)
			{
				strcat(ha,"C");
				charlen++;
			}
			charlen++;
		}
		else if(hundreds == 5)
		{ 
			strcat(ha,"D");
			charlen++;
		} 
		else if(hundreds == 4)
		{ 
			strcat(ha,"CD");
			charlen  = charlen+2;
		} 
		else// if(hundreds == 3 || hundreds == 2 || hundreds == 1)
		{
			for(i=0;i<hundreds;i++)
			{
				strcat(ha,"C");
				charlen++;
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////	
	if(len >= 3)
	{
		if(tens == 9)
		{ 
			strcat(ha,"XC");
			charlen  = charlen+2;
		} 
		else if(tens == 8 || tens == 7 || tens == 6)
		{
			strcat(ha,"L");
			for(i=0;i<(tens-5);i++)
			{
				strcat(ha,"X");
				charlen++;
			}
			charlen++;
		}
		else if(tens == 5)
		{ 
			strcat(ha,"L");
			charlen++;
		} 
		else if(tens == 4)
		{ 
			strcat(ha,"XL");
			charlen  = charlen+2;
		} 
		else// if(tens == 3 || tens == 2 || tens == 1)
		{
			for(i=0;i<tens;i++)
			{
				strcat(ha,"X");
				charlen++;
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////
	if(digits == 9)
	{ 
		strcat(ha,"IX");
		charlen  = charlen+2;
	}	
	else if(digits == 8 || digits == 7 || digits == 6)
	{
		strcat(ha,"V");
		for(i=0;i<(digits-5);i++)
		{
			strcat(ha,"I");
			charlen++;
		}
		charlen++;
	}
	else if(digits == 5)
	{ 
		strcat(ha,"V");
		charlen++;
	}	
	else if(digits == 4)
	{ 
		strcat(ha,"IV");
		charlen  = charlen+2;
	} 
	else// if(digits == 3 || digits == 2 || digits == 1)
	{
		for(i=0;i<digits;i++)
		{
			strcat(ha,"I");
			charlen++;
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////
	//char ans[charlen];
    char *ans;
    ans = (char*)malloc( charlen * sizeof(char) );
	strcpy(ans,ha);
	
	return ans;
}
/**/
int main() 
{
	int a = 3;
	printf("jojo : %s\n",intToRoman(a));
	return 0;
}


