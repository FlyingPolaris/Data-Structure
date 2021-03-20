// 1412.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

void mymemset(int arr[], int t, int size)
{
    for (int i = 0;i < size;i++) arr[i] = t;
}

class bignum
{
private:
    int len;
    int num[1005];
public:
    bignum()
    {
        mymemset(num, 0, 1000);
        len = 0;
    }
    bignum(const bignum& r1)
    {
        mymemset(num, 0, 1000);
        len = r1.len;
        for (int i = 0;i < len;++i) num[i] = r1.num[i];
    }
    bignum(const char* s)
    {
        mymemset(num, 0, 1000);
        len = strlen(s);
        for (int i = len - 1;i >= 0;--i)
        {
            num[len - i - 1] = s[i] - '0';
            if (i == 0) break;
        }
    }
    
    bool operator<(const bignum& r1)
    {
        if (len != r1.len) return (len < r1.len);
        else
        {
            for (int i = len - 1;i >= 0;--i)
            {
                if (num[i] < r1.num[i]) return (num[i] < r1.num[i]);
                if (i == 0) break;
            }
            return false;
        }
    }
    bool zero()
    {
        if (len == 0 && num[0] == 0) return true;
        else return false;
    }
    bool odd()
    {
        if (num[0] % 2) return true;
        else return false;
    }
    bignum& operator=(const bignum& r1)
    {
        len = r1.len;
        mymemset(num, 0, 1000);
        for (int i = 0;i < len;++i) num[i] = r1.num[i];
        return *this;
    }

    bignum& operator-(const bignum& r1);
    bignum& div2();
    bignum& mult2();
    void printin2();
};

bignum& bignum::operator-(const bignum& r1)
{
    bignum s;
    s.len = len;
    for (int i = 0;i < len;i++)
    {
        s.num[i] += num[i] - r1.num[i];
        if (s.num[i] < 0)
        {
            s.num[i] += 10;
            s.num[i + 1]--;
        }
    }
    while (true)
    {
        if (s.len == 0) break;
        if (s.num[s.len - 1] != 0) break;
        s.len--;
    }
    return s;
}

bignum& bignum::div2()
{
    bignum s;
    s.len = len;
    for (int i = len - 1;i >= 0;--i)
    {
        s.num[i] = num[i]/2;
        if (i != 0) num[i - 1] += (num[i] % 2) * 10;
    }
    while (true)
    {
        if (s.len == 0) break;
        if (s.num[s.len - 1] != 0) break;
        s.len--;
    }
    return s;
}

bignum& bignum::mult2()
{
    bignum s;
    s.len = len + 1;
    int getin = 0;
    for (int i = 0;i < len;i++)
    {
        s.num[i] = ( num[i] * 2 )+ getin;
        getin = s.num[i] / 10;
        if (getin) s.num[i] -= 10;
    }
    if (getin) s.num[s.len - 1] = 1;
    else s.len--;
    return s;
}

void bignum::printin2()
{
    int len2 = 0;
    bignum p = *this;
    while (!p.zero())
    {
        p = p.div2();
        len2++;
    }
    int* arr;
    arr = new int[len2];
    for(int i=0;i<len2;i++)
    {
        if (odd())
        {
            num[0] -= 1;
            arr[len2 - i - 1] = 1;
            *this = div2();
        }
        else
        {
            arr[len2 - i - 1] = 0;
            *this = div2();
        }
    }
    for (int i = 0;i < len2;i++) printf("%d",arr[i]);
    delete[]arr;
    return;
}

char a[1005], b[1005];
int main()
{
    int n = 0;
    cin.getline(a, 501);
    cin.getline(b, 501);
    bignum num1 = a, num2 = b;
    if (num1 < num2)
    {
        bignum temp = num2;
        num2 = num1;
        num1 = temp;
    }
    while (!num2.zero())
    {
        if (num1.odd() && num2.odd()) num1 = num1 - num2;
        else if (num1.odd() && !num2.odd()) num2 = num2.div2();
        else if (!num1.odd() && num2.odd()) num1 = num1.div2();
        else 
        {
            num1 = num1.div2();
            num2 = num2.div2();
            n++;
        }
        if (num1 < num2)
        {
            bignum temp = num2;
            num2 = num1;
            num1 = temp;
        }
    }

    for (int i = 0;i < n;i++)
    {
        num1 = num1.mult2();
    }
    num1.printin2();
    //return 0;
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
