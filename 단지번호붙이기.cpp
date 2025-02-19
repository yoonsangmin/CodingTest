#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;

        for (int j = 0; j < n; ++j)
        {
            v[i][j] = input[j] - '0';
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (v[i][j] != 1)
            {
                continue;
            }

            queue<pair<int, int>> q;
            int count = 0;

            q.push({i, j});

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (v[x][y] != 1)
                {
                    continue;
                }

                v[x][y] = 0;
                ++count;

                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny] != 1)
                    {
                        continue;
                    }

                    q.push({nx, ny});
                }
            }

            answer.push_back(count);
        }
    }

    sort(answer.begin(), answer.end());

    printf("%d\n", answer.size());
    for (int item : answer)
    {
        printf("%d\n", item);
    }
}