#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++)
         {  
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
