#include<stdio.h>
#include<limits.h>
int main(){
    printf("Maximum number stored by int: %d\n", INT_MAX);
    printf("Minimum number stored by int: %d\n", INT_MIN);
    printf("n is %d bytes long\n", sizeof(int));
    printf("Maximum number stored by short int: %d\n", SHRT_MAX);
    printf("Minimum number stored by short int: %d\n", SHRT_MIN);
    printf("n is %d bytes long\n", sizeof(int));


    // testing if 1 million is a valid int
    int n=1000000;
    printf("value of n is %d\n", n);
    printf("n is %d bytes long\n", sizeof(int));

    return 0;
}

