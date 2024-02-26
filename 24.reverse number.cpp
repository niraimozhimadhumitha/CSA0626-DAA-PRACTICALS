#include <stdio.h>

int reverse(int num, int rev) {
    if (num == 0) 
        return rev;
    else
        return reverse(num / 10, rev * 10 + num % 10); 
}

int main() {
    int num, rev = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    rev = reverse(num, 0);
    
    printf("Reverse of %d is %d\n", num, rev);
}
