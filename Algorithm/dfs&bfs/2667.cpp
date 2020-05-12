#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int map[25][25];
bool check[25][25];

int bfs (int row, int col)
{
    int cnt = 0;
    queue<pair<int, int>> q;

    check[row][col] = true;
    q.push(make_pair(row, col));

    while (!q.empty())
    {
        cnt++;
        int y = q.front().first, x = q.front().second; q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (map[ny][nx] == 1 && check[ny][nx] == false)
                {
                    check[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    return cnt;
}

int main(void)
{
    cin >> n;
    vector<int> ans;
    memset(check, false, sizeof(check));

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            map[i][j] = s[j] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && check[i][j] == false)
            {
                ans.push_back(bfs(i, j));
            }    
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i: ans)
        cout << i << '\n';
}