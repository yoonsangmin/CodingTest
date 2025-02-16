#include <iostream>
#include <vector>

#define INF 210000000

using namespace std;

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    vector<vector<int>> v(n, vector<int>(n, INF));

    for (int i = 0; i < m; ++i)
    {
        int start, end, price;
        scanf("%d%d%d", &start, &end, &price);

        if (v[start - 1][end - 1] > price)
        {
            v[start - 1][end - 1] = price;
        }
    }

    int from, to;
    scanf("%d%d", &from, &to);
    --from;
    --to;

    vector<int> dp(n, INF);
    vector<bool> visited(n, false);

    dp[from] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int min = INF;
        int current = 0;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && min > dp[j])
            {
                min = dp[j];
                current = j;
            }
        }

        visited[current] = true;
        
        for (int j = 0; j < n; ++j)
        {
            if (v[current][j] == INF)
            {
                continue;
            }

            if (dp[j] > dp[current] + v[current][j])
            {
                dp[j] = dp[current] + v[current][j];
            }
        }
    }

    printf("%d\n", dp[to]);
}