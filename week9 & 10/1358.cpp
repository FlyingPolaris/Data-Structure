// 1358.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int n;
int head[20005], nex[20005], ans[20005], point[20005], childnum[20005];
int tot = 0;
int num = 0;
bool visited[20005];

void addedge(int u,int v)
{
    tot++;
    point[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;
}

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

void dfs(int p)
{
    bool flag = true;
    visited[p] = true;
    for (int i = head[p]; i != 0; i = nex[i])
    {
        if (!visited[point[i]])
        {
            dfs(point[i]);
            if (childnum[point[i]] > n >> 1) flag = false;
            childnum[p] += childnum[point[i]];
        }
    }
    if (n - childnum[p] > n >> 1) flag = false;
    if (flag) ans[++num] = p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int son, par;
    for (int i = 1;i < n;++i)
    {
        cin >> par >> son;
        addedge(par, son);
        addedge(son, par);
    }

    for (int i = 1;i <= n;++i) childnum[i] = 1;
    dfs(1);

    QuickSort(ans, 1, num);

    for (int i = 1;i <= num;++i) cout << ans[i] << '\n';

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
