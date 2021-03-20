// 2111.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class bstree
{
private:
    struct node
    {
        long long num;
        node* l;
        node* r;
        node(long long x = 0, node* a = NULL, node* b = NULL)
        {
            num = x;
            l = a;
            r = b;
        }
    };

public:
    node* root = NULL;
    long long size = 0;
    void insert(long long x, node*& p)
    {
        if (p == NULL)
        {
            p = new node(x);
            size++;
        }
        else
        {
            if (x < p->num) insert(x, p->l);
            else insert(x, p->r);
        }
    }

    void deletenode(long long x, node*& p)
    {
        if (p == NULL) return;
        if (x < p->num) deletenode(x, p->l);
        else if (x > p->num) deletenode(x, p->r);
        else if (p->l != NULL && p->r != NULL)
        {
            node* tmp = p->r;
            while (tmp->l != NULL)
            {
                tmp = tmp->l;
            }
            p->num = tmp->num;
            deletenode(p->num, p->r);
        }
        else
        {
            node* tmp = p;
            p = (p->l == NULL) ? p->r : p->l;
            delete tmp;
            size--;
        }
        if (size == 0) root = NULL;
    }

    long long findmin(long long x)
    {
        long long ans = 1e9;
        node* p = root;
        while (p != NULL)
        {
            if (x < p->num)
            {
                ans = ans < p->num - x ? ans : p->num - x;
                p = p->l;
            }
            else if (x > p->num)
            {
                ans = ans < x - p->num ? ans : x - p->num;
                p = p->r;
            }
            else return 0;
        }
        return ans;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m;
    long long op;
    long long x;
    bstree a;
    cin >> m;
    while (m--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> x;
            cout << a.findmin(x) << '\n';
        }
        else if (op == 1)
        {
            cin >> x;
            a.insert(x, a.root);
        }
        else if (op == 2)
        {
            cin >> x;
            a.deletenode(x, a.root);
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
