#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Edge
{
    int begin, end, length;
};
inline int min (int __1, int __2)
{
    return (__1 < __2) ? __1 : __2;
}
int main (void)
{
    struct Edge edges[10002];
    int dist[102];
    int v, e, i, j;

    scanf ("%d %d", &v, &e);
    for (i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    for (i = 0; i < e; i++)
    {
        scanf ("%d %d %d", &edges[i].begin, &edges[i].end, &edges[i].length);
        edges[i].begin--;
        edges[i].end--;
    }
    for (i = 0; i < v; i++)
        for (j = 0; j < e; j++)
            if (dist[ edges[j].begin ] != INT_MAX)
                dist[ edges[j].end ] =
                    min (dist[ edges[j].end ], dist[ edges[j].begin ] + edges[j].length );
    for (i = 0; i < v; i++)
        printf ("%d ", dist[i] == INT_MAX ? 30000 : dist[i]);
    return 0;
}
