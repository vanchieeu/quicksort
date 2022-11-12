#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int *a, int l, int h) {
    int p = a[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (a[j] < p) {
            i++;
            swap(a+i, a+j);
        }
    }

    swap(a+i+1, a+h);
    return i++;
}

void quickSqort(int *a, int l, int h) {
    if (l < h) {
        int pi = partion(a, l, h);
        quickSqort(a, l, pi - 1);
        quickSqort(a, pi + 1, h);
    }
}

void coutArray(int *a, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    quickSqort(a, 0, n-1);

    coutArray(a, n);

    return 0;
}