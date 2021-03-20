// 1042.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct Node
{
    int leftson;
    int rightbro;
    bool isnotroot = false;
};

Node node[12349];

void fronttrav(int root)
{
    cout << root << ' ';
    int p = node[root].leftson;
    while (p != 0)
    {
        fronttrav(p);
        p = node[p].rightbro;
    }
}

void backtrav(int root)
{
    int p = node[root].leftson;
    while (p != 0)
    {
        backtrav(p);
        p = node[p].rightbro;
    }
    cout << root << ' ';
}

void leveltrav(int root)
{
    int stack[12349];
    int head;
    int tail;
    head = tail = 0;
    stack[tail] = root;
    tail++;
    while (head < tail)
    {
        cout << stack[head] << ' ';
        int q = node[stack[head]].leftson;
        head++;
        while (q != 0)
        {
            stack[tail] = q;
            q = node[q].rightbro;
            tail++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int t0 = t;
    while (t0--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].leftson = b;
        node[a].rightbro = c;
        node[b].isnotroot = node[c].isnotroot = true;
    }
    int root;
    for (int i = 1;i <= t;++i)
    {
        if (node[i].isnotroot == false)
        {
            root = i;
            break;
        }
    }
    fronttrav(root);
    cout << endl;
    backtrav(root);
    cout << endl;
    leveltrav(root);
   // cout << endl;

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
