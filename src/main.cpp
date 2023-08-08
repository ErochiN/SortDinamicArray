#include <iostream>

void PartSortArr(int *arr, int cols);
void SortRows(int **arr, int rows, int cols);
void SortArray(int **arr, int rows, int cols);
void RandArray(int **arr, int rows, int cols);
void ShowArray(int **arr, int rows, int cols);

void main()
{
    int rows = 4; // creating a two-dimensional array
    int cols = 5;
    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    RandArray(arr, rows, cols); // Calling a function that fills an array
    ShowArray(arr, rows, cols); // Displays an array on the screen
    std::cout << std::endl;

    SortArray(arr, rows, cols); // Sorts elements in arrays
    ShowArray(arr, rows, cols);
    std::cout << std::endl;

    SortRows(arr, rows, cols); // Sorts items in columns
    ShowArray(arr, rows, cols);
    std::cout << std::endl;

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

void RandArray(int **arr, int rows, int cols) // Fills an array with pseudo-random numbers
{
    for (int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            arr[i][j] = rand();
}

void ShowArray(int **arr, int rows, int cols) // Displays an array on the screen
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}

void PartSortArr(int *arr, int cols) // Sorting by choice
{
    for (int i = 1; i < cols; i++)
    {
        int sorted = i - 1;

        while (sorted > -1 && arr[sorted] > arr[sorted + 1])
        {
            int temp = arr[sorted];
            arr[sorted] = arr[sorted + 1];
            arr[sorted + 1] = temp;
            sorted--;
        }
        
    }
}

void SortArray(int **arr, int rows, int cols) // Recursion for sorting other arrays
{
    for (int i = 0; i < rows; i++)
        PartSortArr(arr[i], cols);
}

void SortRows(int **arr, int rows, int cols) // Sorts columns
{
    for (int j = 0; j < cols; j++)
    {
        for (int i = 1; i < rows; i++)
        {
            int sorted = i - 1;

            while (sorted > -1 && arr[sorted][j] > arr[sorted + 1][j])
            {
                int temp = arr[sorted][j];
                arr[sorted][j] = arr[sorted + 1][j];
                arr[sorted + 1][j] = temp;
                sorted--;
            }
            
        }
    }
}