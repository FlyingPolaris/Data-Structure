// 1566.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;

int n;

int map[30][30];

int MAX = 1e8 + 7;

int prim()
{
    int ans = 0;
    bool flag[30];
    memset(flag, 0, sizeof(flag));
    int lowcost[30];
    for (int i = 1;i <= n;++i)
    {
        lowcost[i] = MAX;
    }

    int min;
    int point;
    int tmp = 1;

    for (int i = 1;i < n;++i)
    {
        min = MAX;
        for (int j = 2;j <= n;++j)
        {
            if (!flag[j] && lowcost[j] > map[tmp][j])
            {
                lowcost[j] = map[tmp][j];
            }
            if (!flag[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                point = j;
            }
                
        }
        tmp = point;
        flag[tmp] = true;
        ans += min;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    char village;
    char target;
    int t;
    int cost;

    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            map[i][j] = map[j][i] = MAX;
        }
    }

    for (int i = 1;i < n;++i)
    {
        cin >> village >> t;
        for (int j = 1;j <= t;++j)
        {
            cin >> target >> cost;
            map[village - 'A' + 1][target - 'A' + 1] = map[target - 'A' + 1][village - 'A' + 1] = cost;
        }
    }

    cout << prim() << endl;
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
