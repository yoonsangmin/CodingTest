// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int count;

//     scanf("%d", &count);

//     for (int i = 0; i < count; ++i)
//     {
//         int p, n;

//         scanf("%d%d", &p, &n);

//         vector<int> input(n);
//         for (int i = 0; i < n; ++i)
//         {
//             scanf("%d", &input[i]);
//         }

//         vector<int> v;
//         v.assign(input.begin(), input.end());
//         sort(v.begin(), v.end(), greater<>());

//         // 가장 돈을 많이 가진 사람 - 더 내야 하는 사람.
//         const int higestWealth = v[0];
//         // 최대 내야할 돈 - 돈 없는 사람은 전재산 냄.
//         int targetToPay = 0;
//         // 돈 떨어지지 않은 사람 중에 돈이 제일 적은 사람.
//         int last = n - 1;
//         int sum = 0;

//         while (last >= 0)
//         {
//             if (sum + (last + 1) >= p)
//             {
//                 break;
//             }

//             sum += last + 1;
//             ++targetToPay;

//             // 돈 떨어진 사람 제외.
//             while (last >= 0 && v[last] <= targetToPay)
//             {
//                 --last;
//             }
//         }

//         if (p - sum > (last + 1))
//         {
//             printf("IMPOSSIBLE\n");
//             continue;
//         }

//         int remainBalance = p - sum;

//         // 출력.
//         for (int i = 0; i < n; ++i)
//         {
//             if (input[i] == higestWealth && remainBalance > 0)
//             {
//                 --remainBalance;
//                 printf("%d ", targetToPay + 1);
//                 continue;
//             }

//             printf("%d ", (input[i] < targetToPay ? input[i] : targetToPay));
//         }
//         printf("\n");
//     }
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main()
{
    int count;

    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        int p, n;

        scanf("%d%d", &p, &n);

        vector<int> v(n);
        vector<pair<int, int>> moneyIndices(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &v[i]);
            moneyIndices[i] = { v[i], i };
        }

        sort(moneyIndices.begin(), moneyIndices.end(), Compare);

        vector<int> paid(n, 0);
        int sum = 0;
        int last = n - 1;
        int nextLast = n - 1;

        while (sum < p && last >= 0)
        {
            for (int i = 0; i <= last; ++i)
            {
                int index = moneyIndices[i].second;
                ++paid[index];
                ++sum;

                if (paid[index] == v[index] && nextLast >= last)
                {
                    nextLast = i - 1;
                }

                if ((sum == p) || last < 0)
                {
                    break;
                }
            }
            
            last = nextLast;
        }

        if (sum != p)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        for (int i = 0; i < n; ++i)
        {
            printf("%d ", paid[i]);
        }
        printf("\n");
    }
}