#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long a,b,c;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%ld%ld%ld",&a,&b,&c);
  if (a*b==c)
  {
  printf("YES");
  }
  else
  {
  printf("NO");
  }
  return 0;
}

