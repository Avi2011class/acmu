#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main (void)
{
    int height[30001];
    int n, i;
    double s = 0;

    scanf ("%d", &n);
    for (i = 0; i < n; i++)
        scanf ("%d", &height[i]);

    for (i = 0; i < n - 1; i++)
        s += (double)(height[i] + height[i + 1]) / 2;

    printf ("%.8lg", s / (double)(n - 1));
    return 0;
}
