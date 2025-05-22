//WAP to find Euler's totient function of any number n
#include<stdio.h>
#include<math.h>


int gcd( int a ,int b)
{
    int r;
    while(b>0)
    {
        r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int euler_totient( int n )
{
    int val=1;

    for(int i=2;i<n;i++)
        if( gcd(i,n) == 1)
            val++;
    
    return val;
}

void main()
{
    int n;

    printf("Enter number: ");
    scanf("%d",&n);

    printf("Euler totient function of %d is %d",n,euler_totient(n));
}


