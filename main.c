#include <stdio.h>

//Tendero Beltrán, Antonio, 49428050S
//García Guirado, David
//García Marín, Jorge


// Swap 2 elements of the Array
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    // initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // condition 1: find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // condition 2: find the first element smaller than
        // the pivot (from last)
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // call Partition function to find Partition Index
        int partitionIndex = partition(arr, low, high);

        // Recursion to left and right
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// GREEDY ALGORITHM
int greedy(int weight[], int n, int totalWeight, int selected[]) {
    int j = 0, money = 0;
    quickSort(weight, 0, n); // SORT

    for (int i = 0; i < n; ++i) {
        if (weight[i] <= totalWeight) { // Check if another item stills fits
            selected[j] = weight[i]; // Include the weight of the selected item
            j++;
            money += 40; // Increment money
            totalWeight -= weight[i]; // Subtract the weight from the total weight left
        } else break;
    }
    return money; // Return total money and the array of selected items' weight
}

void main() {
    int list[20];
    int i = 0, input = 0;

    printf("Enter weight for each item:\n");
    while (input != -1) {
        scanf("%d", &input);
        if (input == -1) break;
        list[i] = input;
        i++;
    }

    printf("\nSorted list:\n");
    for (int j = 0; j < i; ++j) { // Print list sorted
        printf("%d\n", list[j]);
    }


    // GREEDY ALGORITHM
    int selected[i];
    int money = greedy(list, i, 20, selected);

    // Print results
    printf("Money = %d\n", money);
    printf("Selected items' weight:\n");
    for (int j = 0; j < i; ++j) { // Print list sorted
        printf("%d, ", list[j]);

    }
}
