// 4232.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
int node[800002];
int grades[200002];

int higher(int a, int b)
{
    return (a > b ? a : b);
}
void build(int k,int l,int r)
{
    if (l == r)
    {
        node[k] = grades[l];
        return;
    } 
    else
    {
        int m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        node[k] = higher(node[k << 1], node[k << 1 | 1]);
    }
}
void changegrade(int pos, int value, int k, int l, int r)
{
    if (l == r)
    {
        node[k] = grades[l] = value;
    }
    else
    {
        int m = (l + r) >> 1;
        if (pos <= m) changegrade(pos, value, k << 1, l, m);
        else changegrade(pos, value, k << 1 | 1, m + 1, r);
        node[k] = higher(node[k << 1], node[k << 1 | 1]);
    }
}

int checkgrade(int A, int B,int k, int l, int r)
{
    if (A <= l && B >= r) return node[k];
    else
    {
        int tmp = -1;
        int m = (l + r) >> 1;
        if (A <= m) tmp = higher(checkgrade(A, B, k << 1, l, m), tmp);
        if (B > m) tmp = higher(checkgrade(A, B, k << 1 | 1, m + 1, r), tmp);
        return tmp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    while (cin >> N >> M)
    {
        memset(node, 0, sizeof(node));
        memset(grades, 0, sizeof(grades));
        for (int i = 1;i <= N;++i) cin >> grades[i];
        build(1, 1, N);
        while (M--)
        {
            char op;
            int A, B;
            cin >> op >> A >> B;
            if (op == 'Q') cout << checkgrade(A, B, 1, 1, N) << '\n';
            if (op == 'U') changegrade(A, B, 1, 1, N);
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
