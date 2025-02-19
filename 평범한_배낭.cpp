#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    unordered_map<int, int> dp;
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int w, v;
        scanf("%d%d", &w, &v);

        unordered_map<int, int> new_dp = dp;
        for (auto& [weight, value] : dp)
        {
            if (weight + w <= k)
            {
                new_dp[weight + w] = max(new_dp[weight + w], value + v);
            }
        }
        dp = move(new_dp);
    }

    int maxValue = 0;
    for (auto& [weight, value] : dp)
    {
        maxValue = max(maxValue, value);
    }

    printf("%d\n", maxValue);
}