#include <iostream>
#define INF (1 << 31) - 1
using namespace std;
int n;
const int MAXN = 105;
int D[MAXN][MAXN];
char P[MAXN][MAXN];
int main()
{
    cout << "请输入顶点数目：\n";
    cin >> n;
    cout << "请输入初始化邻接矩阵：\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            P[i][j] = char('A' + j);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (D[j][k] > D[j][i] + D[i][k])
                {
                    D[j][k] = D[j][i] + D[i][k];
                    P[j][k] = char('A' + i);
                }
            }
        }
    }
    cout << "请输入查询的点对：\n";
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < n; ++i)
    {
        cout << endl;
        for (int j = 0; j < n; ++j)
            cout << D[i][j] << " ";
    }
    for (int i = 0; i < n; ++i)
    {
        cout << endl;
        for (int j = 0; j < n; ++j)
            cout << P[i][j] << " ";
    }
    printf("最短距离为：%d\n", D[a][b]);
    char k = P[a][b];
    printf("%c->", 'A' + a);
    while (k != b + 'A')
    {
        printf("%c->", k);
        k = P[k - 'A'][b];
    }
    printf("%c\n", 'A' + b);
}

/*
0 12 1000 1000 1000 16 14
12 0 10 1000 1000 7 1000
1000 10 0 3 5 6 1000
1000 1000 3 0 4 1000 1000
1000 1000 5 4 0 2 8
16 7 6 1000 2 0 9
14 1000 1000 1000 8 9 0
*/