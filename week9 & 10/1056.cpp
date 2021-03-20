// 1056.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class hheap {
private:
    long long a[2000005];
    long long heapsize = 0;

    void swap(long long x, long long y)
    {
        long long t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    void up(long long x)
    {
        while (x != 1)
        {
            if (a[x] > a[x >> 1])
            {
                swap(x, x >> 1);
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
            if (i < heapsize && a[i + 1] > a[i])
            {
                ++i;
            }
            if (a[i] > a[i >> 1])
            {
                swap(i, i >> 1);
                i <<= 1;
            }
            else break;
        }
    }

public:
    void push(long long x)
    {
        a[++heapsize] = x;
        up(heapsize);
    }

    void pop()
    {
        swap(1, heapsize);
        --heapsize;
        down();
    }

    long long top()
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

hheap candy;
hheap emptycandy;
long long head[2000005];

long long findhead(long long num)
{
    return head[num] == num ? num : head[num] = findhead(head[num]);
}

long long gettop()
{
    while (candy.top() == emptycandy.top() && candy.size() != 0 && emptycandy.size() != 0)
    {
        candy.pop();
        emptycandy.pop();
    }
    return candy.top();
}


long long box[2000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long n, m;
    cin >> n >> m;


    for (long long i = 1;i <= n;++i)
    {
        box[i] = 1;
        head[i] = i;
        candy.push(1);
    }

    char op;
    long long x, y;
    while (m--)
    {
        cin >> op;
        if (op == 'C')
        {
            cin >> x >> y;
            long long xhead = findhead(x);
            long long yhead = findhead(y);

            if (xhead == yhead) continue;
            if (!box[xhead] || !box[yhead]) continue;

            emptycandy.push(box[xhead]);
            emptycandy.push(box[yhead]);

            box[xhead] += box[yhead];
            box[yhead] = 0;

            candy.push(box[xhead]);
            head[yhead] = xhead;
        }
        else if (op == 'Q')
        {
            cin >> x;
            long long t = 0;
            if (candy.size() - emptycandy.size() <= x)
            {
                cout << 0 << '\n';
                continue;
            }
            long long tmp[15];
            while (x--)
            {
                ++t;
                tmp[t] = gettop();
                emptycandy.push(tmp[t]);
            }

            cout << tmp[t] << '\n';

            for (long long i = 1;i <= t;++i)
            {
                candy.push(tmp[i]);
            }
        }
        else if (op == 'D')
        {
            cin >> x;
            long long xhead = findhead(x);
            emptycandy.push(box[xhead]);
            box[xhead] = 0;
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
