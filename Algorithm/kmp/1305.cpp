#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> processing(string p)
{
    int j = 0, m = p.size();
    vector<int> pi(m, 0);
    
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        
        if (p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

int main(void)
{
    int l; cin >> l;
    string p; cin >> p;

    vector<int> pi = processing(p);

    cout << l - pi[l-1];
}