// 1050.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct node
{
    int num, npl;
    node* l = NULL;
    node* r = NULL;
};

void nodeswap(node*& a, node*& b)
{
    node* p = a;
    a = b;
    b = p;
}
node* girlfriend[300005];
//bool exist[300005];

node* merge(node* x, node* y)
{
    if (x == NULL) return y;
    if (y == NULL) return x;
    if (x->num > y->num)
    {
        nodeswap(x, y);
    }
    x->r = merge(x->r, y);
    if (x->l == NULL || x->l->npl < x->r->npl)
    {
        nodeswap(x->l, x->r);
    }
    if (x->r == NULL) x->npl = 0;
    else x->npl = x->r->npl + 1;
    return x;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> n >> m;
    for (int i = 0;i < n;++i)
    {
        node* tmp = new node;
        cin >> tmp->num;
        tmp->npl = 0;
        girlfriend[i] = tmp;
        //exist[i] = 1;
    }
    for (int i = 0;i < m;++i)
    {
        int op, x, y;
        cin >> op;
        if (op == 0)
        {
            cin >> x >> y;
            girlfriend[x] = merge(girlfriend[x], girlfriend[y]);
            //exist[y] = 0;
        }
        else if (op == 1)
        {
            cin >> x;
            if (girlfriend[x] == NULL) cout << -1 << '\n';
            else
            {
                cout << girlfriend[x]->num << '\n';
                node* tmp = girlfriend[x];
                girlfriend[x] = merge(girlfriend[x]->l, girlfriend[x]->r);
                //if (girlfriend[x] == NULL) exist[x] = 0;
                delete tmp;
            }
        }
        else if (op == 2)
        {
            cin >> x >> y;
            node* tmp = new node;
            tmp->num = y;
            tmp->npl = 0;
            girlfriend[x] = merge(girlfriend[x], tmp);
            //exist[x] = 1;
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
