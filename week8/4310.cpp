// 4310.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const int MAXDEPTH = 18;
int n, m, num = 0, len = 0;
int f[100001][19], depth[100001], val[100001];
int head[100001], nex[100001], from[100001], point[100001], dis[100001];
bool isnotroot[100001];

char op[8];
void swp(int& a, int& b)
{
	int tmp = b;
	b = a;
	a = tmp;
}

void add(int u, int v, int value)
{
	num++;
	point[num] = v;
	from[num] = u;
	val[num] = value;
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
	{
		dis[point[i]] = dis[p] + val[i];
		dfs(point[i], p);
	}
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

int quary(int a, int b, int k)
{
	int lca = LCA(a, b);
	if (depth[a] - depth[lca] + 1 >= k)
	{
		int ans = depth[a] - k + 1;
		for (int i = MAXDEPTH; i >= 0; i--)
			if (depth[f[a][i]] >= ans) a = f[a][i];
		return a;
	}
	else
	{
		int ans = depth[lca] * 2 + k - depth[a] - 1;
		for (int i = MAXDEPTH; i >= 0; i--)
			if (depth[f[b][i]] >= ans) b = f[b][i];
		return b;
	}
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

	cin >> n >> m;
	int father, son, valu;
	for (int i = 1;i < n;++i)
	{
		cin >> father >> son >> valu;
		isnotroot[son] = true;
		add(father, son, valu);
	}
	int root;
	for (int i = 1;i <= n;++i)
	{
		if (!isnotroot[i])
		{
			root = i;
			break;
		}
	}

	dfs(root, root);
	int a, b, c;
	for (int i = 0;i < m;++i)
	{
		cin >> op;
		if (op[0] == 'D')
		{
			cin >> a >> b;
			cout << dis[a] + dis[b] - dis[LCA(a, b)] * 2 ;
			if (i != m - 1) cout << '\n';
		}
		else if(op[0] == 'K')
		{
			cin >> a >> b >> c;
			cout << quary(a, b, c);
			if (i != m - 1) cout << '\n';
		}
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
