#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize)
{
	int i,left=0,right=heightSize-1,tmp=0,max=0,tmp_index=0,flag=0;
	
	while(1)
	{
		if(height[left] < height[right])
		{
			printf("右大\n");
			tmp = height[left] * (right-left);
			if(tmp > max)
				max = tmp;
			left = left + 1;
		}
		else if(height[left] > height[right])
		{
			printf("左大\n");
			tmp = height[right] * (right-left);
			if(tmp > max)
				max = tmp;
			right = right - 1;
		}
		else
		{
			printf("一樣\n");
			tmp = height[right] * (right-left);
			if(tmp > max)
				max = tmp;
			//printf("%d %d %d\n",left,right,max);
			if(left+1==right)
				flag = 1;
			else
			{
				for(i=1;i<(right-left)/2+1;i++)
				{
					if(height[left+i]>height[left])
					{
						printf("left\n");
						left = left+1;
						break;
					}
					else if(height[right-i]>height[left])
					{
						printf("right\n");
						right = right-1;
						break;
					}
					else
					{
						printf("other\n");
						if(i == (right-left)/2)
							flag = 1;
					}
				}
			}
			/*if(flag == 1)
				break;*/
		}
		if(left == right || flag == 1)
		{
			break;
		}
		//printf("\n");
	}
	
	return max;
}
/**/
int main() 
{
	/**/int a[] = {1,8,6,2,5,4,8,3,7};
	printf("jojo : %d\n",maxArea(a,9));
	int b[] = {1,1};
	printf("jojo : %d\n",maxArea(b,2));
	int c[] = {4,3,2,1,4};
	printf("jojo : %d\n",maxArea(c,5));
	int d[] = {1,2,1};
	printf("jojo : %d\n",maxArea(d,3));
	int e[] = {2,1};
	printf("jojo : %d\n",maxArea(e,2));
	int f[] = {1,3,2,5,25,24,5};
	printf("jojo : %d\n",maxArea(f,7));
	int g[] = {1,0,0,0,0,0,0,2,2};
	printf("jojo : %d\n",maxArea(g,9));
	int h[] = {1,8,100,2,100,4,8,3,7};
	printf("jojo : %d\n",maxArea(h,9));
	return 0;
}


