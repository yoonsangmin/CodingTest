#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    vector<vector<int>> v(n + 1, vector<int>(n + 1, n + 1));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x][y] = 1;
        v[y][x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        v[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    int kevin = (n + 1) * (n + 1);
    int index = 1;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += v[i][j];
        }

        if (kevin > sum)
        {
            kevin = sum;
            index = i;
        }
    }

    printf("%d\n", index);
}