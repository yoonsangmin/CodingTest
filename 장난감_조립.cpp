// #include <iostream>
// #include <vector>

// using namespace std;

// void dissemble(vector<vector<int>>& v, vector<bool>& completed, int current)
// {
//     if (completed[current])
//     {
//         return;
//     }

//     for (int i = 1; i < v[current].size(); ++i)
//     {
//         if (v[current][i] == 0 || current == i)
//         {
//             continue;
//         }

//         if (!completed[i])
//         {
//             dissemble(v, completed, i);
//         }

//         int amount = v[current][i];
//         v[current][i] = 0;

//         for (int j = 1; j < v[i].size(); ++j)
//         {
//             v[current][j] += v[i][j] * amount;
//         }
//     }
    
//     completed[current] = true;
// }

// int main()
// {
//     int n, m;

//     scanf("%d %d", &n, &m);

//     vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
//     vector<bool> completed(n + 1, true);

//     for (int i = 0; i < m; ++i)
//     {
//         int assembly, part, count;
//         scanf("%d %d %d", &assembly, &part, &count);
//         v[assembly][part] = count;
//         completed[assembly] = false;
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         if (completed[i])
//         {
//             v[i][i] = 1;
//         }
//     }

//     dissemble(v, completed, n);

//     for (int i = 0; i < v[n].size(); ++i)
//     {
//         if (v[n][i] == 0)
//         {
//             continue;
//         }

//         printf("%d %d\n", i, v[n][i]);
//     }
// }

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<bool> completed(n + 1, true);

    for (int i = 0; i < m; ++i)
    {
        int assembly, part, count;
        scanf("%d %d %d", &assembly, &part, &count);
        v[assembly][part] = count;
        completed[assembly] = false;
    }

    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < n + 1; ++i)
        {
            if (completed[i])
            {
                continue;
            }

            if (v[n][i] != 0)
            {
                flag = true;

                for (int j = 1; j < n + 1; ++j)
                {
                    v[n][j] += v[i][j] * v[n][i];
                }

                v[n][i] = 0;
            }
        }
    }
    
    for (int i = 0; i < v[n].size(); ++i)
    {
        if (v[n][i] == 0)
        {
            continue;
        }

        printf("%d %d\n", i, v[n][i]);
    }
}