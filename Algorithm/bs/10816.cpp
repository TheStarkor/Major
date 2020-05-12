#include <iostream>
#include <cstring>

using namespace std;

int num[500000 * 2 + 1];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    memset(num, 0, sizeof(num));

    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        num[temp + 500000]++;
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp; cin >> temp;
        cout << num[temp + 500000] << ' ';
    }
}