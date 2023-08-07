#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) //n
    {
        for (int j = 0; j < n - i - 1; j++) //n
        {
            if (arr[j] > arr[j + 1]) //1
            {
                swap(arr[j], arr[j + 1]); //1
            }
        }
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
    bubble_sort(arr, n); //n^2
    cout << "Sorted array is: "; //1
    for (int i = 0; i < n; i++) //n
    {
        cout << arr[i] << " "; //n
    }
    printf("\nNAME: NANDINI SAIN");
    printf("\nENROLLMENT NO. : A2305221060");
    return 0; //1
}


// Time complexity of bubble sort algorithm is O(n^2).
