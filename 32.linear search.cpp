#include<stdio.h>
int main()
{
	int a[100],c,n,search;
	printf("enter the number:");
	scanf("%d",&n);
	printf("enter the no of elements:");
	for(c=0;c<n;c++)
	scanf("%d",&a[c]);
	printf("enter number to be searched:");
	scanf("%d",&search);
	for(c=0;c<n;c++)
	{
		if(a[c]==search)
		{
		
		printf("%d is present at location %d",search,c+1);
		break;
	}
	}
	if(c==n)
	{
		printf("%d is not present in array",search);
	}
	return 0;
}
