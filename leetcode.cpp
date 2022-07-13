// @author Soumya
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string getHint(string secret, string guess)
{
    int bulls = 0, cows = 0, s[10] = {0}, g[10] = {0};

    for (int i = 0; i < secret.length(); i++)
        if (secret[i] == guess[i])
            bulls++;
        else
        {
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }

    for (int i = 0; i < 10; i++)
        cows += min(s[i], g[i]);

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string secret = "1123", guess = "0111";

    cout << getHint(secret, guess) << endl;

    return 0;
}