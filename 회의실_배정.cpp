// https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int count;
    cin >> count;

    vector<vector<long long>> meetings(count, vector<long long>(2, 0));

    int start, end;
    for (int i = 0; i < count; ++i)
    {
        cin >> start >> end;
        meetings[i][0] = start;
        meetings[i][1] = end;
    }

    sort(meetings.begin(), meetings.end());

    long long maxMeeting = 1;
    int selected = 0;

    for (int i = 1; i < count; ++i)
    {
        if (meetings[i][0] >= meetings[selected][1])
        {
            ++maxMeeting;
            selected = i;
            continue;
        }
        if (meetings[i][1] < meetings[selected][1])
        {
            selected = i;
        }
    }

    cout << maxMeeting;
}