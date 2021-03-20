// 1348.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
using namespace std;

int boy[1000003], girl[1000003];
long long songtime[100003];

void QuickSort(int arr[], int low, int high)
{
    int i, j, temp;
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N;
    for (int i = 0;i < N;++i)
    {
        cin >> songtime[i];
    }
    cin >> M;
    int sex, boynum = 0, girlnum = 0;
    int boyend, girlend;
    boyend = girlend = 1;
    while (M--)
    {
        cin >> sex;
        if (sex == 1)
        {
            boynum++;
            cin >> boy[boynum];
        }
        else if (sex == 2)
        {
            girlnum++;
            cin >> girl[girlnum];
        }
    }

    QuickSort(girl, 1, girlnum);
    QuickSort(boy, 1, boynum);

    long long nowtime = 0;
    long long boywaittime = 0, girlwaittime = 0;
    for (int i = 0;i < N;++i)
    {
        //while (boyend != boynum + 1 && girlend != girlnum + 1 && girl[girlend] == 0 && boy[boyend] == 0)
        //{
        //    boyend++;
        //    girlend++;
        //}

        if (i != N - 1)
        {
            while (boyend != boynum + 1 && girlend != girlnum + 1 && girl[girlend] <= nowtime && boy[boyend] <= nowtime)
            {
                boywaittime += nowtime - boy[boyend++];
                girlwaittime += nowtime - girl[girlend++];
            }
            nowtime += songtime[i];
        }
        else
        {
            while(boyend != boynum + 1)
                boywaittime += nowtime - boy[boyend++];
            while(girlend != girlnum + 1)
                girlwaittime += nowtime - girl[girlend++];
            nowtime += songtime[i];
        }
    }
    printf("%.2f %.2f", (double)boywaittime / boynum, (double)girlwaittime / girlnum);
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
