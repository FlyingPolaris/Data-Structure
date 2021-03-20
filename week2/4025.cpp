// 4025.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void QuickSort(long long arr[], long long low, long long high);

int main()
{
    long long M, N;
    cin >> M >> N;
    long long* arr;
    arr = new long long[M * N];
    for (long long i = 0;i < M * N;i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, M * N - 1);
    long long water;
    cin >> water;

    long long num = 0;
    double level = arr[0];
    while (water > 0)
    {
        if (num + 1 >= M * N)
        {
            level += (double)water / (double)(num + 1);
            water = 0;
        }
        else if (water - (arr[num + 1] - arr[num]) * (num + 1) > 0)
        {
            water -= (arr[num + 1] - arr[num]) * (num + 1);
            level += arr[num + 1] - arr[num];
            num++;
        }
        else
        {
            level += (double)water /(double) (num + 1);
            water = 0;
        }
    }
    printf("%.2f", level);
    cout << endl;
    printf("%.2f", (double)(num + 1) / (double)(M * N) * 100);
    delete[] arr;
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
