#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;

    scanf("%d %d", &n, &m);

    vector<vector<int>> v(1025, vector<int>(1025, 0));

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            int temp;
            scanf("%d", &temp);
            v[x][y] = temp + v[x - 1][y] + v[x][y - 1] - v[x - 1][y - 1];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int answer = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
        printf("%d\n", answer);
    }
}