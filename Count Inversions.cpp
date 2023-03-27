/*https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0*/

#include <bits/stdc++.h> 

long long merge(long long arr[], int left, int mid, int right) {
    long long inv_count = 0;
    int i = left, j = mid, k = 0;
    long long temp[right - left + 1];

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inv_count;
}

long long mergeSort(long long arr[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid + 1, right);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}
