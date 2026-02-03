#include <stdio.h>

int binarySearch(int v[], int key, int start, int end) {

    int meio = ((start + end) / 2) + ((end - start) % 2);

    if (end < start) {
        return -1;
    }
    else if (v[meio] == key) {
        return meio;
    }
    else if (v[meio] < key) {
        return binarySearch(v, key, meio, end);
    }
    else {
        return binarySearch(v, key, start, meio);
    }

}


int main() {
    int n, key, start = 0, end, res = 0;
    printf("Choose the size of the array: ");
    scanf("%d", &n);
    end = n - 1;

    int v[n];
    printf("Choose the values for the array: ");
    for (int w = 0; w < n; w++) {
        scanf("%d", &v[w]);
    }

    printf("Choose the key for search: ");
    scanf("%d", &key);

    int temp = 0;

    for (int t = 0; t < n - 1; t++) {
        for (int i = 0;i < n - t - 1; i++) {
            if (v[i] > v[i + 1]) {
                temp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = temp;
            }
        }
    }

    res = binarySearch(v, key, start, end);
    res != -1 ? printf("The key was found on the %d position of the array;", res + 1) : printf("The key is not on the array");

    return 0;
}