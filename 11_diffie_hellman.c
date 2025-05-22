//Lab11: WAP to implement Diffie Hellma Key Excahnge Algorithm. 
#include<stdio.h>
#include<math.h>

void main()
{
  int q, a;
  int xa,xb;

  printf("Enter prime number: ");
  scanf("%d",&q);

  printf("Enter a primitive root of %d : ",q);
  scanf("%d",&a);

  printf("User A:\nSelect private key:");
  scanf("%d",&xa);

  printf("User B:\nSelect private key:");
  scanf("%d",&xb);

  int val = pow(a,xa);
  int ya = val % q;
  val = pow(a,xb);
  int yb = val % q;

  val = pow(yb,xa);
  int k1 = val % q;
  val = pow(ya,xb);
  int k2 = val % q;

  printf("\nUser A:\nPublic Key: %d and secret key: %d ",ya,k1);
  printf("\n\nUser B:\nPublic Key: %d and secret key: %d ",yb,k2);
}
