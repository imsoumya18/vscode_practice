// @author Soumya
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();

    if (n2 < n1)
        return false;

    vector<char> st1, st2;

    for (auto i : s1)
        st1.push_back(i);

    sort(st1.begin(), st1.end());

    int right = n1 - 1;

    for (int i = 0; i <= right; i++)
        st2.push_back(s2[i]);

    vector<char> temp(n1);
    partial_sort_copy(begin(st2), end(st2), begin(temp), end(temp));

    if (st1 == temp)
        return true;

    while (right < n2)
    {
        st2.erase(st2.begin());
        right++;
        st2.push_back(s2[right]);

        vector<char> temp(n1);
        partial_sort_copy(begin(st2), end(st2), begin(temp), end(temp));

        if (st1 == temp)
            return true;
    }

    return false;
}

// bool checkInclusion(string s1, string s2)
// {
//     if (s2.size() < s1.size())
//         return false;

//     bool flag = false;

//     vector<int> vct(26, 0);
//     int n = s1.size();

//     for (auto i : s1)
//         vct[i - 'a']++;

//     vector<int> test(26, 0);
//     int left = 0, right = n - 1;

//     for (int i = left; i <= right; i++)
//         test[s2[i] - 'a']++;

//     if (test == vct)
//         return true;

//     while (right < s2.size())
//     {
//         test[vct[left] - 'a']--;
//         left++;
//         right++;
//         test[vct[right] - 'a']++;

//         for (auto p : vct)
//             cout << p << " ";
//         cout << endl;
//         for (auto p : test)
//             cout << p << " ";

//         if (test == vct)
//             return true;
//     }

//     return false;
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1 = "ab", s2 = "ba";

    cout << checkInclusion(s1, s2) << endl;

    return 0;
}