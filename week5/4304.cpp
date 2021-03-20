// 4304.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
long long node[400002];
long long a[100002];
long long teg[400002];

void build(long long k, long long l, long long r)
{
    if (l == r)
    {
        node[k] = a[l];
        return;
    }
    else
    {
        long long m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        node[k] = node[k << 1] + node[k << 1 | 1];
    }
}
void changenum(long long pos, long long value, long long k, long long l, long long r)
{
    if (l == r)
    {
        node[k] += value;
        a[l] += value;
    }
    else
    {
        long long m = (l + r) >> 1;
        if (pos <= m) changenum(pos, value, k << 1, l, m);
        else changenum(pos, value, k << 1 | 1, m + 1, r);
        node[k] = node[k << 1] + node[k << 1 | 1];
    }
}

long long checknum(long long A, long long B, long long k, long long l, long long r)
{
    if (A <= l && B >= r) return node[k];
    else
    {
        long long tmp = 0;
        long long m = (l + r) >> 1;
        if (A <= m) tmp += checknum(A, B, k << 1, l, m);
        if (B > m) tmp += checknum(A, B, k << 1 | 1, m + 1, r);
        return tmp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long N, M;
    memset(node, 0, sizeof(node));
    memset(a, 0, sizeof(a));
    cin >> N;
    for (long long i = 1;i <= N;++i) cin >> a[i];
    build(1, 1, N);
    cin >> M;
    while (M--)
    {
        char op[8];
        long long A, B;
        cin >> op >> A >> B;
        if (op[0] == 'Q') cout << checknum(A, B, 1, 1, N) << '\n';
        if (op[0] == 'S') changenum(A, -B, 1, 1, N);
        if (op[0] == 'G') changenum(A, B, 1, 1, N);
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
