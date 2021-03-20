// 4011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;

class hint
{
private:
    long long n[10];
    long long len;
    long long base;
public:
    hint(long long x = 0)
    {
        for (int i = 0;i < 10;++i) n[i] = 0;
        n[0] = x;
        len = 1;
        base = 1e11;
    }

    hint& operator=(const hint& rhs)
    {
        if (this != &rhs)
        {
            for (long long i = 0;i < 10;++i)
            {
                n[i] = rhs.n[i];
            }
            len = rhs.len;
            base = rhs.base;
        }

        return *this;
    }

    hint operator+(const hint& rhs) const
    {
        hint ans;
        long long in = 0;

        for (long long i = 0;i < 10 && (in != 0 || rhs.n[i] != 0 || n[i] != 0);++i)
        {
            ans.n[i] = n[i] + rhs.n[i] + in;
            in = ans.n[i] / base;
            ans.n[i] %= base;
        }

        return ans;
    }

    hint operator+=(const hint& rhs)
    {
        *this = *this + rhs;
        return *this;
    }
    void print()
    {
        long long t = 9;
        while (!n[t]) t--;
        cout << n[t];
        t--;
        while (t >= 0)
        {
            cout << n[t];
            t--;
        }
    }
};





int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    hint dp[55][55];

    long long h, k;
    cin >> k >> h;
    for (long long i = 0;i < k;++i) dp[1][i] = k - i;
    for (long long i = 2;i < h;++i)
    {
        for (long long j = 0;j < k;++j)
        {
            for (long long t = 0;t < k - j;++t)
            {
                dp[i][j] += dp[i - 1][t];
            }
        }
    }
    dp[h - 1][0].print();
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
