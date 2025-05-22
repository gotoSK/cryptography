//RSA

#include<stdio.h>
#include<stdlib.h>


int gcd(int a, int b)
{
    int r;

    while(b>0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int compute(int e, int phi)
{
    int d=1;

    while ( (e*d)%phi != 1)
        d++;

    return d;
}
void main()
{
    int p,q;

    printf("Enter two prime numbers: ");
    scanf("%d %d",&p,&q);

    int n = p * q ;
    int phi = (p-1)*(q-1);
    
    int e = 2;
    while ( gcd(phi,e) != 1)
        e++;

    int d = compute(e,phi);

    printf("\nPublic Key { %d, %d }",e,n);
    printf("\nPrivate Key { %d, %d }",d,n);
}
