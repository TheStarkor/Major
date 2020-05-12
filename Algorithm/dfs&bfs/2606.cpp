#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> computer[101];
bool check[101];

void bfs(void)
{
    queue<int> q;

    check[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        
        for (int next: computer[node])
        {
            if (check[next] == false)
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int node, edge, vertex;
    cin >> node; cin >> edge;
    memset(check, false, sizeof(check));

    for (int i = 0; i < edge; i++)
    {
        int from, to;
        cin >> from >> to;

        computer[from].push_back(to);
        computer[to].push_back(from);
    }

    bfs();

    for (int i = 2; i <= node; i++)
    {
        if (check[i] == true)
            ans++;
    }

    cout << ans;
}