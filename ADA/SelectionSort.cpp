#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i; //1
        for (int j = i + 1; j < n; j++) //n
        {
            if (arr[j] < arr[min]) //1
            {
                min = j; //1
            }
        }
        swap(arr[i], arr[min]); //1
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
    selection_sort(arr, n); //n^2
    cout << "Sorted array is: "; //1
    for (int i = 0; i < n; i++) //n
    {
        cout << arr[i] << " "; //n
    }
    printf("\nNAME: NANDINI SAIN");
    printf("\nENROLLMENT NO. : A2305221060");
    return 0; //1
}

//Time complexity of selection sort algorithm is O(n^2).
