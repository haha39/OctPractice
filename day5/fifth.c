//If We Were Vampires 
#include <stdio.h>
#include <stdlib.h>
//using namespace std;
#define maxDegree 10
#define maxType 100

typedef struct Polynomial
{
	int degree;
	float coef[maxDegree];
}polynomial;
/**/
polynomial* inputPolynomial(char*);
polynomial* isValid(char*);
int getOperationType(char*);
int inputOperationSymbol(char*);
polynomial* operation(int, polynomial*, polynomial*);
polynomial* addition(polynomial*, polynomial*);
polynomial* subtraction(polynomial*, polynomial*);
polynomial* multiplication(polynomial*, polynomial*);
char* polynomialToString(polynomial*);


int main()
{
	char a[maxType];
	char b[maxType];
	char s;
	int o;
	/*while(1)
	{
		printf("please enter your first polynomial and don't ��� : \n");
		gets(a);
		
		if( isValid(a) == -1)
		{
			printf("wtf ! �A��ݴN�ﱼ�� : \n");
		}
		else
			break;
	}
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
		printf("please enter your first polynomial and don't ��� : \n");
		s = getchar();
		o = inputOperationSymbol(s);
		if(o == -1)
		{
			printf("wtf ! how !? how i ask you this piece of shit : \n");
		}
		else
			break;
	}	
	
	polynomialToString( operation( o, inputPolynomial(a), inputPolynomial(b) ) );*/
	
	system("PAUSE");
	return 0;
}

/**/
polynomial* inputPolynomial(char *p)						//�ǤJinput�A���@�ǳB�z,�]�N�O�h����A,B�C�^�Ǧh���� 
{
	return p;
}
polynomial* isValid(char *p)										//�O�_���Ī��h�����AENTER�O0 
{
	
	return 8787;
}
int getOperationType(char *s)								//�^�ǥ[�k�A��k�A���k
{
	return 8787;
}
int inputOperationSymbol(char *s)							//��J�T�غ�k���@�A�٬O�n���b ,getOperationType
{
	return 8787;
}
polynomial* operation(int s, polynomial *a, polynomial *b)	//�ǤJ���Ӻ�k�A�h����A,B�C�^�ǵ��� 
{
	return a;
}
polynomial* addition(polynomial *a, polynomial *b)			//�[�k 
{
	return a;
}
polynomial* subtraction(polynomial *a, polynomial *b)			//��k 
{
	return a;
}
polynomial* multiplication(polynomial *a, polynomial *b)			//���k 
{
	return a;
}
char* polynomialToString(polynomial *p)					//�o�쵲�G����A�ন�r��A�~��L�X�� 
{
	char *c;
	
	return c;
}





