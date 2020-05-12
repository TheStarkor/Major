#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> num(n);
    vector<int>::iterator it;

    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        num[i] = temp;
    }

    sort(num.begin(), num.end());

    int m; cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int temp; cin >> temp;
        it = lower_bound(num.begin(), num.end(), temp);
        
        if (*it == temp)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}