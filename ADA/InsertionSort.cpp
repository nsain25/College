#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) //n
    {
        int current = arr[i]; //1
        int j = i - 1; //1
        while (arr[j] > current && j >= 0) //n
        {
            arr[j + 1] = arr[j]; //1
            j--;
        }
        arr[j + 1] = current; //1
    }
}

int main()
{
    int n; //1
    cout << "Enter the size of array: "; //1
    cin >> n; //1
    int arr[n]; //1
    cout << "Enter the elements of array: "; //1
    for (int i = 0; i < n; i++) //n
    {
        cin >> arr[i]; //n
    }
    insertion_sort(arr, n); //n^2
    cout << "Sorted array is: "; //1
    for (int i = 0; i < n; i++) //n
    {
        cout << arr[i] << " "; //n
    }
    printf("\nNAME: NANDINI SAIN");
    printf("\nENROLLMENT NO. : A2305221060");
    return 0; //1
}

// Time complexity of insertion sort algorithm is O(n^2).
