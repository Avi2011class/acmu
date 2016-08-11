#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct edge
{
    int start;
    int stop;
    int weight;
};
int main(void)
{
    int n;
    edge tmp;
    int we;
    cin >> n;
    vector< edge > V;
    V.reserve(n * n);
    for( size_t i = 0; i < n; i++ )
        for( size_t j = 0; j < n; j++ )
        {
            cin >> we;
            if( we != 100000 )
            {
                tmp.start = i;
                tmp.stop = j;
                tmp.weight = we;
                V.push_back(tmp);
            }
        }

    vector< int > res(n + 4, INT_MAX);

    int iter = 0;
    while(iter < n)
    {
        res[iter] = 0;
        bool flag = true;
        int iteration = 0;
        while(flag)
        {
            flag = false;
            for(size_t i = 0; i < V.size(); i++)
            {
                if(res[V[i].start] != INT_MAX)
                    if(res[V[i].stop] > res[V[i].start] + V[i].weight)
                    {
                        res[V[i].stop] = res[V[i].start] + V[i].weight;
                        flag = true;
                        iteration ++;
                    }
            }
            if(iteration > 100000)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        while(res[iter] != INT_MAX)
            iter++;
    }
    cout << "NO" << endl;
    return 0;
}
