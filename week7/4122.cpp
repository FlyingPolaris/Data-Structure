// 4122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e6 + 7;
int n, m, l, r;
int a[1002], b[100005];
bool vis[2*MOD],want[2*MOD];
int times[2*MOD];
int gethash(char* a)
{
    int len = strlen(a);
    long long ans = 0;
    for (int i = 0;i < len;++i)
    {
        ans *= 31;
        ans += a[i] - 'a';
        ans %= MOD;
    }
    return ans % MOD;
}
int main()
{
    int x1 = 0, x2 = 0;
    cin >> n;
    char tmp[15];
    for (int i = 1;i <= n;++i)
    {
        cin >> tmp;
        a[i] = gethash(tmp);
        want[a[i]] = 1;
    }
    cin >> m;
    for (int i = 1;i <= m;++i)
    {
        cin >> tmp;
        b[i] = gethash(tmp);
        if (want[b[i]] && !vis[b[i]])
        {
            vis[b[i]] = 1;
            x1++;
        }
    }
    if (x1 == 0)
    {
        cout << 0 << '\n' << 0;
        return 0;
    }
    cout << x1 << '\n';
    l = r = m;    
    int num = x1;
    x2 = m;
    memset(times, 0, sizeof(times));
    while (1)
    {
        if (num)
        {
            if (l == 0) break;
            if (vis[b[l]])
            {
                if (!times[b[l]])
                {
                    num--;
                }
                times[b[l]]++;
            }
            l--;
        }
        else
        {
            while (!vis[b[r]]) r--;
            x2 = (x2 < r - l) ? x2 : r - l;
            if (times[b[r]])
            {
                if (times[b[r]] == 1) num++;
            }
            times[b[r]]--;
            r--;
        }
    }
    cout << x2;
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
