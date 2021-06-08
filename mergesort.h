#ifndef METALSHEET_CPP_MERGESORT_H
#define METALSHEET_CPP_MERGESORT_H



#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort((*this), l, m);
        mergeSort((*this), m + 1, r);
        merge((*this), l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    int i = 0;
    int j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}



// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

#endif //METALSHEET_CPP_MERGESORT_H