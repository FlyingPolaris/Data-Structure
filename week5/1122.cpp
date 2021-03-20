// 1122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
//#include <cstring>
using namespace std;

int node[200002];
int lzero[200002], rzero[200002];
int tag[200002];

void pushup(int k, int l, int r)
{
    lzero[k] = lzero[k << 1];
    rzero[k] = rzero[k << 1 | 1];
    int m = (l + r) >> 1;
    if (lzero[k] == m - l + 1) lzero[k] += lzero[k << 1 | 1];
    if (rzero[k] == r - m) rzero[k] += rzero[k << 1];
    int tmp1 = node[k << 1];
    int tmp2 = node[k << 1 | 1];
    int tmp3 = rzero[k << 1] + lzero[k << 1 | 1];
    node[k] = tmp1 > tmp2 ? tmp1 : tmp2;
    node[k] = node[k] > tmp3 ? node[k] : tmp3;
}

void pushdown(int k, int l, int r)
{
    if (tag[k] != 0)
    {
        tag[k << 1] = tag[k << 1 | 1] = tag[k];
        int m = (l + r) >> 1;
        if (tag[k] == 1)
        {
            node[k << 1] = node[k << 1 | 1] = lzero[k << 1] = rzero[k << 1] = lzero[k << 1 | 1] = rzero[k << 1 | 1] = 0;
        }
        if (tag[k] == 2)
        {
            node[k << 1] = lzero[k << 1] = rzero[k << 1] = m - l + 1;
            node[k << 1 | 1] = lzero[k << 1 | 1] = rzero[k << 1 | 1] = r - m;
        }
        tag[k] = 0;
    }
}
void build(int k,int l,int r)
{
    if (l == r)
    {
        node[k] = lzero[k] = rzero[k] = 1;
        return;
    }
    else
    {
        int m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        pushup(k, l, r);
    }
}

int check(int k,int l,int r,int len)
{
    if (l == r)
    {
        return l;
    }
    pushdown(k, l, r);
    int m = (l + r) >> 1;
    if (node[k << 1] >= len) return check(k << 1, l, m, len);
    else if (rzero[k << 1] + lzero[k << 1 | 1] >= len) return m - rzero[k << 1] + 1;
    else if (node[k << 1 | 1] >= len) return check(k << 1 | 1, m + 1, r, len);
}

void checkin(int L, int R, int k, int l, int r)
{
    if (L <= l && R >= r)
    {
        tag[k] = 1;
        node[k] = lzero[k] = rzero[k] = 0;
        return;
    }
    pushdown(k, l, r);
    int m = (l + r) >> 1;
    if (L <= m) checkin(L, R, k << 1, l, m);
    if (R > m) checkin(L, R, k << 1 | 1, m + 1, r);
    pushup(k, l, r);
}

void checkout(int L, int R, int k, int l, int r)
{
    if (L <= l && R >= r)
    {
        tag[k] = 2;
        node[k] = lzero[k] = rzero[k] = r - l + 1;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(k, l, r);
    if (L <= m) checkout(L, R, k << 1, l, m);
    if (R > m) checkout(L, R, k << 1 | 1, m + 1, r);
    pushup(k, l, r);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int N, M;
    scanf("%d %d", &N, &M);
    build(1, 1, N);
    while (M--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            if (x > node[1]) printf("0\n");
            else
            {
                int L, R;
                L = check(1, 1, N, x);
                printf("%d\n", L);
                R = L + x - 1;
                checkin(L, R, 1, 1, N);
            }
        }
        if (op == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int L, R;
            L = x;
            R = x + y - 1;
            checkout(L, R, 1, 1, N);
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
