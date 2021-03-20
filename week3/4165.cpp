
// 4165.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, * A, * B,* num;
    cin >> N;
    A = new int[N];
    B = new int[N];
    num = new int[N];

    for (int i = 0;i < N;++i) cin >> A[i];
    for (int i = 0;i < N;++i) cin >> B[i];
    for (int i = 0;i < N;++i) num[i] = A[i] - B[i];
    long long sum = 0;
    //if (N == 1)
    //{
    //    cout << num[0];
    //    return 0;
    //}
    for (int i = 0;i < N;i++)
    {
        if (num[i] > 0)
        {
            sum += num[i];
            while (num[i + 1] > 0 && i < N - 1)
            {
                sum += (num[i + 1] > num[i] ? num[i + 1] - num[i] : 0);
                i++;
            }
        }
        else if (num[i] < 0) 
        {
            sum -= num[i];
            while (num[i + 1] < 0 && i < N - 1)
            {
                sum += (num[i + 1] < num[i] ? num[i] - num[i + 1] : 0);
                i++;
            }
        }
    }
    cout << sum;
    delete[]A;
    delete[]B;
    delete[]num;
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
