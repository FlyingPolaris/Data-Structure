
// 4118.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;

int m;
char s1[27], s2[27];
long long ans = 1;
long long C(long long m,long long n)
{
    if (!m) return 1;
    long long tmp1 = 1, tmp2 = 1;
    for (int i = 1;i <= m;++i)
    {
        tmp1 *= i;
    }
    for (int i = 0;i < m;++i)
    {
        tmp2 *= n - i;
    }
    return tmp2 / tmp1;
}

void f(int fleft, int fright, int eleft, int eright)
{
    int root = fleft + 1;
    int childnum = 0;
    while (root <= fright)
    {
        int len;
        for (int i = eleft;i <= eright;++i)
        {
            if (s2[i] == s1[root])
            {
                len = i - eleft + 1;
                break;
            }
        }
        f(root, root + len - 1, eleft, eleft + len - 1);
        childnum++;
        root += len;
        eleft += len;
    }
    ans *= C(childnum, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(s1, 0, sizeof(char) * 27);
    memset(s2, 0, sizeof(char) * 27);
    cin >> m >> s1 >> s2;
    f(0, strlen(s1) - 1, 0, strlen(s2) - 1);
    cout << ans;
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
