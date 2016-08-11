#include <stdio.h>
#include <stdlib.h>

long a,b;
int i;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%ld",&a);

  if (a==0) printf("1");
  else if (a>0)
  {
  b=a*(a+1)/2;
  printf("%ld",b);
  }
  else if (a<0)
  {
  b=-(a*(a-1)/2)+1;
  printf("%ld",b);
  };
  return 0;
}

