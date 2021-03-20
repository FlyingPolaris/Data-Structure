// 4240.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
using namespace std;
int a[4000005] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, p, tmp, min = 0, max = 0;
    cin >> s;
    //scanf("%d", &s);
    for (int i = 0;i < s;++i)
    {
        cin >> tmp;
        //scanf("%d", &tmp);
        if (tmp < min) min = tmp;
        if (tmp > max) max = tmp;
        a[tmp + 2000000] = 1;
    }
    cin >> p;
    //scanf("%d", &p);
    while (p--)
    {
        int x;
        cin >> x;
        //scanf("%d", &x);
        switch (x)
        {
        case 1:
            cin >> tmp;
            if (tmp < min) min = tmp;
            if (tmp > max) max = tmp;
            a[tmp + 2000000] = 1;
            break;
        case 0:
            cin >> tmp;
            //if (tmp < min) min = tmp;
            //if (tmp > max) max = tmp;
            a[tmp + 2000000] = 0;
            break;
        }
    }

    for (int i = min + 2000000;i <= max + 2000000;++i)
    {
       // while (true)
       // {
            //cout << i - 2000000;
            //cout << " ";
            if (a[i])
            {
                cout << i - 2000000;
                cout << " ";
                //printf("%d", i - 2000000);
                //printf(" ");
                //a[i]--;
            }
       //     else break;
       //
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
