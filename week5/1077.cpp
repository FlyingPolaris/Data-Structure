// 1077.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int w[30];
int f[30][30];
int root[30][30];

void print(int l, int r)
{
    if (l > r) return;
    cout << root[l][r] << ' ';
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;++i) cin >> w[i];
    for (int i = 1;i <= n;++i)
    {
        f[i][i] = w[i];
        root[i][i] = i;
    }
    for (int m = 1;m < n;++m)
    {
        for (int l = 1;l + m <= n;++l)
        {
            int r = l + m;
            for (int t = l;t <= r;++t)
            {
                int lw, rw;
                if (t == l) lw = 1;
                else lw = f[l][t - 1];
                if (t == r) rw = 1;
                else rw = f[t + 1][r];
                if (lw * rw + w[t] > f[l][r])
                {
                    f[l][r] = lw * rw + w[t];
                    root[l][r] = t;
                }
            }            
        }
    }

    cout << f[1][n] << '\n';
    print(1, n);
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
