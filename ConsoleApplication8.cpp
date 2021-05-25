#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void quickSort(int* numbers, int left, int right)
{
    int pivot; 
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) 
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; 
        if (left != right) 
        {
            numbers[left] = numbers[right]; 
            left++; 
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; 
        if (left != right) 
        {
            numbers[right] = numbers[left]; 
            right--; 
        }
    }
    numbers[left] = pivot; 
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) 
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}
int main()
{
    int a[SIZE];
   
    for (int i = 0; i < SIZE; i++)
        a[i] = rand() % 200 - 100;

    for (int i = 0; i < SIZE; i++)
        printf("%4d ", a[i]);
    printf("\n");
    quickSort(a, 0, SIZE - 1); 
    
    for (int i = 0; i < SIZE; i++)
        printf("%4d ", a[i]);
    printf("\n");
 
    return 0;
}