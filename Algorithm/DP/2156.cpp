#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main(void)
{
    int n, dp[10001], cup[10001];
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> cup[i];

    dp[1] = cup[1];
    dp[2] = cup[1] + cup[2];
    dp[3] = max(max(cup[1]+cup[2], cup[1]+cup[3]), cup[2]+cup[3]);

    for (int i = 4; i <= n; i++)
        dp[i] = max(max(dp[i-1], dp[i-2]+cup[i]), dp[i-3]+cup[i-1]+cup[i]);

    cout << dp[n];
}
