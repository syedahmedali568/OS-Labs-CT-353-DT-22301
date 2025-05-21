#include <stdio.h>

// Function to update the array in most recently used fashion
void recently(int* arr, int size, int elem)
{
    int index = elem % size;
    int temp = index;
    int id = arr[index];

    // Shift elements from index to 1 position right
    while (temp > 0)
    {
        arr[temp] = arr[temp - 1];
        temp--;
    }

    // Place the element at the front
    arr[0] = id;
}

// Function to print array elements
void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int elem = 3;
    int arr[] = { 6, 1, 9, 5, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    recently(arr, size, elem);
    printf("Array in most recently used fashion: ");
    print(arr, size);

    return 0;
}
