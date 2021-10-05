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
		printf("please enter your first polynomial and don't 手殘 : \n");
		gets(a);
		
		if( isValid(a) == -1)
		{
			printf("wtf ! 再手殘就剁掉喔 : \n");
		}
		else
			break;
	}
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
		printf("please enter your first polynomial and don't 手殘 : \n");
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
polynomial* inputPolynomial(char *p)						//傳入input，做一些處理,也就是多項式A,B。回傳多項式 
{
	return p;
}
polynomial* isValid(char *p)										//是否有效的多項式，ENTER是0 
{
	
	return 8787;
}
int getOperationType(char *s)								//回傳加法，減法，乘法
{
	return 8787;
}
int inputOperationSymbol(char *s)							//輸入三種算法之一，還是要防呆 ,getOperationType
{
	return 8787;
}
polynomial* operation(int s, polynomial *a, polynomial *b)	//傳入哪個算法，多項式A,B。回傳答案 
{
	return a;
}
polynomial* addition(polynomial *a, polynomial *b)			//加法 
{
	return a;
}
polynomial* subtraction(polynomial *a, polynomial *b)			//減法 
{
	return a;
}
polynomial* multiplication(polynomial *a, polynomial *b)			//乘法 
{
	return a;
}
char* polynomialToString(polynomial *p)					//得到結果之後，轉成字串，才能印出來 
{
	char *c;
	
	return c;
}





