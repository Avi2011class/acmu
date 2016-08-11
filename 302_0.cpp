#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>

class DSU
{
private:
    size_t size;
    std::vector<size_t> Parent;
    std::vector<size_t> Range;
public:
    DSU(size_t size) :
        size(size),
        Parent(std::vector<size_t>(size)),
        Range(std::vector<size_t>(size))
    {
        for(size_t i = 0; i < size; i++)
        {
            Parent[i] = i;
            Range[i] = 1;
        }
    }
private:
    size_t find_set(size_t V)
    {
        if(Parent[V] == V)
            return V;
        else
        {
            Parent[V] = find_set(Parent[V]);
            return Parent[V];
        }
    }
public:
    void union_sets(size_t X, size_t Y)
    {
        X = find_set(X);
        Y = find_set(Y);
        if(X != Y)
        {
            if(Range[X] < Range[Y])
                std::swap(X, Y);
            Parent[Y] = X;
            Range[X] += Range[Y];
        }
    }
    bool is_sets_equal(size_t X, size_t Y)
    {
        return (find_set(X) == find_set(Y));
    }
};

class Edge
{
public:
    int __begin;
    int __end;
    double __weight;
    Edge(int __begin, int __end, double __weight) :
        __begin(__begin), __end(__end), __weight(__weight)
    {}
    friend bool operator < (Edge & __1, Edge & __2)
    {
        return __1.__weight < __2.__weight;
    }
    friend std::ostream & operator << (std::ostream & output_stream, Edge E)
    {
        output_stream << "Edge: (" << E.__begin << " -> " << E.__end << "): " << E.__weight;
        return output_stream;
    }
};

int main(void)
{
    int N;
    std::cin >> N;
    std::vector< std::pair< double, double > > location(N);
    for (size_t i = 0; i < N; i++)
        std::cin >> location[i].first >> location[i].second;
    std::vector< Edge > E;
    for (size_t i = 0; i < N - 1; i++)
        for (size_t j = i + 1; j < N; j++)
            E.push_back(Edge(i, j,
                        (location[i].first - location[j].first) * (location[i].first - location[j].first) +
                        (location[i].second - location[j].second) * (location[i].second - location[j].second)));
    std::sort(E.begin(), E.end());

    DSU D(N);
    double result = 0;
    for (int iter = 0, count = 0; count < N - 1; iter++)
    {
        if(!D.is_sets_equal(E[iter].__begin, E[iter].__end))
        {
            D.union_sets(E[iter].__begin, E[iter].__end);
            result = E[iter].__weight;
            count++;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << sqrt(result) << std::endl;

    return 0;
}
