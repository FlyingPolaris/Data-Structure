// 4016.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

void fun(int arr[], int len);

int themax = 0;
int main()
{
    int N;
    cin >> N;
    int* max;
    max = new int[N];
    for (int i = 0;i < N;i++)
    {
        themax = 0;
        int num[10];
        cin >> num[0] >> num[1] >> num[2] >> num[3];
        fun(num, 4);
        max[i] = themax;
    }
    for (int i = 0; i < N; ++i)
        cout << max[i] << endl;
    return 0;
  
}

void fun(int arr[], int len)
{
    if (len == 1)
    {
       if (arr[0] <= 24 && arr[0] > themax) themax = arr[0];
       return;
    }
    
    else
    {
        int temp[10];
        for(int p = 0;p < 4;p++)
        {
            for (int n = 0;n < len;n++)
            {
                for (int m = n + 1;m < len;m++)
                {
                    int i = 0,j = 0;
                    while (i < len)
                    {
                        if (i != m && i != n)
                        {
                            temp[j] = arr[i];
                            j++;
                        }
                        i++;
                    }

                    if (p == 0) temp[len - 2] = arr[m] + arr[n];
                    else if (p == 1) temp[len - 2] = abs(arr[m] - arr[n]);
                    else if (p == 2) temp[len - 2] = arr[m] * arr[n];
                    else if (p == 3)
                    {
                        if (arr[n] != 0 && arr[m] % arr[n] == 0)  temp[len - 2] = arr[m] / arr[n];
                        else if (arr[m] != 0 && arr[n] % arr[m] == 0) temp[len - 2] = arr[n] / arr[m];
                        else return;
                    }

                    fun(temp, len - 1);
                }
            }
        }
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
