#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long> &a,
	vector<long long> &tree,
	int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(vector<long long> &tree,
	int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long> &tree,
	int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end)
		return;

	tree[node] = tree[node] + diff;

	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(void)
{
	int n, m, k; cin >> n >> m >> k;
	vector<long long> a(n);
	vector<long long> tree(1 << ((int)ceil(log2(n)) + 1));
	m += k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 1, 0, n - 1);

	while (m--)
	{
		int t1;
		cin >> t1;

		if (t1 == 1)
		{
			int t2;
			long long t3;
			cin >> t2 >> t3;
			t2--;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, 1, 0, n - 1, t2, diff);
		}
		else if (t1 == 2)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
}