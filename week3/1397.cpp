// 1397.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <cmath>
using namespace std;

void QuickSort(long long arr[], long long low, long long high);
long long num[1000001];

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 0;i < n;i++) scanf("%d",&num[i]);
    QuickSort(num, 0, n - 1);
    for (long long i = 0;i < n - 1;i++)
    {
        sum += (num[i + 1] - num[i]) * (n - 1 - i) * (i + 1);
        sum %= 1000000007;
    }
    printf("%d",sum);
    return 0;
}

void QuickSort(long long arr[], long long low, long long high)
{
    long long i, j, temp;
    i = low;
    j = high;
    if (low < high)
    {
        temp = arr[low];
        while (i != j)
        {
            while (j > i&& arr[j] >= temp)
            {
                --j;
            }
            if (i < j)
            {
                arr[i] = arr[j];
                ++i;
            }

            while (i < j && arr[i] < temp)
            {
                ++i;
            }
            if (i < j)
            {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i] = temp;
        QuickSort(arr, low, i - 1);
        QuickSort(arr, i + 1, high);
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
