#include <iostream>
#include <cstring>

using namespace std;

bool check[41];
int cnt[41][2];

void fibo(int n)
{
    if (check[n])
        return;
    check[n] = true;

    if (n == 0)
    {
        cnt[n][0]++;
        return;
    }
    if (n == 1)
    {
        cnt[n][1]++;
        return;
    }

    fibo(n-1); fibo(n-2);

    cnt[n][0] = cnt[n-1][0] + cnt[n-2][0];
    cnt[n][1] = cnt[n-1][1] + cnt[n-2][1];
}

int main(void)
{
    int t; cin >> t;
    memset(check, false, sizeof(check));
    memset(cnt, 0, sizeof(cnt));

    while (t--)
    {
        int temp; cin >> temp;
        fibo(temp);
        cout << cnt[temp][0] << ' ' << cnt[temp][1] << '\n';
    }
}