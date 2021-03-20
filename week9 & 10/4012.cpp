// 4012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

template <class T>
class sheap {
private:
    T a[200005];
    long long heapsize = 0;

    void swap(long long x, long long y)
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
            if (i < heapsize && a[i + 1] < a[i])
            {
                ++i;
            }
            if (a[i] < a[i >> 1])
            {
                swap(i, i >> 1);
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
        swap(1, heapsize);
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


int main()
{
    sheap<int> fruit;
    int ans = 0;
    int n;
    cin >> n;
    int x;

    for (int i = 0;i < n;++i)
    {
        cin >> x;
        fruit.push(x);
    }

    int a, b;
    for (int i = 1;i < n;++i)
    {
        a = fruit.top();
        fruit.pop();
        b = fruit.top();
        fruit.pop();
        ans += a + b;
        fruit.push(a + b);
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
