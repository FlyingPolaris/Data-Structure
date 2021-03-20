// 4075.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;
char a[1000002], b[100002];
int thenext[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int j = -1;
    int i = 0;
    thenext[0] = -1;
    while (i < strlen(b))
    {
        if (j == -1 || b[i] == b[j])
        {
            i++;
            j++;
            thenext[i] = j;
        }
        else j = thenext[j];
    }

    int p = 0, q = 0;
    while (p < strlen(a) && (q < strlen(b) || q == -1))
    {
        if (q == -1 || a[p] == b[q])
        {
            p++;
            q++;
        }
        else q = thenext[q];
    }
    cout << p - q;
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
