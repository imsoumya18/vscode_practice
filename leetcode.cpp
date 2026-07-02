// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <sstream>
#include <set>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<string>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int n = beginWord.size();
    set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty())
    {
        string currWord = q.front().first;
        int ladder = q.front().second;
        q.pop();

        for (int pos = 0; pos < n; pos++)
            for (char c = 'a'; c <= 'z'; c++)
                if (c != currWord[pos])
                {
                    string nextWord = currWord;
                    nextWord[pos] = c;

                    if (st.count(nextWord))
                    {
                        if (nextWord == endWord)
                            return ladder + 1;

                        q.push({nextWord, ladder + 1});
                        st.erase(nextWord);
                    }
                }
    }

    return 0;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto p : prerequisites)
    {
        adj[p[0]].push_back(p[1]);
        indegree[p[1]]++;
    }

    queue<int> q;
    vector<int> vct;

    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        vct.push_back(node);
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return !(vct.size() == numCourses);
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
        for (auto it : graph[i])
        {
            adj[it].push_back(i);
            indegree[i]++;
        }

    queue<int> q;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> vct;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vct.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    sort(vct.begin(), vct.end());

    return vct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    for (auto it : eventualSafeNodes(graph))
        cout << it << " ";

    return 0;
}