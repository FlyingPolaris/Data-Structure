// 4189.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next = NULL;
};


node* G[500000];
node* tail[500000];
int city[500000];
int n;


int dfs(int u, int parent)
{
    int num = 0, max = 0, sum = 1;
    node* p = G[u]->next;
    while (true)
    {
        int v = p->data;
        if (v != parent)
        {
            num = dfs(v, u);
            sum += num;
            max = (num > max) ? num : max;
        }
        if (p->next != NULL) p = p->next;
        else break;
    }
    city[u] = (max > n - sum) ? max : n - sum;
    return sum;
}

void add(int x,int y)
{
    node* tmp1 = new node;
    tmp1->data = y;
    tail[x]->next = tmp1;
    tail[x] = tail[x]->next;

    node* tmp2 = new node;
    tmp2->data = x;
    tail[y]->next = tmp2;
    tail[y] = tail[y]->next;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> n;
    for (int i = 0;i <= n;++i) tail[i] = new node;
    for (int i = 0;i <= n;++i) G[i] = tail[i];
    for (int i = 1;i < n;++i)
    {
        cin >> x >> y;
        add(x, y);
    }
    dfs(1, -1);
    for (int i = 1;i <= n;++i)
    {
        if (2 * city[i] <= n) cout << i << ' ';
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
