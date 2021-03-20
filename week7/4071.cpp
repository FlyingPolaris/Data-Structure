// 4071.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const long long MOD = 1E9 + 7;
struct m
{
    long long leftup = 0;
    long long leftdown = 0;
    long long rightup = 0;
    long long rightdown = 0;
};

m mul(m a, m b)
{
    m ans;
    ans.leftup = (a.leftup * b.leftup % MOD + a.rightup * b.leftdown % MOD) % MOD;
    ans.rightup = (a.leftup * b.rightup % MOD + a.rightup * b.rightdown % MOD) % MOD;
    ans.leftdown = (a.leftdown * b.leftup % MOD + a.rightdown * b.leftdown % MOD) % MOD;
    ans.rightdown = (a.leftdown * b.rightup % MOD + a.rightdown * b.rightdown % MOD) % MOD;
    return ans;
}

m quickpos(m a, long long n)
{
    if (n == 0)
    {
        m E;
        E.leftdown = E.rightup = 0;
        E.leftup = E.rightdown = 1;
        return E;
    }
    else
    {
        while (!(n & 1))
        {
            n >>= 1;
            a = mul(a, a);
        }
    }
    m ans = a;
    n >>= 1;
    while (n)
    {
        a = mul(a, a);
        if (n & 1) ans = mul(ans, a);
        n >>= 1;
    }
    return ans;
}


int main()
{
    long long n;
    cin >> n;
    m a;
    a.leftup = a.leftdown = a.rightup = 1;
    a.rightdown = 0;
    m ans = quickpos(a, n);
    cout << ans.leftup;
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
