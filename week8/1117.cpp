// 1117.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int head[200005], pre[200005], nex[200005], num[200005], degree[200005], point[200005];

int tot = 0;
int maxnum = 0;

void add(int u,int v)
{
    tot++;
    point[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;

    if (nex[tot]) pre[nex[tot]] = tot;

    degree[u]++;
    degree[v]++;
}

void del(int begin, int edge)
{
    if (nex[edge]) pre[nex[edge]] = pre[edge];
    if (pre[edge]) nex[pre[edge]] = nex[edge];
    else head[begin] = nex[edge];

    pre[edge] = nex[edge] = 0;
}

template <class T>
class sheap {
private:
    T a[200005];
    long long heapsize = 0;

    void swp(long long x, long long y)
    {
        T t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    void up(long long x)
    {
        while (x != 1)
        {
            if (a[x] < a[x >> 1])
            {
                swp(x, x >> 1);
                x >>= 1;
            }
            else break;
        }
    }

    void down()
    {
        long long i = 2;
        while (i <= heapsize)
        {
            if (i < heapsize && a[i + 1] < a[i])
            {
                ++i;
            }
            if (a[i] < a[i >> 1])
            {
                swp(i, i >> 1);
                i <<= 1;
            }
            else break;
        }
    }

public:
    void push(T x)
    {
        a[++heapsize] = x;
        up(heapsize);
    }

    void pop()
    {
        swp(1, heapsize);
        --heapsize;
        down();
    }

    T top()
    {
        return a[1];
    }

    bool empty()
    {
        return heapsize == 0;
    }

    long long size()
    {
        return heapsize;
    }
};

void build(int rot)
{
    char ch;
    int a = 0;
    cin >> ch;
    while (ch >= '0' && ch <= '9')
    {
        a *= 10;
        a += ch - '0';
        cin >> ch;
    }


    if (a > maxnum) maxnum = a;

    if (rot != 0)
    {
        add(rot, a);
        add(a, rot);
    }

    while (ch == '(')
    {
        build(a);
        cin >> ch;
    }
}


sheap<int> Heap;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin.get();
    build(0);

    for (int i = 1;i <= maxnum;++i)
    {
        if (degree[i] == 2) Heap.push(i);
    }

    for (int i = 1;i < maxnum;++i)
    {
        int tmp = Heap.top();
        int edge = head[tmp];
        int parent = point[edge];
        cout << parent << ' ';

        Heap.pop();
        del(tmp, edge);
        if (edge % 2 == 0) del(parent, edge - 1);
        else del(parent, edge + 1);

        degree[parent] -= 2;
        if (degree[parent] == 2) Heap.push(parent);
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
