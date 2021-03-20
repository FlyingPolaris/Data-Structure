// 1329.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
//#include <cmath>
using namespace std;

int pow2(int a)
{
    if (a == 0) return 1;
    else
    {
        int temp = 1;
        for (int i = 0;i < a - 1;i++)
        {
            temp *= 2;
        }
        return temp;
    }
}
int main()
{
    int t;
    cin >> t;
    cin.get();
    for (int p = 0;p < t;p++)
    {
        int m, n;
        cin.get();
        cin >> n >> m;
        int* peo1, * peo2;
        peo1 = new int[m];
        peo2 = new int[m];
        char x = 0;
        
        for (int i = 0;i < m;i++)
        {
            peo1[i] = peo2[i] = 0;
            x = 0;
            int temp;
            while (x != '\n')
            {
                cin >> temp;
                if (temp > 0) peo1[i] += pow2(temp);
                else peo2[i] += pow2(-temp);
                x = cin.get();
            }         
        }

        //for (int i = 0;i < m;i++)
        //{
        //    cout << "want" << ' ' << peo1[i] << ' ' << "diswant" << ' ' << peo2[i] << endl;
        //}

        bool flag = true;
        for (int i = 1;i <= pow2(n + 1) - 1;i++)
        {
            flag = true;
            for (int j = 0;j < m;j++)
            {
                if ((i & peo1[j]) == 0 && (~i & peo2[j]) == 0) flag = false;
            }
            //cout << i << ' ' << flag;
            if (flag)
            {
                cout << "Bingo!" << endl; break;
            }
        }
        if (!flag) cout << "Sigh..." << endl;
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
