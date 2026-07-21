// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void solve(int start, string &s, unordered_set<string> &dictionary, unordered_map<int, vector<string>> &dp, string curr, vector<string> &vct)
{
    if (start >= s.size())
    {
        vct.push_back(curr);
        return;
    }

    if (dp.find(start)!=dp.end())
        return;

    for (int len = 1; len <= s.size() - start; len++)
        if (dictionary.count(s.substr(start, len)))
        {
            string newCurr = curr;
            if (newCurr != "")
                newCurr += " ";
            newCurr += s.substr(start, len);

            solve(start + len, s, dictionary, dp, newCurr, vct);
        }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
    vector<string> vct;
    string curr = "";
    unordered_map<int, vector<string>> dp;

    solve(0, s, dictionary, dp, curr, vct);

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string x = "1234";

    cout << x.substr(2) << endl;

    return 0;
}