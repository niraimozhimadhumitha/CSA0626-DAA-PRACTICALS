#include<stdio.h> 
int gcd(int a, int b) 
{ 
 if (b == 0) 
   return (a); 
 return gcd(b,a%b); 
} 
int main() 
{ 
 int a = 4, b = 8; 
 printf("%d", gcd(a,b)); 
 return (0); 
} 

