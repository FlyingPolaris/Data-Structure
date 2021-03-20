// 1360.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void QuickSort(int begin[],int end[], int low, int high);

int main()
{
    int n;
    cin >> n;
    int *arrbegin, *arrend;
    arrbegin = new int[n + 1];
    arrend = new int[n + 1];
    for (int i = 0;i < n;i++)
    {
        cin >> arrbegin[i] >> arrend[i];
    }
    QuickSort(arrbegin, arrend, 0, n - 1);

    //for (int i = 0;i < n;i++)
    //{
    //    cout << arrbegin[i] << ' ' << arrend[i] << endl;
    //}
    int end = arrend[0];
    int flag = 1;
    for (int i = 1;i < n;i++)
    {
        if (arrbegin[i] >= end)
        {
            end = arrend[i];
            flag++;
        }
    }
    cout << flag;
    delete[]arrbegin;
    delete[]arrend;
    return 0;
}

void QuickSort(int begin[], int end[], int low, int high)
{
    int i, j;
    int temp, ttemp;
    i = low;
    j = high;
    if (low < high)
    {
        temp = end[low];
        ttemp = begin[low];
        while (i != j)
        {
            while (j > i&& end[j] >= temp)
            {
                --j;
            }
            if (i < j)
            {
                end[i] = end[j];
                begin[i] = begin[j];
                ++i;
            }

            while (i < j && end[i] < temp)
            {
                ++i;
            }
            if (i < j)
            {
                end[j] = end[i];
                begin[j] = begin[i];
                --j;
            }
        }
        end[i] = temp;
        begin[i] = ttemp;
        QuickSort(begin , end , low, i - 1);
        QuickSort(begin, end , i + 1, high);
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

