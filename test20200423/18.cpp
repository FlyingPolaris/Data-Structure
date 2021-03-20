// 18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int f[150002], m[150002], b[150002];
int x1[150002], x2[150002], x3[150002];
int node[150002];
int sna[600002];
int top;
int tail;
void build(int k,int al,int ar,int bl,int br)
{
    if (al <= ar && bl <= br)
    {
        node[k] = f[al];
        int i = bl;
        while (m[i] != f[al])
            i++;
        if (al <= ar && bl <= br) build(k << 1, al + 1, al + (i - bl), bl, i - 1);
        if (al <= ar && bl <= br) build(k << 1 | 1, al + (i - bl) + 1, ar, i + 1, br);
    } 
}
void print(int a[], int n)
{
    for (int i = 1;i <= n;++i)
        cout << a[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for (int i = 1;i <= k;++i) cin >> x1[i];
    for (int i = 1;i <= k;++i) cin >> x2[i];
    for (int i = 1;i <= k;++i) cin >> x3[i];
    f[0] = m[0] = b[0] = 0;
    int z = 0;
    while (true)
    {
        for (int i = 0;i <= k;++i)
            f[i] = m[i] = b[i] = -1;
        int t1 = 1, t2 = 0, t3 = 0;
        f[1] = x1[t1+z];
        while (x3[t3+1+z] != f[1])
        {
            b[++t3-z] = x3[t3];
        }
        t3++;
        for (t2 = z+1;t2 <= t3 + z;++t2)
        {
            m[t2-z] = x2[t2];
        }
        for (t1 = z+2;t1 <= t3 + z;++t1)
        {
            f[t1-z] = x1[t1];
        }
        build(1, 1, t3, 1, t3);
        print(node, t3);
        z += t3;

        if (z >= k) break;
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
