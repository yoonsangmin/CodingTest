#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareBySecond(const vector<long long> &a, const vector<long long> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }

    return a[1] < b[1];
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<long long>> sortByFirst(n, vector<long long>(3));
    vector<vector<long long>> sortBySecond(n, vector<long long>(3));

    for (int i = 0; i < n; ++i)
    {
        long long first, second;
        scanf("%lld%lld", &first, &second);

        sortByFirst[i][0] = first;
        sortByFirst[i][1] = second;
        sortByFirst[i][2] = i;

        sortBySecond[i][0] = first;
        sortBySecond[i][1] = second;
        sortBySecond[i][2] = i;
    }

    sort(sortByFirst.begin(), sortByFirst.end());
    sort(sortBySecond.begin(), sortBySecond.end(), CompareBySecond);

    vector<bool> visited(n, false);
    int firstIndex = 1, secondIndex = 0;
    int pickedFirstIndex = 0;
    long long sum = 0;

    sum = sortByFirst[0][1];
    printf("%lld\n", sortByFirst[0][0]);
    visited[sortByFirst[0][2]] = true;

    while (secondIndex < n && visited[sortBySecond[secondIndex][2]])
    {
        ++secondIndex;
    }

    while (firstIndex < n && secondIndex < n)
    {
        long long firstChanged = sum + sortByFirst[firstIndex][0];
        long long secondChanged = sum + sortByFirst[pickedFirstIndex][0] - sortByFirst[pickedFirstIndex][1] + sortBySecond[secondIndex][1];

        if (firstChanged < secondChanged)
        {
            printf("%lld\n", firstChanged);
            pickedFirstIndex = firstIndex;
            visited[sortByFirst[firstIndex][2]] = true;
            sum += sortByFirst[firstIndex][1];
        }
        else
        {
            printf("%lld\n", secondChanged);
            visited[sortBySecond[secondIndex][2]] = true;
            sum += sortBySecond[secondIndex][1];
        }

        while (firstIndex < n && visited[sortByFirst[firstIndex][2]])
        {
            ++firstIndex;
        }

        while (secondIndex < n && visited[sortBySecond[secondIndex][2]])
        {
            ++secondIndex;
        }
    }
}