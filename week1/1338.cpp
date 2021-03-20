// 1338.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void sorts(long long arr[], long long start, long long last);
int main()
{
    long long n,summax = 0,summin = 0;
    cin >> n;
    long long* a, * b;
    a = new long long[n];
    b = new long long[n];
    for (long long i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for (long long i = 0;i < n;i++)
    {
        cin >> b[i];
    }
    sorts(a, 0, n - 1);
    sorts(b, 0, n - 1);
    for (long long i = 0;i < n;i++)
    {
        summax += a[i] * b[i];
    }
    for (long long i = 0;i < n / 2;i++)
    {
        long long temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    for (long long i = 0;i < n;i++)
    {
        summin += a[i] * b[i];
    }
    cout << summax <<' '<< summin;
    delete[]a;
    delete[]b;
    return 0;
}

void sorts(long long arr[], long long start, long long last)
{
    long long i = start;
    long long j = last;
    long long temp = arr[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j && arr[j] >= temp) j--;
            if (i < j)
            {
                arr[i] = arr[j];
                i++;
            }
            while (i < j && arr[i] < temp)i++;
            if (i < j)
            {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = temp;
        sorts(arr, start, i - 1);
        sorts(arr, i + 1, last);
    }
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
