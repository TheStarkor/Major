#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int file[501];
long long sum[501];
long long dp[501][501];

long long go(int i, int j)
{
    if (i == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i; k < j; k++)
    {
        long long temp = go(i, k) + go(k+1, j) + sum[j] - sum[i-1];
        if (dp[i][j] == -1 || temp < dp[i][j])
            dp[i][j] = temp;
    }
    
    return dp[i][j];
}

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int k; cin >> k;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < k; i++)
            cin >> file[i];

        sum[0] = file[0];
        for (int i = 0; i < k; i++)
            sum[i] = sum[i-1] + file[i];

        cout << go(0, k-1) << '\n';
    }
}