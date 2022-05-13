// @author Soumya
#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size(), maxi = 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
        {
            set<char> box;
            for (int k = i; k <= j; k++)
            {
                box.insert(s[k]);
                if (box.size() < k - i + 1)
                    break;
            }
            if (box.size() > maxi)
                maxi = box.size();
        }

    return maxi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int arr[n][n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}