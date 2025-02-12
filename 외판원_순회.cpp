#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<vector<int>> edges(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int temp;
            scanf("%d", &temp);
            if (temp != 0)
            {
                edges[i][j] = temp;
            }
        }
    }

    // 비트마스크를 이용한 DP.
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    int answer = INF;

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        for (int u = 0; u < n; ++u)
        {
            // 방문한 경우.
            if (mask & (1 << u))
            {
                for (int v = 0; v < n; ++v)
                {
                    // 방문하지 않은 노드들에 대하여. 경로가 존재할 때.
                    if (!(mask & (1 << v)) && edges[u][v] != INF)
                    {
                        // u를 경유해 v 노드를 방문한 경우 최솟값 선택.
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + edges[u][v]);
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        // INF 처리 - INF 끼리 더하면 오버플로우 발생.
        if (dp[(1 << n) - 1][i] != INF && edges[i][0] != INF)
        {
            answer = min(answer, dp[(1 << n) - 1][i] + edges[i][0]);
        }
    }

    printf("%d\n", answer);
}