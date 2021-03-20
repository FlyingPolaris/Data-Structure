// 1214.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct treenode
{
    int leftchild;
    int rightbro;
    int id;
};

treenode tree[100005];
bool isnotroot[100005];

void traverse1(int t)
{
    if (!t) return;
    cout << tree[t].id << ' ';
    t = tree[t].leftchild;
    while (t)
    {
        traverse1(t);
        t = tree[t].rightbro;
    }
}

void traverse2(int t)
{
    if (!t) return;
    int tmp = tree[t].leftchild;
    while (tmp)
    {
        traverse2(tmp);
        tmp = tree[tmp].rightbro;
    }
    cout << tree[t].id << ' ';
}

void traverse3(int t)
{
    int queue[100005] = { 0 };
    int head = 0, tail = -1;
    queue[++tail] = t;
    while (head <= tail)
    {
        if(tree[queue[head]].leftchild) queue[++tail] = tree[queue[head]].leftchild;
        while (tree[queue[tail]].rightbro)
        {
            tail++;
            queue[tail] = tree[queue[tail - 1]].rightbro;
        }
        cout << tree[queue[head++]].id << ' ';
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1;i <= N;++i)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        tree[i].leftchild = x1;
        tree[i].rightbro = x2;
        tree[i].id = x3;
        isnotroot[x1] = isnotroot[x2] = true;
    }
    int root = 0;
    for (int i = 1;i <= N;++i)
    {
        if (!isnotroot[i])
        {
            root = i;
            break;
        }
    }
    traverse1(root);
    cout << '\n';
    traverse2(root);
    cout << '\n';
    traverse3(root);
    cout << '\n';
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
