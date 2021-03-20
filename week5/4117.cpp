// 4117.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>

using namespace std;
long long a[100005];
long long node[400005];
long long tag[400005];
void build(long long k,long long l,long long r)
{
    if (l == r)
    {
        node[k] = a[l];
        return;
    }
    long long m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    node[k] = node[k << 1] + node[k << 1 | 1];

}

void pushdown(long long k, long long l, long long r, long long m)
{
    if (tag[k])
    {
        tag[k << 1] += tag[k];
        tag[k << 1 | 1] += tag[k];
        node[k << 1] += tag[k] * (m - l + 1);
        node[k << 1 | 1] += tag[k] * (r - m);
        tag[k] = 0;
    }
}
void changevalue(long long L, long long R, long long value, long long k, long long l, long long r)
{
    if (L <= l && R >= r)
    {
        tag[k] += value;
        node[k] += value * (r - l + 1);
        return;
    }
    long long m = (l + r) >> 1;
    pushdown(k, l, r, m);
    if (L <= m) changevalue(L, R, value, k << 1, l, m);
    if (R > m) changevalue(L, R, value, k << 1 | 1, m + 1, r); 
    node[k] = node[k << 1] + node[k << 1 | 1];
}

long long thesum(long long L, long long R, long long k, long long l, long long r)
{
    if (L <= l && R >= r) return node[k];
    else
    {
        long long m = (l + r) >> 1;
        pushdown(k, l, r, m);
        long long ans = 0;
        if (L <= m) ans += thesum(L, R, k << 1, l, m);
        if (R > m) ans += thesum(L, R, k << 1 | 1, m + 1, r);
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long N, Q;
    cin >> N >> Q;
    memset(a, 0, sizeof(a));
    memset(node, 0, sizeof(node));
    memset(tag, 0, sizeof(tag));
    for (long long i = 1;i <= N;++i)
    {
        cin >> a[i];
    }
    build(1, 1, N);
    while (Q--)
    {
        char op;
        cin >> op;
        long long a, b, c;
        if (op == 'Q')
        {
            cin >> a >> b;
            cout<<thesum(a, b, 1, 1, N)<<'\n';
        }
        if (op == 'C')
        {
            cin >> a >> b >> c;
            changevalue(a, b, c, 1, 1, N);
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
