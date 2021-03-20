// 4206.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, m;
int a[2005][2005] = { 0 };
//char b[2002][2002];
bool isPrime[1002];
int f(int l)
{
    int ans = 0;
    int N = ceil((double)n / l) * l;
    int M = ceil((double)m / l) * l;
    for (int i = 0;i < N;i += l)
    {
        for (int j = 0;j < M;j += l)
        {
            int black = a[i + l][j + l] - a[i][j + l] - a[i + l][j] + a[i][j];
            ans += ((black < l * l - black) ? black : (l * l - black));
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 2; i <= 1000; i++)
        isPrime[i] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (isPrime[i])
            for (int j = 2 * i; j <= 1000; j += i)
                isPrime[j] = 0;
    }
    int k[200];
    int z = 0;
    for (int i = 2;i <= 1000;++i)
    {
        if (isPrime[i])
        {
            k[z] = i;
            ++z;
        }
    }

    char c;
    cin.get();
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= m;++j)
        {
            c = cin.get();
            a[i][j] = c - '0';
        }
        cin.get();
    }

    for (int i = 1;i <= 2000;++i)
    {
        for (int j = 1;j <= 2000;++j)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int change = 2 * n * m;
    for (int p = 0;k[p] <= (n > m ? n : m);++p)
    {
        int tmp = 0;
        tmp = f(k[p]);
        if (tmp < change) change = tmp;
    }
    cout << change;
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
