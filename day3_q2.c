int missingNum(int *arr, int size) {

    int n = size + 1;
    long long esum = (long long)n * (n + 1) / 2;
    long long asum = 0;

    for (int i = 0; i < size; i++) {
        asum += arr[i];
    }

    return (int)(esum - asum);
}