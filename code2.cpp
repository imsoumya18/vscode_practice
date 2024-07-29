// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

vector<int> find_elements(vector<int> vct, int n)
{
    vector<int> temp(n, 0);
    int repeat = -1, missing = -1;

    for (int i = 0; i < n; i++)
    {
        temp[vct[i] - 1]++;

        if (temp[vct[i] - 1] > 1)
            repeat = vct[i];
    }

    for (int i = 0; i < n; i++)
        if (temp[i] == 0)
        {
            missing = i + 1;
            break;
        }

    return vector<int>{missing, repeat};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{1, 3, 3, 4, 5, 6, 7};

    vector<int> ans = find_elements(vct, vct.size());

    cout << "missing: " << ans[0] << endl;
    cout << "repeating: " << ans[1] << endl;

    return 0;
}