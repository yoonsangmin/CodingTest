// https://www.acmicpc.net/problem/1259
#include <iostream>

using namespace std;

string boolString[2] = {"no", "yes"};

int main()
{
    while(true)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            break;
        }
        if (input % 10 == 0)
        {
            cout << boolString[false] << "\n";
            continue;
        }

        int length;
        int temp;
        int count = 1;
        int dec = 1;
        bool isPalindrome = true;

        temp = input;
        while (temp / 10 != 0)
        {
            temp /= 10;
            dec *= 10;
            ++count;
        }

        temp = input;
        for (int i = 0; i < count / 2; ++i)
        {
            int left = temp / dec;
            temp -= left * dec;
            int right = temp % 10;
            dec /= 100;
            temp /= 10;

            if (left != right)
            {
                isPalindrome = false;
                break;
            }
        }

        cout << boolString[isPalindrome] << "\n";
    }
}