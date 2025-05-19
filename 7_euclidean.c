//WAP to compute gcd of any two number using Euclidean Algorithm
#include<stdio.h>

int gcd(int a, int b)
{
    if( a > b)
    {
        int temp=b;
        b = a;
        a= temp ;
    }

    int r;
    while(b>0)
    {
        r=a % b;
        a = b;
        b = r;
    }
    return a;
}

void main()
{
    int a,b;

    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    printf("GCD of %d and %d is : %d ",a,b,gcd(a,b));
}
