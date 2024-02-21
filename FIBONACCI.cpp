#include<stdio.h>
int fibonacci(int n)
{
	if(n<=1)
		return 1;
  }
int main(){
	int n,i;
printf("enter the number of elements");
scanf("%d",&n);
printf("fibonacci seris");
for(i=0;i<n;i++){
	printf("%d",fibonacci(i));
}
return 0;
}


