#include <iostream>

using namespace std;


void insertionSort(int arr[], int size) {
    int i, value, j;
    for (i = 1; i < size; i++)
    {
        value = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = value;
    }
}

void print(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
    int arr[] = {1,7,8,5,3,6,4,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);
    print(arr, size);

    return 0;
}
