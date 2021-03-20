// 4009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    char encryption[105], open[105];
    scanf("%s", open);
    scanf("%s", encryption);
    int len = strlen(open);
    int k[20];
    int flag = 0;
    for (int i = 2;i < len;++i)
    {
        
        if (len % i == 0)
        {
            k[flag] = len / i;
            flag++;
        }
    }
    for (int i = 0;i < flag;i++)
    {
        /*cout << k[i] << endl;*/
    }
    bool solution = false;
    /*cout << len << endl;*/
    for (int i = 0;i < flag;i++)
    {
        /*cout << i << ' ' << k[i] << endl;
        cout << endl;*/
        int div = len / k[i];
        char str[105];
        for (int j = 0;j < len;j++)
        {
            int p, q;
            
            p = j / k[i];
            q = j % k[i];
           /* cout << p << ' ' << q << ' ' << div * q + p << endl;*/
            str[div * q + p] = open[j];
        }
        str[len] = '\0';

       /* cout << k[i] << ' ' << div << endl;*/
        if (!strcmp(encryption, str))
        {
            cout << k[i];
            solution = true;
            break;
        }
        /*cout << endl;*/
    }
    if (!solution) cout << "No Solution";

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
