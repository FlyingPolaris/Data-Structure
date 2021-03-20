#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
using namespace std;
int arr[100005];

void QuickSort(int arr[], int low, int high)
{
    int i, j, temp;
    i = low;
    j = high;
    if (low < high)
    {
        temp = arr[low];
        while (i != j)
        {
            while (j > i&& arr[j] >= temp)
            {
                --j;
            }
            if (i < j)
            {
                arr[i] = arr[j];
                ++i;
            }

            while (i < j && arr[i] < temp)
            {
                ++i;
            }
            if (i < j)
            {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i] = temp;
        QuickSort(arr, low, i - 1);
        QuickSort(arr, i + 1, high);
    }
}
int main()
{
    int N, S;
    scanf("%d%d", &N, &S);
    for (int i = 0;i < N;i++) scanf("%d", &arr[i]);
    QuickSort(arr, 0, N - 1);
    int left = 0, right = 1000000005;
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        int temp = 0, num = 0;
        for (int i = 0;i < N;++i)
        {
            if (arr[i] >= temp)
            {
                num++;
                temp = arr[i] + mid;
            }
        }
        if (num < S) right = mid - 1;
        else left = mid;
    }
        printf("%d", left);
        return 0;
}

