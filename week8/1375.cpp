// 1375.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const int MAXDEPTH = 16;
int n, m, root, num;
int f[40001][17], depth[40001];
int head[40001], nex[40001], point[40001];

void swp(int& a, int& b)
{
	int tmp = b;
	b = a;
	a = tmp;
}

void add(int u, int v) 
{
	num++;
	point[num] = v;
	nex[num] = head[u];
	head[u] = num;
}

void dfs(int p, int father)
{
	depth[p] = depth[father] + 1;
	f[p][0] = father;
	for (int i = 1; i <= MAXDEPTH; i++)
		f[p][i] = f[f[p][i - 1]][i - 1];
	for (int i = head[p]; i != 0; i = nex[i])
		dfs(point[i], p);
}

int LCA(int x, int y)
{
	if (depth[x] > depth[y]) swp(x, y);
	if (x == y) return x;
	for (int i = MAXDEPTH; i >= 0; i--)
		if (depth[f[y][i]] >= depth[x]) y = f[y][i];
	if (x == y) return x;
	for (int i = MAXDEPTH; i >= 0; i--)
		if (f[x][i] != f[y][i]) 
		{
			x = f[x][i];
			y = f[y][i];
		}
	return f[x][0];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int father, son;
		cin >> son >> father;
		if (father == -1) {
			root = son;
			continue;
		}
		add(father, son);
	}

	dfs(root, root);

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int lca = LCA(x, y);
		if (lca == x) cout << 1 << '\n';
		else if (lca == y) cout << 2 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
