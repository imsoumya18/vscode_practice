// @author Soumya
#include <iostream>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << arr[0];

    return 0;
}