// 1560.crotrot : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char s[100009];

class BST 
{
public:

    struct node
    {
        int thedata = 0;
        node* l = NULL;
        node* r = NULL;
        node* p = NULL;
    };

    node* root = NULL;
   
    void find(int thedata) 
    {
        memset(s, 0, sizeof(s));
        int len = 0;
        s[len] = '*';
        len++;
        node* rot = root;
        while (rot != NULL)
        {
            if (rot->thedata == thedata) 
            {
                cout << s << '\n';
                return;
            }
            else if (thedata < rot->thedata) 
            {
                s[len] = 'l';
                len++;
                rot = rot->l;
            }
            else 
            {
                s[len] = 'r';
                len++;
                rot = rot->r;
            }
        }
        cout << "Nothing." << '\n';
    }

    void insert(int thedata) 
    {
        if (root == NULL) 
        {
            root = new node;
            root->thedata = thedata;
            return;
        }

        node* rot = root;
        while (rot != NULL) 
        {
            if (rot->thedata == thedata)
                return;
            if (thedata < rot->thedata) 
            {
                if (rot->l != NULL) rot = rot->l;
                else 
                {
                    rot->l = new node;
                    rot->l->p = rot;
                    rot = rot->l;
                    break;
                }
            }
            else 
            {
                if (rot->r != NULL)  rot = rot->r;
                else 
                {
                    rot->r = new node;
                    rot->r->p = rot;
                    rot = rot->r;
                    break;
                }
            }
        }
        rot->thedata = thedata;
    }

    void erase(int thedata) 
    {
        node* rot = root;
        while (rot != NULL) 
        {
            if (rot->thedata == thedata)
            {
                if (rot->l == NULL && rot->r == NULL) 
                {
                    if (rot == root) root = NULL;
                    else if (rot->p->l == rot) rot->p->l = NULL;
                    else rot->p->r = NULL;
                    delete rot;
                }
                else if (rot->r == NULL)
                {
                    if (rot == root) 
                    {
                        root = rot->l;
                        rot->l->p = NULL;
                    }
                    else if (rot->p->l == rot)
                    {
                        rot->p->l = rot->l;
                        rot->l->p = rot->p;
                    }
                    else 
                    {
                        rot->p->r = rot->l;
                        rot->l->p = rot->p;
                    }
                    delete rot;
                }
                else if (rot->r) 
                {
                    node* q = rot->r;
                    while (q->l != NULL) q = q->l;
                    rot->thedata = q->thedata;
                    if (q->p->l == q) q->p->l = q->r;
                    else q->p->r = q->r;
                    if (q->r != NULL) q->r->p = q->p;
                    delete q;
                }
                return;
            }
            else if (thedata < rot->thedata) rot = rot->l;
            else if (thedata > rot->thedata) rot = rot->r;
        }
    }
};

BST a;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') a.insert(x); 
        else if (op == '-') a.erase(x);
        else if (op == '*') a.find(x);
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
