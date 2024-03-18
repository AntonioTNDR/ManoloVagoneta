#include <stdio.h>

/*
    GREEDY ALGORITHMS ASSIGNMENT
    - Tendero Beltrán, Antonio (49428050S)
    - García Guirado, David (55052860Z)
    - García Marín, Jorge (49314477Q)
*/


// Declaration of functions (SORTING ALGORITHM)
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);


// GREEDY ALGORITHM
int greedy(int weight[], int n, int totalWeight, int selected[]) {
    int money = 0, currentWeight = 0;
    if (n > 1) mergeSort(weight, 0, n-1); // SORT (only when more than 1 element)

    for (int i = 0; i < n; ++i) {
        if (currentWeight + weight[i] <= totalWeight) { // Check if another item stills fits
            selected[i] = weight[i]; // Include the weight of the selected item
            money += 40; // Increment money
            currentWeight += weight[i]; // Subtract the weight from the total weight left
        } else break;
    }
    return money; // Return total money and the array of selected items' weight
}

void main() {
    int list[20]; // CANDIDATES (up to 20)
    int i = 0, input = 0;

    // Ask for the input (Candidates)
    printf("Enter weight for each item:\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        list[i] = input;
        i++;
    }

    // GREEDY ALGORITHM >>> Store selected elements in array 'selected'
    int selected[i];
    int money = greedy(list, i, 20, selected);

    // Print results = Money + Selected items
    printf("Money = %d\n", money);
    printf("Selected items' (%d) weight:\n", money/40);
    for (int j = 0; j < money/40; ++j) { // Print list sorted (money/40 = Nº elements)
        printf("%d, ", selected[j]);
    }
}


// MERGE SORT ALGORITHM
// l = left-most index of the array | r = right-most index of the array
void mergeSort(int arr[], int l, int r) {
    if (l < r) { // Only if more than 1 element OR right arguments (l < r)
        int m = l + (r - l) / 2; // Index in the middle of the array

        // Sort 1st and 2nd halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the already sorted halves
        merge(arr, l, m, r);
    }
}

// Merges the 2 sub-arrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Length of the 1st array = arr[l..m]
    int n2 = r - m; // Length of the 2nd array = arr[m+1..r]

    // Create temp arrays AND initialize with argument data
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { // Include element from the left if smaller
            arr[k] = L[i];
            i++;
        }
        else { // Include element from the right if bigger
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] (if any)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] (if any)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
