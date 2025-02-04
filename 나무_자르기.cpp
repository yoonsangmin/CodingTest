#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int main()
{
    int n;
    long long m;
    scanf("%d %lld", &n, &m);

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }

    int start = 0;
    int end = *max_element(v.begin(), v.end());
    int answer = 0;

    while (start < end)
    {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (auto& elem : v)
        {
            sum += max(elem - mid, 0);
        }
        
        if (sum < m)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
            answer = mid;
        }
    }

    printf("%d\n", answer);
}