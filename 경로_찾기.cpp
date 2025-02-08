#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][k] != 0 && v[k][j] != 0)
                {
                    v[i][j] = 1;
                }
            }
            
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}