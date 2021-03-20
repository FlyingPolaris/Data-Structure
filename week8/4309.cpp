// 4309.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

int dp[200001][19];
int num[200001];
int n, m;

int log2(int a)
{
    return ((int)(log((double)a) / log(2.0)));
}

int maxnum(int a, int b)
{
    return (a < b) ? b : a;
}

void RMQ()
{
    for (int i = 1;i <= n;++i) dp[i][0] = num[i];

    int k = log2(n);
    for (int j = 1;j <= k;++j)
    {
        for (int i = 1;i <= n;++i)
        {
            dp[i][j] = maxnum(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
           
    }
}

int quary(int l, int r)
{
    int k = log2(r - l + 1);
    return maxnum(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1;i <= n;++i) cin >> num[i];


    RMQ();

    cin >> m;
    int x, y;
    for (int i = 0;i < m;++i)
    {
        cin >> x >> y;
        cout << quary(x, y);
        if (i < m - 1) cout << '\n';
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
