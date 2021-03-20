// 4027.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int a[100005], f[100005];
using namespace std;
int main()
{
    int n, t;
    int top = 0;
    a[1] = -1;
    cin >> n;
    for (int i = 1;i <= n;++i)
    {
        cin >> t;
        f[t] = i;
    }
    for (int i = 1;i <= n;++i)
    {
        cin >> t;
        if (f[t] > a[top])
        {
            top++;
            a[top] = f[t];
        }
        else
        {
            int l = 1, r = top, m;
            while (l < r)
            {
                m = (l + r) >> 1;
                if (f[t] > a[m]) l = m + 1;
                else r = m;
            }
            a[l] = f[t];
        }
    }
    cout << top;
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
