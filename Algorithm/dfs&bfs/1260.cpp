#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
    check[node] = true;
    cout << node << " ";
    for (int next: a[node])
    {
        if (check[next] == false) 
            dfs(next);
    }
}

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int next: a[node])
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

	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	for (int i = 1; i < n; i++)
		sort (a[i].begin(), a[i].end());

	memset(check, false, sizeof(check));
	dfs(v);
	cout << '\n';
	memset(check, false, sizeof(check));
	bfs(v);
}