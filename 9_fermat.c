#include<stdio.h>
#include<math.h>

int fermatLittle(int a, int p) {
   
   int powVal;
      powVal = pow(a, (p - 1));
      if((powVal - 1) % p == 0 ){
       printf("\n%d is a prime.\n",p);
      }
      else{
       printf("%d is a not prime. theorem is wrong",p);
      }
     
}

int main()
{
    int a,m;

    printf("Enter prime number and positive integer not divisible by p:");
    scanf("%d %d",&m,&a);
   fermatLittle(a, m);
   return 0;
}
