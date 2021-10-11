//If We Were Vampires 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxDegree 100
#define maxType 100

typedef struct Polynomial
{
	int degree;
	float coef[maxDegree];
}polynomial;
/**/
polynomial* inputPolynomial(char*);
int isValid(char*);
int getOperationType(char*);
int inputOperationSymbol(char*);
polynomial* operation(int, polynomial*, polynomial*);
polynomial* addition(polynomial*, polynomial*);
polynomial* subtraction(polynomial*, polynomial*);
polynomial* multiplication(polynomial*, polynomial*);
char* polynomialToString(polynomial*);

int main()
{
	char *a;
    a = (char*)malloc( maxType * sizeof(char) );
 	char *b;
    b = (char*)malloc( maxType * sizeof(char) );   
	char *s;
	s = (char*)malloc( maxType * sizeof(char) );
	int o;
/*	while(1)
	{
		printf("please enter your first polynomial and don't 手殘 : \n");
		gets(a);
		
		if( isValid(a) == -1)
		{
			printf("wtf ! 再手殘就剁掉喔 \n");
		}
		else
			break;
	}
	printf("a is a polynomial haha\n");
	while(1)
	{
		printf("please enter your second polynomial and don't 手殘 : \n");
		gets(b);
		
		if( isValid(b) == -1)
		{
			printf("wtf ! 操你媽找死阿 : \n");
		}
		else
			break;
	}
	while(1)
	{
		printf("please enter symbol and don't 手殘 : \n");
		gets(s);
		o = inputOperationSymbol(s);
		if(o == -1)
		{
			printf("wtf ! how !? how i ask you this piece of shit : \n");
		}
		else
			break;
	}	*/
	
	//polynomialToString( operation( o, inputPolynomial(a), inputPolynomial(b) ) );
	
	system("PAUSE");
	return 0;
}

/**/
polynomial* inputPolynomial(char *s)	//傳入input，做一些處理,也就是多項式A,B。回傳多項式 
{
	int i;
	polynomial *p;
	p = (polynomial*)malloc( maxType * sizeof(polynomial) );
	
	for(i=0;i<strlen(s);i++)
	{
		
			
	}	
	
	return p;
}
int isValid(char *s)	//是否有效的多項式，ENTER是0 
{
	/*vincent
	*1x^5+30X ^   4- 50x ^1+ 1
	* if(p[i]==數字) while 看他下一個484x^  或是+- 略過空格 若沒有 看自己484尾巴 
	*若不是回傳-1 是就呼叫 inputPolynomial
	*/
	int i,check=0,len=strlen(s);	//check : if next symbols after num is x^ check = 1，else if is +- check = 2, it should take turns
	
	//printf("in isValid(), the input string is : %s\n",p);
	if( isdigit(s[0]) && isdigit(s[len-1]) )	//ensure that first word is a number and the last word is, too(either power or constant)
	{
		return -1;
	}
	else
	{
		//printf("第一個是數字，值為 : %c		最後一個是數字，值為 : %c\n",p[0],p[len-1]);
		for(i=0;i<(len-1);i++)	//?????????????????????????????????
		{
			//printf("第%d個字元，值為 : %c\n",i,p[i]);
			if(isdigit(s[i]))	//遇到數字 
			{
				//printf("遇到數字，值為 : %c\n",p[i]);
				if(check==1)	//the next symbols should be +-
				{
					//printf("the next symbols should be +-  \n");
					while(1)	//找+- 
					{
						i++;
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(isdigit(s[i]))		//meet number don't bird it
							continue;
						else if(s[i]=='+' || s[i]=='-')	//good job! meet + or - 
						{
							//printf("good job! 數字之後是正負號\n"); 
							check = 2;
							//i--;
							break;
						} 
						else if(s[i]=='\0') //meet '\0' cool!
							return 8787;
						else
							return -1;
					}
				}
				else	//the next symbols should be x^
				{
					//printf("the next symbols should be x^  \n");
					while(1)	//找x or X  or '\0'
					{
						i++;
						//printf("p[%d] = %c\n",i,p[i]);
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(isdigit(s[i]))		//meet number don't bird it
							continue;
						else if(s[i]=='X' || s[i]=='x')	//oh ya! meet x or X 
						{
							//printf("oh ya! 數字之後是x\n"); 
							//check = 1;
							//i--;
							break;
						}
						else if(s[i]=='\0') //meet '\0' cool!
							return 8787;
						else
							return -1;
					}
					while(1)	//找^ 
					{
						i++;
						//printf("p[%d] = %c\n",i,p[i]);
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(s[i]=='^')	//oh ya! meet ^ 
						{
							//printf("oh ya! x之後是^\n"); 
							check = 1;
							//i--;
							break;
						} 
						else
							return -1;
					}					
				}
			}
			else
			{
				return -1;
			}
		}	
	}
	/**/
	return 8787;
}
int getOperationType(char *s)	//回傳加法，減法，乘法
{
	int i,symNum=-1;
	
	for(i=0;i<strlen(s);i++)
	{
		if((isspace(s[i]) && s[i]=='\t'))
			continue;
		else if(s[i]=='+')
			symNum = 1;
		else if(s[i]=='-')
			symNum = 2;
		else if(s[i]=='*')
			symNum = 3;
		else
			symNum = -1;					
	}
	
	return symNum;
}
int inputOperationSymbol(char *s)	//輸入三種算法之一，還是要防呆 ,getOperationType
{
	int i,funnyCt=0,symNum;
	
	for(i=0;i<strlen(s);i++)
		if(!(isspace(s[i]) && s[i]!='\t'))
			funnyCt++;
	if(funnyCt==1)
		symNum = getOperationType(s);
	else
		symNum = -1;
	
	return symNum;
}
polynomial* operation(int s, polynomial *a, polynomial *b)	//傳入哪個算法，多項式A,B。回傳答案 
{
	return a;
}
polynomial* addition(polynomial *a, polynomial *b)	//加法 
{
	return a;
}
polynomial* subtraction(polynomial *a, polynomial *b)	//減法 
{
	return a;
}
polynomial* multiplication(polynomial *a, polynomial *b)	//乘法 
{
	return a;
}
char* polynomialToString(polynomial *p)	//得到結果之後，轉成字串，才能印出來 
{
	char *c;
	
	return c;
}

/*




*/


