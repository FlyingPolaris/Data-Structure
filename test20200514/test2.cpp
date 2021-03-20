// test2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

long long s[500000];
long long maxx[500000], minn[500000];
long long len, n;
long long node[500000];
long long node2[500000];
long long summaxx = 0;

void down(long long p)
{
    long long tmp = node[p];
    long long t = p;
    long long s = t << 1;
    while (t << 1 <= len)
    {
        s = t << 1;
        if (s != len && node[s + 1] < node[s]) s++;
        if (node[s] < tmp) node[t] = node[s];
        else break;
        t = s;
    }
    node[t] = tmp;
}

void up(long long t)
{
    long long tmp = node[t];
    long long p = len;
    while (p > 1 && tmp < node[p >> 1])
    {
        node[p] == node[p >> 1];
        p = p >> 1;
    }
    node[p] = tmp;
}

void buildtree()
{
    len = n;
    for (long long i = 1;i <= len;++i)
    {
        node[i] = s[i];
        summaxx += s[i];
    }
    for (long long i = 1;i <= len >> 1;++i)
    {
        down(i);
    }
}

void insertnode(long long da)
{
    len++;
    node[len] = da;
    up(len);
}

long long deletenode()
{
    long long ans = node[1];
    node[1] = node[len];
    len--;

    down(1);

    return ans;
}




long long summinn = 0;

void down2(long long p)
{
    long long tmp = node2[p];
    long long t = p;
    long long s = t << 1;
    while (t << 1 <= len)
    {
        s = t << 1;
        if (s != len && node2[s + 1] > node2[s]) s++;
        if (node2[s] > tmp) node2[t] = node2[s];
        else break;
        t = s;
    }
    node2[t] = tmp;
}

void up2(long long t)
{
    long long tmp = node2[t];
    long long p = len;
    while (p > 1 && tmp > node2[p >> 1])
    {
        node2[p] == node2[p >> 1];
        p = p >> 1;
    }
    node2[p] = tmp;
}

void buildtree2()
{
    len = n;
    for (long long i = 1;i <= n;++i)
    {
        node2[i] = s[3 * n - i + 1];
        summinn += s[3 * n - i + 1];
    }
    for (long long i = 1;i <= len >> 1;++i)
    {
        down2(i);
    }
}

void insertnode2(long long da)
{
    len++;
    node2[len] = da;
    up2(len);
}

long long deletenode2()
{
    long long ans = node2[1];
    node2[1] = node2[len];
    len--;

    down2(1);
    return ans;
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (long long i = 1;i <= 3 * n;++i)
    {
        cin >> s[i];
    }
    buildtree();

    maxx[n] = summaxx;
    for (long long i = n + 1;i <= 3 * n;++i)
    {
        if (s[i] > node[1])
        {
            summaxx -= deletenode();
            summaxx += s[i];
            insertnode(s[i]);
        }
        maxx[i] = summaxx;
    }

    buildtree2();
    minn[2 * n + 1] = summinn;
    for (long long i = 2 * n;i > 0;--i)
    {
        if (s[i] < node2[1])
        {
            summinn -= deletenode2();
            summinn += s[i];
            insertnode2(s[i]);
        }
        minn[i] = summinn;
    }

    long long ans = -1000000009;
    for (long long i = n;i <= 2 * n;++i)
    {
        if (ans < maxx[i] - minn[i+1]) ans = maxx[i] - minn[i+1];
    }
    cout << ans;
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
