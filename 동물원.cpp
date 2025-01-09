// https://www.acmicpc.net/problem/1309
#include <iostream>

using namespace std;

int main()
{
    int length;
    cin >> length;

    int even = 1;
    int empty = 1;

    for (int i = 1; i < length; ++i)
    {
        int temp = empty;
        empty = (empty + even * 2) % 9901;
        even = (even + temp) % 9901;
    }

    cout << (even * 2 + empty) % 9901;
}