#include <iostream>
#include <vector>

using namespace std;

void update(vector<int> &v, int index, int value)
{
    int i = index;
    while (i < v.size())
    {
        v[i] += value;
        i += (i & -i);
    }
}

int query(const vector<int> &v, int index)
{
    int sum = 0;
    int i = index;
    while (i > 0)
    {
        sum += v[i];
        i -= (i & -i);
    }
    return sum;
}

int search(vector<int> &v, int k)
{
    int start = 1;
    int end = v.size();
    int mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (k <= query(v, mid))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

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

    vector<int> availables(count + 1, 0);

    for (int i = 1; i < availables.size(); ++i)
    {
        update(availables, i, 1);
    }

    vector<int> result(count);
    for (int i = 0; i < count; ++i)
    {
        int index = search(availables, input[i] + 1);
        update(availables, index, -1);
        result[index - 1] = i + 1;
    }

    for (auto &item : result)
    {
        cout << item << " ";
    }
}