#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), cmp);
    
    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int min_left = left, min_right = right;
    
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            min_left = left;
            min_right = right;
        }
        
        if (current_sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    printf("%d %d\n", arr[min_left], arr[min_right]);
    
    return 0;
}