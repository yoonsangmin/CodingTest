#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, maxCount;
    deque<int> d;

    cin >> n >> maxCount;

    for (int i = 0; i < maxCount; ++i)
    {
        int temp;
        cin >> temp;

        if (d.size() < n)
        {
            d.push_front(temp);
            continue;
        }

        auto iter = find(d.begin(), d.end(), temp);

        if (iter != d.end())
        {
            for (auto it = iter; it > d.begin(); --it)
            {
                *it = *(it - 1);
            }
            *d.begin() = temp;
            // d.erase(iter);
            // d.push_front(temp);
        }
        else
        {
            d.pop_back();
            d.push_front(temp);
        }
    }

    for (auto& item : d)
    {
        cout << item << " ";
    }
}