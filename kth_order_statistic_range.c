#include "stdio.h"

void quick_sort(int*, int, int, int, int);
int split(int*, int, int);

int main()
{
    int arr[] = { 0, 2, 1, 6, 4, 5, 3, 8, 7, 9 };
    int arr_len = 10;
    int i;

    /*
     * We need to figure out what elements will be on positions from 5 through 9
     * in a sorted array
     */
    int kth_from = 5;
    int kth_to = 9;

    quick_sort(arr, 0, arr_len - 1, kth_from, kth_to);

    for (i = kth_from; i <= kth_to; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/*
 * Sorting using quick sort algorithm
 *
 * @arr: source array to be sorted
 * @left: left boundary of partition of the array which needs to be sorted
 * @right: right boundary of partition of the array which needs to be sorted
 * @kth_from: left boundary of kth statistic
 * @kth_to: right boundary of kth statistic
 */
void quick_sort(int *arr, int left, int right, int kth_from, int kth_to)
{
    if (left == right || left > kth_from || right < kth_to)
        return;

    int mid = split(arr, left, right);

    quick_sort(arr, left, mid, kth_from, kth_to);
    quick_sort(arr, mid + 1, right, kth_from, kth_to);
}

/*
 * Spliting the array into two parts of approximately same size and
 * swapping two values: leftmost one which more than middle value and
 * rightmost one which less than middle value
 *
 * @arr: source array to be splitted
 * @left: left boundary of partition of the array which needs to be splitted
 * @right: right boundary of partition of the array which needs to be splitted
 */
int split(int *arr, int left, int right)
{
    /* Middle value of the given array */
    int mid = arr[(left + right) / 2];

    /* Left and right counters */
    int left_i = left, right_i = right;

    /* Temporary variable for swapping two values */
    int tmp;

    while (left_i <= right_i) {
        while (arr[left_i] < mid)
            left_i++;
        while (arr[right_i] > mid)
            right_i--;

        if (left_i <= right_i) {
            tmp = arr[left_i];
            arr[left_i] = arr[right_i];
            arr[right_i] = tmp;

            left_i++;
            right_i--;
        }
    }

    return mid;
}