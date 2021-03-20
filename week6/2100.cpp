// 2100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

long long N;
long long ans = 0;
struct node
{
    long long num;
    long long val;
    node* l, * r;
    node* p;
};

void select(node** a, long long end, long long& s1, long long& s2)
{
    long long i = 1;
    long long min1, min2;
    while (i <= end && a[i]->p != NULL)
    {
        ++i;
    }
    min1 = a[i]->val;
    s1 = i;
    ++i;
    while (i <= end && a[i]->p != NULL)
    {
        ++i;
    }
    if (a[i]->val < min1)
    {
        min2 = min1;
        s2 = s1;
        min1 = a[i]->val;
        s1 = i;
    }
    else
    {
        min2 = a[i]->val;
        s2 = i;
    }
    for (long long j = i + 1;j <= end;++j)
    {
        if (a[j]->p != NULL) continue;
        else if (a[j]->val < min1)
        {
            min2 = min1;
            s2 = s1;
            min1 = a[j]->val;
            s1 = j;
        }
        else if (a[j]->val >= min1 && a[j]->val < min2)
        {
            min2 = a[j]->val;
            s2 = j;
        }
    }
}


node* word[500005];

void buildtree()
{
    cin >> N;
    for (long long i = 1;i <= N;++i)
    {
        word[i] = new node;
        word[i]->num = i;
        cin >> word[i]->val;
        word[i]->l = NULL;
        word[i]->r = NULL;
        word[i]->p = NULL;
    }
    for (long long i = N + 1;i <= 2 * N - 1;++i)
    {
        word[i] = new node;
        word[i]->num = i;
        word[i]->val = 0;
        word[i]->l = NULL;
        word[i]->r = NULL;
        word[i]->p = NULL;
    }
    for (long long i = N + 1;i <= 2 * N - 1;++i)
    {
        long long s1, s2;
        select(word, i-1, s1, s2);
        word[s1]->p = word[s2]->p = word[i];
        word[i]->l = word[s1];
        word[i]->r = word[s2];
        word[i]->val = word[s1]->val + word[s2]->val;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    buildtree();
    for (long long i = N + 1;i <= 2 * N - 1;++i)
        ans += word[i]->val;
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
