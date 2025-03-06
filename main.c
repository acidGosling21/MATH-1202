#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COUNT 8

void swapValues(int *value_1, int *value_2);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

void printArray(int array[]);

int main()
{
    int example_array[] = {97, 5, 2, 45, 87, 1, 34, 56};
    char input;

    while(true)
    {
        int copy_array[MAX_COUNT];
        memcpy(copy_array, example_array, sizeof(int) * MAX_COUNT);

        printf("\nEnter input selection [s] [b] [i] [q] - exit: ");
        scanf("%c", &input);
        getchar();

        switch (input)
        {
            case 's':
                selectionSort(copy_array, MAX_COUNT);
                printArray(copy_array);
                break;
            case 'b':
                bubbleSort(copy_array, MAX_COUNT);
                printArray(copy_array);
                break;
            case 'i':
                insertionSort(copy_array, MAX_COUNT);
                printArray(copy_array);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid character selection! \n");
        }
    }


    return 0;
}

void swapValues(int *value_1, int *value_2)
{
    int l_temp = *value_1;
    *value_1 = *value_2;
    *value_2 = l_temp;
}

void selectionSort(int arr[], int n)
{
    int L_min_index;

    for(int i = 0; i < n - 1; i++)
    {
        L_min_index = i;
        
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[L_min_index])
            {
                L_min_index = j;
            }
        }

        swapValues(&arr[i], &arr[L_min_index]);
    }
}

void bubbleSort(int arr[], int n)
{
    bool isSwapped;

    for(int i = 0; i < n - 1; i++)
    {
        isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swapValues(&arr[j], &arr[j + 1]);
                isSwapped = true;
            }
        }

        if(!isSwapped) break;
    }
}

void insertionSort(int arr[], int n)
{
    int L_key, x;

    for(int i = 1; i < n; i++)
    {
        L_key = arr[i];

        while(x >= 0 && arr[x] > L_key)
        {
            arr[x + 1] = arr[x];
            x -= 1;
        }
        
        arr[x + 1] = L_key;
    }
}

void printArray(int array[])
{
    for (int i = 0; i < MAX_COUNT; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}