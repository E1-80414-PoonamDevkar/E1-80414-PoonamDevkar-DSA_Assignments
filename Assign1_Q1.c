#include <stdio.h>

int linearSearchRecursive(int arr[], int key, int index, int size);
int binarySearchRecursive(int arr[], int key, int left, int right);


int main()
 {
    int arr[] = {10,20,30,40,50,70,60,80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int linearIndex = linearSearchRecursive(arr, key, 0, size);
    int binaryIndex = binarySearchRecursive(arr, key, 0, size - 1);

    if (linearIndex != -1) 
    {
        printf("Linear Search: Element %d found at index %d\n", key, linearIndex);
    }
     else 
    {
        printf("Linear Search: Element %d not found in the array\n", key);
    }

    if (binaryIndex != -1) 
    {
        printf("Binary Search: Element %d found at index %d\n", key, binaryIndex);
    }
     else
    {
        printf("Binary Search: Element %d not found in the array\n", key);
    }

    return 0;
}


int linearSearchRecursive(int arr[], int key, int index, int size) 
{
    if (index == size)
    {
        return -1; 
    }

    if (arr[index] == key) 
    {
        return index; 
    }

    return linearSearchRecursive(arr, key, index + 1, size);
}


int binarySearchRecursive(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1; 
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) 
    {
        return mid; 
    } else if (arr[mid] > key) 
    {
        return binarySearchRecursive(arr, key, left, mid - 1);
    }
     else
    {
        return binarySearchRecursive(arr, key, mid + 1, right);
    }
}