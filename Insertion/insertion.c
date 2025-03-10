#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int *funcInsertData(int data[], int *size, int pos, int new_data);

int main()
{
    int size = MAX_SIZE, pos, value;

    int *data = calloc(MAX_SIZE, sizeof(int));

    for(int i = 0; i < MAX_SIZE; i++) data[i] = i * (i + 1);

    printf("Enter position to be modified: ");
    scanf("%d", &pos);
    printf("Enter value to be inserted: ");
    scanf("%d", &value);

    data = funcInsertData(data, &size, pos, value);

    for (int j = 0; j < size; j++) printf("%d ", data[j]);

    free(data);
}


int *funcInsertData(int data[], int *size, int pos, int new_data)
{
    (*size)++;
    pos -= 1;

    data = realloc(data, sizeof(int) * (*size));

    for (int i = *size - 1; i > pos; i--)
    {
        data[i] = data[i - 1];
    }

    data[pos] = new_data;

    return data;
}