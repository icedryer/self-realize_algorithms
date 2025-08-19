#include <iostream>
using namespace std;
const int MAXN = 5005;
int fa[MAXN];
int n;
void init()
{
    for (int i = 0; i <= n; ++i)
    {
        fa[i] = i;
    }
}

int find(int s)
{
    if (fa[s] == s)
        return s;
    else
    {
        fa[s] = find(fa[s]); // 将路径上的父节点全部设为根节点
        return fa[s];
    }
}
void merge(int i, int j)
{
    fa[find(j)] = find(fa[i]); // 让根节点的父节点与另一个根节点相同
}

int main()
{
    int m, p;
    cin >> n >> m >> p;
    init();
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 0; i < p; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}