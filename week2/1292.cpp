// 1292.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int changtime(int len)
{
    if (len == 0 || len == 1) return 0;
    else if (len == 2) return 1;
    else return 2;
}

int changtimes(int len)
{
    return len - 1;
}



//int shouldbe[1000001];

int main()
{
    int n;
    while (cin>>n)
    {
        int ans1 = 0, ans2 = 0;
        int* num;
        num = new int[n + 1];
        bool* flag;
        for (int i = 1;i <= n;++i) scanf("%d", &num[i]);
        flag = new bool[n + 1];
        for (int i = 1;i <= n;i++) flag[i] = false;
        //for (int i = 0;i < n;++i) shouldbe[num[i]] = i;
        for (int i = 1;i <= n;++i)
        {
            if (!flag[i])
            {
                int looplen = 1;
                flag[i] = true;
                int p = num[i];
                while (!flag[p])
                {
                    flag[p] = true;
                    p = num[p];
                    looplen++;
                }
                ans1 += changtimes(looplen);
                if (changtime(looplen) > ans2) ans2 = changtime(looplen);
            }
        }
        cout << ans1 << endl;
        cout << ans2 << endl;
        delete[]num;
        delete[]flag;
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
