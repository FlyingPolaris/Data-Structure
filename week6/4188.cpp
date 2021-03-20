// 4188.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstring>
using namespace std;

class str
{
public:
    long long len = 0;
    long long size = 2;
    char* data;
    void doublespace()
    {
        char* tmp = data;

        size += size >> 1;
        data = new char[size];
        for (long long i = 0;i <= len;++i)
        {
            data[i] = tmp[i];
        }
        delete[] tmp;
    }
};

//long long gethash(long long l, long long r, char* m)
//{
//    long long hash = 0;
//    for (long long i = l;i <= r;++i)
//    {
//        hash = (hash * 53 + (m[i] - 'a' + 1)) % (19260817);
//    }
//    return hash;
//}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;
    str* name = new str[N];
    long long** prehash = new long long* [N];
    long long** endhash = new long long* [N];
    cin.get();
    for (long long i = 0;i < N;++i)
    {
        name[i].data = new char[2];
        char x = cin.get();
        while (x != '\n')
        {
            name[i].data[name[i].len] = x;
            name[i].len++;
            x = cin.get();
            if (name[i].size == name[i].len) name[i].doublespace();
        }
        /*   name[i].data[name[i].len] = '\n';
           name[i].len++;
           if (name[i].size <= name[i].len) name[i].doublespace();*/

        prehash[i] = new long long[name[i].size];

        prehash[i][0] = name[i].data[0] - 'a' + 1;
        for (long long j = 1;j < name[i].len;++j)
        {
            prehash[i][j] = (prehash[i][j - 1] * 28 + (name[i].data[j] - 'a' + 1)) % (1000000007);
        }

        endhash[i] = new long long[name[i].size];
        endhash[i][name[i].len - 1] = name[i].data[name[i].len - 1] - 'a' + 1;

        for (long long j = name[i].len - 2;j >= 0;--j)
        {
            endhash[i][j] = (endhash[i][j + 1] * 28 + (name[i].data[j] - 'a' + 1)) % (1000000007);
        }

    }

    long long M;
    cin >> M;
    while (M--)
    {
        long long op, x, y;
        cin >> op;
        if (op == 1)
        {
            bool flag = 0;
            cin >> x;
            x--;
            for (long long i = 0;i < x;++i)
            {
                if (endhash[x][0] == endhash[i][0])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
        if (op == 2)
        {
            cin >> x >> y;
            x--;y--;
            long long len = (name[x].len < name[y].len) ? name[x].len - 1 : name[y].len - 1;
            for (long long i = len;i >= 0;--i)
            {
                if (prehash[x][i] == prehash[y][i])
                {
                    cout << i + 1 << '\n';
                    break;
                }
            }
        }
        if (op == 3)
        {
            cin >> x >> y;
            x--;y--;
            if (name[x].len <= name[y].len)
            {
                long long a = name[x].len - 1;
                long long b = name[y].len - 1;
                for (long long i = 0;i <= a;++i)
                {
                    if (endhash[x][i] == endhash[y][i + b - a])
                    {
                        cout << a - i + 1 << '\n';
                        break;
                    }
                }
            }

            if (name[x].len > name[y].len)
            {
                long long a = name[x].len - 1;
                long long b = name[y].len - 1;
                for (long long i = 0;i <= b;++i)
                {
                    if (endhash[x][i + a - b] == endhash[y][i])
                    {
                        cout << b - i + 1 << '\n';
                        break;
                    }
                }
            }

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
