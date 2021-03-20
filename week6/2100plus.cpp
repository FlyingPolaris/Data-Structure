// 2100plus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

long long n;
long long len = 0;
long long word[200005];
void build()
{
    for (long long i = 1;i <= n;++i)
    {
        cin >> word[i];
        len++;
    }
    for (long long i = n>>1;i >=1;--i)
    {
        long long t = i;
        long long s = i;
        long long tmp = word[t];
        while (t << 1 <= len)
        {
            s = t << 1;
            if (s != len && word[s + 1] < word[s]) s++;
            if (word[s] < tmp) word[t] = word[s];
            else break;
            t = s;
        }
        word[t] = tmp;
    }
}

long long deleteroot()
{
    long long ans = word[1];
    word[1] = word[len];
    len--;
    long long t = 1;
    long long s = 1;
    while (t << 1 <= len)
    {
        s = t << 1;
        if (s != len && word[s + 1] < word[s]) s++;
        if (word[s] < word[len + 1]) word[t] = word[s];
        else break; 
        t = s;
    }
    word[t] = word[len + 1];
    return ans;
}

void insert(long long t)
{
    len++;
    //word[len] = t;
    long long p = len;
    while (p > 1 && t < word[p << 1])
    {
        word[p] = word[p >> 1];
        p = p >> 1;
    }
    word[p] = t;
}
long long ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    build();
    len = n;
    while (len != 1)
    {
        long long a, b;
        a = deleteroot();
        b = deleteroot();
        insert(a + b);
        ans += a + b;
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
