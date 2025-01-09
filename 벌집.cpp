// https://www.acmicpc.net/problem/2292
#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    int i = 0;
    int edgeCount = 1;

    while (n > 0)
    {
        n -= edgeCount;
        ++i;
        edgeCount = i * 6;
    }

    cout << i;
}