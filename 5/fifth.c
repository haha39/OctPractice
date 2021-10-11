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
		printf("please enter your first polynomial and don't ��� : \n");
		gets(a);
		
		if( isValid(a) == -1)
		{
			printf("wtf ! �A��ݴN�ﱼ�� \n");
		}
		else
			break;
	}
	printf("a is a polynomial haha\n");
	while(1)
	{
		printf("please enter your second polynomial and don't ��� : \n");
		gets(b);
		
		if( isValid(b) == -1)
		{
			printf("wtf ! �ާA���䦺�� : \n");
		}
		else
			break;
	}
	while(1)
	{
		printf("please enter symbol and don't ��� : \n");
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
polynomial* inputPolynomial(char *s)	//�ǤJinput�A���@�ǳB�z,�]�N�O�h����A,B�C�^�Ǧh���� 
{
	int i;
	polynomial *p;
	p = (polynomial*)malloc( maxType * sizeof(polynomial) );
	
	for(i=0;i<strlen(s);i++)
	{
		
			
	}	
	
	return p;
}
int isValid(char *s)	//�O�_���Ī��h�����AENTER�O0 
{
	/*vincent
	*1x^5+30X ^   4- 50x ^1+ 1
	* if(p[i]==�Ʀr) while �ݥL�U�@��484x^  �άO+- ���L�Ů� �Y�S�� �ݦۤv484���� 
	*�Y���O�^��-1 �O�N�I�s inputPolynomial
	*/
	int i,check=0,len=strlen(s);	//check : if next symbols after num is x^ check = 1�Aelse if is +- check = 2, it should take turns
	
	//printf("in isValid(), the input string is : %s\n",p);
	if( isdigit(s[0]) && isdigit(s[len-1]) )	//ensure that first word is a number and the last word is, too(either power or constant)
	{
		return -1;
	}
	else
	{
		//printf("�Ĥ@�ӬO�Ʀr�A�Ȭ� : %c		�̫�@�ӬO�Ʀr�A�Ȭ� : %c\n",p[0],p[len-1]);
		for(i=0;i<(len-1);i++)	//?????????????????????????????????
		{
			//printf("��%d�Ӧr���A�Ȭ� : %c\n",i,p[i]);
			if(isdigit(s[i]))	//�J��Ʀr 
			{
				//printf("�J��Ʀr�A�Ȭ� : %c\n",p[i]);
				if(check==1)	//the next symbols should be +-
				{
					//printf("the next symbols should be +-  \n");
					while(1)	//��+- 
					{
						i++;
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(isdigit(s[i]))		//meet number don't bird it
							continue;
						else if(s[i]=='+' || s[i]=='-')	//good job! meet + or - 
						{
							//printf("good job! �Ʀr����O���t��\n"); 
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
					while(1)	//��x or X  or '\0'
					{
						i++;
						//printf("p[%d] = %c\n",i,p[i]);
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(isdigit(s[i]))		//meet number don't bird it
							continue;
						else if(s[i]=='X' || s[i]=='x')	//oh ya! meet x or X 
						{
							//printf("oh ya! �Ʀr����Ox\n"); 
							//check = 1;
							//i--;
							break;
						}
						else if(s[i]=='\0') //meet '\0' cool!
							return 8787;
						else
							return -1;
					}
					while(1)	//��^ 
					{
						i++;
						//printf("p[%d] = %c\n",i,p[i]);
						if(isspace(s[i]) || s[i]=='\t')	//meet space don't bird it
							continue;
						else if(s[i]=='^')	//oh ya! meet ^ 
						{
							//printf("oh ya! x����O^\n"); 
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
int getOperationType(char *s)	//�^�ǥ[�k�A��k�A���k
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
int inputOperationSymbol(char *s)	//��J�T�غ�k���@�A�٬O�n���b ,getOperationType
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
polynomial* operation(int s, polynomial *a, polynomial *b)	//�ǤJ���Ӻ�k�A�h����A,B�C�^�ǵ��� 
{
	return a;
}
polynomial* addition(polynomial *a, polynomial *b)	//�[�k 
{
	return a;
}
polynomial* subtraction(polynomial *a, polynomial *b)	//��k 
{
	return a;
}
polynomial* multiplication(polynomial *a, polynomial *b)	//���k 
{
	return a;
}
char* polynomialToString(polynomial *p)	//�o�쵲�G����A�ন�r��A�~��L�X�� 
{
	char *c;
	
	return c;
}

/*




*/


