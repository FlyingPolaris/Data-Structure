// 4097.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cmath>
using namespace std;

const int MAXSIZE = 1000;

int n, m;

class node
{
public:
    node* prev = NULL;
    node* next = NULL;
    int thedata[MAXSIZE];
    int len = 0;

    node(node* p = NULL, node* q = NULL) : prev(p), next(q) {}

    void split(int pos) 
    {
        if (pos >= len || pos < 0)  return;
        node* b = new node(this, next);
        if (next != NULL) next->prev = b;
        next = b;
        b->len = len - pos;
        for (int i = 0; i < len - pos; ++i)
            b->thedata[i] = thedata[i + pos];
        len = pos;
    }

    bool merge() 
    {
        node* b = next;
        if (b == NULL) return false;
        if (len + b->len > MAXSIZE) return false;
        next = b->next;
        if (next != NULL) next->prev = this;
        for (int i = 0; i < b->len; ++i)
            thedata[len++] = b->thedata[i];
        delete b;
        return true;
    }

    void delNext() 
    {
        node* b = next;
        if (b == NULL) return;
        next = b->next;
        if (next != NULL)
            next->prev = this;
        delete b;
    }
};

ostream& operator <<(ostream& os, const node& b) 
{
    for (int i = 0; i < b.len; ++i)
        os << b.thedata[i] << ' ';
    return os;
}

node* head = new node();

void insert(int x, int y) 
{
    node* p = head->next;
    while (p && x > p->len) 
    {
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    p->thedata[p->len++] = y;
}

void remove(int x) 
{
    node* p = head->next;
    while (p && x > p->len) 
    {
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    --p->len;
}

void update() 
{
    node* p = head->next;
    while (p) 
    {
        p->merge();
        p = p->next;
    }
}

int main() 
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;
 
    node* p = head->next = new node();

    for (int i = 1; i <= n; ++i) 
    {
        int t;
        cin >> t;
        p->thedata[p->len] = t;
        ++p->len;
        if (p->len == MAXSIZE) 
        {
            p->next = new node();
            p = p->next;
        }
    }
    while (m--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int a, b;
            cin >> a >> b;
            insert(a, b);
        }
        else 
        {
            int x;
            cin >> x;
            remove(x);
        }
        update();
    }
    p = head->next;
    while (p != NULL) 
    {
        cout << *p;
        p = p->next;
    }
    cout << endl;
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
