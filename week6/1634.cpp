// 1634.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

long long num = 0;
long long now = 0;
long long a[500005], b[500005];
long long n, k;

void deleteroot()
{
    b[1] = b[now];
    now--;
    long long t, s;
    t = s = 1;
    while (t << 1 <= now)
    {
        s = t << 1;
        if (s != now) num++;
        if (s != now && b[s] > b[s + 1]) s++;
        num++;
        if (b[s] < b[now + 1]) b[t] = b[s];
        else break;
        t = s;
    }
    b[t] = b[now + 1];
}



void merge(long long a[], long long l, long long m, long long r)
{
    long long i = l, j = m, k = 0;
    while (i < m && j <= r)
    {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
        num++;
    }
    while (i < m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (i = 0, k = l;k <= r;) a[k++] = b[i++];
}

void mergesort(long long a[], long long l, long long r)
{
    long long m = (l + r) >> 1;
    if (l == r) return;
    if ((l - r) % 2)
    {
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m + 1, r);
    }
    else
    {
        mergesort(a, l, m - 1);
        mergesort(a, m, r);
        merge(a, l, m, r);
    }
}

void aswap(long long& a, long long& b)
{
    long long tmp = a;
    a = b;
    b = tmp;
}

struct node
{
    long long id;
    node* prev = NULL;
    node* next = NULL;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    for (long long i = 1;i <= n;++i) cin >> a[i];

    if (k == 1)
    {       
        for (long long i = 1;i <= n;++i)
        {
            now++;
            b[now] = a[i];
            long long p = now;
            while (p > 1)
            {
                num++;
                if (b[p] < b[p >> 1])
                {
                    aswap(b[p], b[p >> 1]);
                    p = p >> 1;
                }
                else break;
            }
        }

        for (long long i = 1;i <= n - 1;++i) deleteroot();
        cout << num;
    }
    else if (k == 2)
    {
        mergesort(a, 1, n);
        cout << num;
    }
    else if (k == 3)
    {
        node** list = new node*[n + 2];
        for (long long i = 0;i <= n + 1;++i)
        {
            list[i] = new node;
        }
        list[0]->id = 0;
        list[0]->next = list[1];
        list[n + 1]->id = n + 1;
        list[n + 1]->prev = list[n];
        for (long long i = 1;i <= n;++i)
        {
            list[i]->id = i;
            list[i]->prev = list[i - 1];
            list[i]->next = list[i + 1];
        }
        for (long long i = n;i >= 1;--i)
        {
            num += list[a[i]]->next->id - list[a[i]]->prev->id - 2;
            list[a[i]]->prev->next = list[a[i]]->next;
            list[a[i]]->next->prev = list[a[i]]->prev;
            delete list[a[i]];
        }
        cout << num;
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
