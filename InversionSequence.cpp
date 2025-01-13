#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;

    vector<int> input(count, 0);
    for (int i = 0; i < count; ++i)
    {
        int temp;
        cin >> temp;
        input[i] = temp;
    }

    vector<int> v;
    for (int idx = count - 1; idx >= 0; --idx)
    {
        int current = idx + 1;
        v.insert(v.begin() + input[idx], current);
    }

    for (auto& item : v)
    {
        cout << item << " ";
    }
}