


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct mouse
{
    int P;
    int S;
    int num;
};
void QuickSort(mouse[], int, int);
void BubbleSort(mouse[], int);
int main()
{
    int N, R;
    cin >> N >> R;
    mouse* mice;
    mice = new mouse[2 * N];
    for (int i = 0;i < 2 * N;i++) scanf("%d", &mice[i].P);
    for (int i = 0;i < 2 * N;i++) scanf("%d", &mice[i].S);
    for (int i = 0;i < 2 * N;i++) mice[i].num = i + 1;
    QuickSort(mice, 0, 2 * N - 1);
    /*cout << "before game" << endl;
    cout << endl;
    for (int i = 0;i < 2 * N;i++)
    {
        cout << i << ')' << ' ' << P[i] << '\t';
    }
    cout << endl;
    for (int i = 0;i < 2 * N;i++)
    {
        cout << i << ')' << ' ' << S[i] << '\t';
    }
    cout << endl;
    for (int i = 0;i < 2 * N;i++)
    {
        cout << i << ')' << ' ' << num[i] << '\t';
    }
    cout << endl;*/
    for (int j = 0;j < R;j++)
    {
        for (int i = 0;i < 2 * N;i += 2)
        {
            if (mice[i].S > mice[i + 1].S) mice[i].P += 2;
            else if (mice[i].S < mice[i + 1].S) mice[i + 1].P += 2;
            else
            {
                mice[i].P += 1;
                mice[i + 1].P += 1;
            }
        }
        BubbleSort(mice, 2 * N);
   
        /* cout << endl;
         cout << "after game" << j+1 << endl;

         for (int i = 0;i < 2 * N;i++)
         {
             cout << i<<')' << ' ' <<P[i] << '\t';
         }
         cout << endl;
         for (int i = 0;i < 2 * N;i++)
         {
             cout << i << ')' << ' ' << S[i] << '\t';
         }
         cout << endl;
         for (int i = 0;i < 2 * N;i++)
         {
             cout << i << ')' << ' ' << num[i] << '\t';
         }
         cout << endl;*/
    }
    /*cout << "the end"<<endl;
    for (int i = 0;i < 2 * N;i++)
    {
        cout << P[i] << ' ';
    }
    cout << endl;
    for (int i = 0;i < 2 * N;i++)
    {
        cout << S[i] << ' ';
    }*/
    /*cout << endl;*/
    for (int i = 0;i < 2 * N;i++)
    {
        cout << mice[i].num << ' ';
    }
    return 0;
}

void QuickSort(mouse a[], int low, int high)
{
    int i, j;
    mouse temp;
    i = low;
    j = high;
    if (low < high)
    {
        temp = a[low];
        while (i != j)
        {
            while (j > i && (a[j].P < temp.P || (a[j].P == temp.P)&&(a[j].num > temp.num)))
            {
                --j;
            }
            if (i < j)
            {
                a[i] = a[j];
                ++i;
            }

            while (i < j && (a[i].P > temp.P || (a[i].P == temp.P) && (a[i].num < temp.num)))
            {
                ++i;
            }
            if (i < j)
            {
                a[j] = a[i];
                --j;
            }
        }
        a[i] = temp;
        QuickSort(a, low, i - 1);
        QuickSort(a, i + 1, high);
    }
}

//void myswap(int a1, int a2, int b1, int b2, int c1, int c2)
//{
//    int temp[3];
//    temp[0] = a1;
//    temp[1] = b1;
//    temp[2] = c1;
//    a1 = a2;
//    b1 = b2;
//    c1 = c2;
//    a2 = temp[0];
//    b2 = temp[1];
//    c2 = temp[2];
//}

void BubbleSort(mouse a[], int len)
{
    int i, j;
    bool flag = false;
    for (i = 1;i < len;i++)
    {
        flag = true;
        for (j = 0;j < len - i;j++)
        {
            if (a[j + 1].P > a[j].P || (a[j + 1].P == a[j].P) && (a[j + 1].num < a[j].num))
            {
                mouse temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = false;
            }
        }
        if (flag) break;
    }
}
