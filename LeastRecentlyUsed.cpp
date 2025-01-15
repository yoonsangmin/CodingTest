#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, maxCount;
    stack<int> s;
    vector<bool> visited(101, false);

    cin >> n >> maxCount;

    for (int i = 0; i < maxCount; ++i)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }

    int count = 0;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        if (visited[temp])
        {
            continue;
        }
        visited[temp] = true;
        cout << temp << " ";
        ++count;

        if (count == n)
        {
            break;
        }
    }
}