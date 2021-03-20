// 1049.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct stop
{
    int a[1002];
    int top;
};
int main()
{
    stop s;
    int t, m, n;
    int f[1002];
    int in, out;
    cin >> t;
    while (t--)
    {
        s.top = -1;
        bool flag = false;
        cin >> n >> m;
        for (int i = 0;i < n;++i) cin >> f[i];
        in = out = 0;
        while (out < n)
        {
            if (in == f[out])
            {
                in++;
                out++;
                goto GOOUT;
            }
            if (s.top == m)
            {
                flag = false;
                break;
            }
            s.a[++s.top] = in++;
            GOOUT:
            while (s.a[s.top] == f[out] && s.top != -1)
            {
                s.top--;
                out++;
            }
        }
        if (s.top == -1) flag = true;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
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
