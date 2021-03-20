﻿// 4053.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int n;
int prime[] = { 2,3,5,7,11,13,17,19,23,29,31 };
int num[22];
bool mark[22];
bool isprime(int n)
{
    for (int i = 0;i < 11;++i)
    {
        if (n == prime[i]) return true;
    }
    return false;
}

void dfs(int step)
{
    if (step == n)
    {
        if (isprime(num[1] + num[n]))
        {
            for (int i = 1;i <= n;++i)
            {
                cout << num[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    else
    {
        for (int i = 2;i <= n;++i)
        {
            if (mark[i] == true) continue;
            num[step + 1] = i;
            mark[i] = true;
            if (isprime(num[step + 1] + num[step])) dfs(step + 1);
            mark[i] = false;
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;++i)
        mark[i] = false;
    num[1] = mark[1] = 1;
    if (n > 1 && n % 2)
    {
        cout << "None";
        return 0;
    }
    dfs(1);
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
