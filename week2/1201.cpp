// 1201.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int t = 0;t < N;t++)
    {
        long long n;
        cin >> n;
        int num = n % 100;
        long long m = n / 100, p = m;
        int len = 0;
        while (p > 0)
        {
            p /= 10;
            len++;
        }

        int* bignum;
        bignum = new int[len + 10];
        for (int i = 0;i < len;i++)
        {
            bignum[len - i - 1] = m % 10;
            m /= 10;
        }
        for (int i = 0;i < len;i++)
        {
            int temp = bignum[i];
            for (int j = 0;j < num;j++)
            {
                bignum[i] += temp;
                if (bignum[i] >= 10) bignum[i] -= 10;
            }
        }
        /*cout << len << endl;*/
        //for (int i = 0;i < len;i++) cout << bignum[i]<<endl;

        int onesum = 0, tensum = 0;
        for (int i = 1;i <= num;i++)
        {
            onesum += i % 10;
            tensum += i / 10;
            if (onesum >= 10) onesum -= 10;
            if (tensum >= 10) tensum -= 10;
        }
        if (len == 0) cout << onesum + tensum * 10 << endl;
        else
        {
            bignum[len] = tensum;
            bignum[len + 1] = onesum;
            bool iszero = true;
            for (int i = 0;i < len + 2;i++)
            {
                if (bignum[i] != 0) iszero = false;
                if (!iszero) cout << bignum[i];
            }
            if (iszero) cout << 0;
            cout << endl;
        }
    }
    

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
