#if defined(_MSC_VER)
#define _CRT_SECURE_NO_DEPRECATE
#endif
 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__GNUC__)
 
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
 
#elif defined(_MSC_VER)
 
typedef __int64 int64_t;
#define PRId64 "I64d"
#define SCNd64 "I64d"
 
#endif
int mas_prost[20]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int64_t N=-1;
int mas[20]={0};
int D, i_mas;
void fun_rec(int del, int pr, int64_t temp)
{
    if(temp<0 || temp>1000000000000001 || del>D)
        return;
    if(del==D)
    {
        if(N==-1)
        {
            N=temp;
            return;
        }
        else
        {
            if(N>temp)
                N=temp;
            return;
        }
    }
    mas[pr]++;
    int temp_del=mas[0], fl=1;
    for(int i=1; fl && i<20; i++)
    {
        if(mas[i])
            temp_del=temp_del*(mas[i]+1)+mas[i];
        else
            fl=0;
    }
    fun_rec(temp_del+1, pr, temp*mas_prost[pr]);
    mas[pr]--; mas[pr+1]++;
    if(pr<19)
    {
        int temp_del=mas[0], fl=1;
        for(int i=1; fl && i<20; i++)
        {
            if(mas[i])
                temp_del=temp_del*(mas[i]+1)+mas[i];
            else
                fl=0;
        }
        fun_rec(temp_del+1, pr+1, temp*mas_prost[pr+1]);
        mas[pr+1]--;
    }
}
 
int main()
{
   freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
   scanf("%d", &D);
   if(D==1)
       printf("1");
   else
   {
   if(D==2)
       printf("2");
   else
   {
       mas[0]=1;
       fun_rec(2, 0, 2);
       if(N==-1)
           printf("0");
       else
           printf( "%" PRId64, N);
   }
   }
    return 0;
}