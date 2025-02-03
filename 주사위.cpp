#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int twofacePosibilities[12][2] = {
    {0, 1},
    {0, 2},
    {0, 3},
    {0, 4},
    {1, 2},
    {1, 3},
    {1, 5},
    {2, 4},
    {2, 5},
    {3, 4},
    {3, 5},
    {4, 5}
};

int threefacePosibilities[8][3] = {
    {0, 1, 2},
    {0, 1, 3},
    {0, 3, 4},
    {0, 2, 4},
    {5, 1, 2},
    {5, 1, 3},
    {5, 3, 4},
    {5, 2, 4}
};

int main()
{
    long long n;
    vector<int> faces;

    cin >> n;
    for (int i = 0; i < 6; ++i)
    {
        int input;
        cin >> input;
        faces.push_back(input);
    }

    if (n == 1)
    {
        sort(faces.begin(), faces.end());
        cout << accumulate(faces.begin(), faces.begin() + 5, 0);
        return 0;
    }

    int onefaceMin = 50;
    int twofaceMin = 100;
    int threefaceMin = 150;

    for (int i = 0; i < 6; ++i)
    {
        onefaceMin = min(onefaceMin, faces[i]);
    }

    for (int i = 0; i < 12; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 2; ++j)
        {
            sum += faces[twofacePosibilities[i][j]];
        }
        twofaceMin = min(twofaceMin, sum);
    }

    for (int i = 0; i < 8; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
        {
            sum += faces[threefacePosibilities[i][j]];
        }
        threefaceMin = min(threefaceMin, sum);
    }

    cout << threefaceMin * 4 +
                twofaceMin * ((n - 2) * 8 + 4) +
                onefaceMin * ((n - 2) * ((n - 2) * 5 + 4));
    return 0;
}