// 1550.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    int n, x, i = 0,water = 0;
    cin >> n;
    int height[1005];
    char ch;
    for (int j = 0;j < n;j++)
    {
        cin >> ch >> height[j];
    }
    int max = height[0];    
    for (int j = 0;j < n;j++)
    {
        if (height[j] > max) max = height[j];
    }
    for (int ruler = max;ruler > 0;ruler--)
    {
        int left = 0, right = n - 1;
        while (height[left] < ruler)
        {
            left++;
            if (left > n - 1) break;
        }
        while (height[right] < ruler)
        {
            right--;
            if (right < 0) break;
        }
        if (left > n - 1 || right < 0 || left == right) continue;
        else  water += right - left - 1;
        for (int j = left + 1;j < right;j++)
        {
            if (height[j] >= ruler) water--;
        }
    }
    cout << water;
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
