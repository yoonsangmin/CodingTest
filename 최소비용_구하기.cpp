#include <iostream>
#include <vector>
#include <queue>

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
    priority_queue<pair<int, int>> pq;

    dp[from] = 0;
    pq.push({0, from});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (dp[current] < distance)
        {
            continue;
        }
        
        for (int j = 0; j < n; ++j)
        {
            if (v[current][j] == INF)
            {
                continue;
            }

            if (dp[j] > dp[current] + v[current][j])
            {
                dp[j] = dp[current] + v[current][j];
                pq.push({dp[j], j});
            }
        }
    }

    printf("%d\n", dp[to]);
}