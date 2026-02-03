#include <stdio.h>

// Function that sorts an array using the "count of smaller elements" method
void contagem_menores(int* vector, int n) {
    int aux[n];       // Temporary array to store the sorted values
    int auxi = 0;     // Not used in the current implementation (can be removed)
    int count = 0;    // Counter for how many elements are smaller than the current element

    // Main loop to compute the count of smaller elements for each element
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            // Count how many elements are smaller than vector[i]
            // If equal, use index to maintain stability (preserve order of equal elements)
            if (vector[j] < vector[i] || (vector[j] == vector[i] && j < i)) count++;
        }
        aux[count] = vector[i];  // Place the element in the position corresponding to its count
    }

    // Copy the sorted elements back to the original array
    for (int k = 0; k < n; k++) {
        vector[k] = aux[k];
    }
}

int main() {
    int n;

    // Ask the user for the size of the array
    printf("Write the size of the array:");
    scanf(" %d", &n);

    int p[n]; // Declare the array with size n

    // Prompt the user to input the array elements
    printf("Write the %d numbers within the array:", n);
    int aux;  // This variable is unused in the current implementation
    for (int w = 0; w < n; w++) {
        scanf(" %d", &p[w]);
    }
    printf("\n");

    // Print the array before sorting
    printf("****************\n");
    printf("Before the sort: {");
    for (int z = 0; z < n; z++) {
        printf("%d ", p[z]);
    }

    //! Call the sorting function
    contagem_menores(p, n);

    printf("}");
    printf("\n");
    printf("****************");
    printf("\n\n");

    // Print the array after sorting
    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", p[y]);
    }
    printf("}");
    printf("\n");
    printf("****************");
}
