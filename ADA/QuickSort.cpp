//quicksort algorithm implementation

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) //n
{
    int pivot = arr[e]; //1
    int i = s - 1; //1
    for (int j = s; j < e; j++) //n
    {
        if (arr[j] < pivot) //1
        {
            i++; //1
            swap(arr[i], arr[j]);  //1
        }
    }
    swap(arr[i + 1], arr[e]); //1
    return i + 1; //1
}

void quicksort(int arr[], int s, int e) //logn
{
    if (s < e)  //1
    {
        int p = partition(arr, s, e); //n
        quicksort(arr, s, p - 1); 
        quicksort(arr, p + 1, e);
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
    quicksort(arr, 0, n - 1); //logn
    cout << "Sorted array is: "; //1
    for (int i = 0; i < n; i++) //n
    {
        cout << arr[i] << " "; //n
    }
    printf("\nNAME: NANDINI SAIN");
    printf("\nENROLLMENT NO. : A2305221060");
    return 0; //1
}

// Time complexity of mergesort algorithm is O(nlogn) in all cases.
// Time complexity of quicksort algorithm is O(nlogn) in best and average cases and O(n^2) in worst case.
// Space complexity of mergesort algorithm is O(n).
// Space complexity of quicksort algorithm is O(logn) in best and average cases and O(n) in worst case.
//Counting the steps
// 1+1+1+1+1+n+1+1+1+1+1+1+1+1+1+1+1+1+1+n+n+logn+1+n+n+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+n+n
// = 9n + 2logn + 20
//O(nlogn)
