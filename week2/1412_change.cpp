
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;


void mymemset(int arr[], int t, int size)
{
    for (int i = 0;i < size - 1;i++) arr[i] = t;
}

void changcharintoint(char a[], int b[], int& c)
{
    mymemset(b, 0, 1005);
    c = strlen(a);
    for (int i = c - 1;i >= 0;--i)
    {
        b[c - i - 1] = a[i] - '0';
        if (i == 0) break;
    }
}

void myswap(int num1[], int num2[], int& len1, int& len2)
{
    int tempnum[1005];
    mymemset(tempnum, 0, 1005);
    int templen = len1;
    for (int i = 0;i < len1;++i)
    {
        tempnum[i] = num1[i];
    }
    mymemset(num1, 0, 1005);
    for (int i = 0;i < len2;i++)
    {
        num1[i] = num2[i];
    }
    mymemset(num2, 0, 1005);
    for (int i = 0;i < len2;i++)
    {
        num2[i] = tempnum[i];
    }
    len1 = len2;
    len2 = templen;
}

void div2(int num[], int& len)
{
    int s[1005];
    int slen = len;
    for (int i = len - 1;i >= 0;--i)
    {
        s[i] = num[i] / 2;
        if (i != 0) num[i - 1] += (num[i] % 2) * 10;
    }
    while (true)
    {
        if (slen == 0) break;
        if (s[slen - 1] != 0) break;
        slen--;
    }
    myswap(num,s,len,slen);
}


void mult2(int num[], int& len)
{
    int s[1005];
    int slen = len + 1;
    int getin = 0;
    for (int i = 0;i < len;i++)
    {
        s[i] = (num[i] * 2) + getin;
        getin = s[i] / 10;
        if (getin) s[i] -= 10;
    }
    if (getin) s[slen - 1] = 1;
    else slen--;
    myswap(num, s, len, slen);
}

void reduce(int num1[], int num2[], int& len1, int& len2)
{
    int s[1005];
    mymemset(s, 0, 1005);
    int slen = len1;
    for (int i = 0;i < len1;i++)
    {
        s[i] += num1[i] - num2[i];
        if (s[i] < 0)
        {
            s[i] += 10;
            s[i + 1]--;
        }
    }
    while (true)
    {
        if (slen == 0) break;
        if (s[slen - 1] != 0) break;
        slen--;
    }
    myswap(num1, s, len1, slen);
}


bool compare(int num1[], int num2[], int len1, int len2)
{
    if (len1 != len2) return (len1 < len2);
    else
    {
        for (int i = len1 - 1;i >= 0;--i)
        {
            if (num1[i] != num2[i]) return (num1[i] < num2[i]);
            if (i == 0) break;
        }
        return false;
    }
}

bool zero(int num[], int len)
{
    if (len == 0 && num[0] == 0) return true;
    else return false;
}

bool odd(int num[])
{
    if (num[0] % 2) return true;
    else return false;
}

void printin2(int num[], int& len)
{
    int len2 = 0;
    int tempnum[1005];
    mymemset(tempnum, 0, 1005);
    int templen = len;
    for (int i = 0;i < len;++i)
    {
        tempnum[i] = num[i];
    }
    while (!zero(tempnum, templen))
    {
        div2(tempnum, templen);
        len2++;
    }
    int* arr;
    arr = new int[len2];
    for (int i = 0;i < len2;i++)
    {
        if (odd(num))
        {
            num[0] -= 1;
            arr[len2 - i - 1] = 1;
            div2(num, len);
        }
        else
        {
            arr[len2 - i - 1] = 0;
            div2(num, len);
        }
    }
    for (int i = 0;i < len2;i++) printf("%d", arr[i]);
    delete[]arr;
}
char a[1005], b[1005];
int num1[1005], num2[1005];
int len1 = 0, len2 = 0;


int main()
{
    int n = 0;
    scanf("%s%s", a, b);
    changcharintoint(a, num1, len1);
    changcharintoint(b, num2, len2);
    if (compare(num1, num2, len1, len2))  myswap(num1, num2, len1, len2);
    while (!zero(num2, len2))
    {
        if (odd(num1) && odd(num2)) reduce(num1, num2, len1, len2);
        else if (!odd(num1) && odd(num2)) div2(num1, len1);
        else if (odd(num1) && !odd(num2)) div2(num2, len2);
        else
        {
            div2(num1, len1);
            div2(num2, len2);
            n++;
        }
        if (compare(num1, num2, len1, len2))  myswap(num1, num2, len1, len2);
    }
    for (int i = 0;i < n;i++) mult2(num1, len1);
    printin2(num1, len1);
    return 0;
}

