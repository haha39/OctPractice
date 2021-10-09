#include <stdio.h>
#include <stdlib.h>

int hierarchy(int x)
{
	int h=1;
	int i;
	for(i=x;i>0;i--)
	{
		h = h * i;
	}
	printf("h : %lld\n",h);
	return h;	
}

/*int max(int m,int n)
{
	int max;
	max = (m>n) ? m : n;
	return max;
}*/

int uniquePaths(int m, int n)
{
	int max,min,i,med_ans=1;
	m--;
	n--;
	if(m>n)
	{
		max = m;
		min = n;	
	}
	else
	{
		max = n;
		min = m;
	}
	
	for(i=m+n;i>max;i--)
	{
		med_ans *= i;
		printf("%d\n",i);
	}
	
	return med_ans/hierarchy(min);
}

/**/

int main() 
{
	printf("jojo : %d\n",uniquePaths(7,3));

	return 0;
}


