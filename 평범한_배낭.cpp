#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int w, v;
        scanf("%d%d", &w, &v);
        for (int j = k; j >= w; --j)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    printf("%d\n", dp[k]);
}