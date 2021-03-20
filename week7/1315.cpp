// 1315.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct frac
{
    int son;
    int mother;
    double num;
};

frac num[500000];
int N;

void quicksort(frac a[], int begin, int end)
{
    int i, j;
    frac tmp;
    i = begin;
    j = end;
    if (begin < end)
    {
        tmp = a[begin];
        while (i != j)
        {
            while (i < j && tmp.num <= a[j].num) --j;
            if (i < j)
            {
                a[i] = a[j];
                ++i;
            }
            while (i < j && tmp.num > a[i].num) ++i;
            if (i < j)
            {
                a[j] = a[i];
                --j;
            }
        }
        a[i] = tmp;
        quicksort(a, begin, i - 1);
        quicksort(a, i + 1, end);
    }
}


int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    num[0].son = 0; num[1].son = 1;
    num[0].mother = num[1].mother = 1;
    num[0].num = 0; num[1].num = 1;

    int p = 2;

    for (int i = 2;i <= N;++i)
    {
        for (int j = 1;j < i;++j)
        {
            if (gcd(j, i) == 1)
            {
                num[p].son = j;
                num[p].mother = i;
                num[p].num = (1.0 * j) / (1.0 * i);
                ++p;
            }
        }
    }
    quicksort(num, 0, p - 1);
    for (int i = 0;i < p;++i)
    {
        cout << num[i].son << '/' << num[i].mother << '\n';
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
