//Mergesort algorithm implementation along with step counts

#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) 
{
    int mid = (s + e) / 2; //1
    int i = s; //1
    int j = mid + 1; //1
    int k = s; //1
    int temp[100]; //1
    while (i <= mid && j <= e)  //n
    {
        if (arr[i] < arr[j]) //1
        {
            temp[k++] = arr[i++]; //1
        }
        else
        {
            temp[k++] = arr[j++];   //1
        }
    }
    while (i <= mid) //n
    {
        temp[k++] = arr[i++]; //1
    }
    while (j <= e) //n
    {
        temp[k++] = arr[j++]; //1
    }
    for (int i = s; i <= e; i++) //n
    {
        arr[i] = temp[i]; //1
    }
}

void mergesort(int arr[], int s, int e) //logn
{
    if (s < e) //1
    {
        int mid = (s + e) / 2; //1
        mergesort(arr, s, mid); 
        mergesort(arr, mid + 1, e); 
        merge(arr, s, e); 
    }
}

int main()
{
    int n; //1
    cout << "Enter the size of array: "; //1
    cin >> n; //1
    int arr[n]; //1
    cout << "Enter the elements of array: ";  //1
    for (int i = 0; i < n; i++) //n
    {
        cin >> arr[i]; //n
    }
    mergesort(arr, 0, n - 1); //logn
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
//Counting the steps:
// 1 + 1 + 1 + 1 + 1 + 1 + n + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + n + n + n + n + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + n + n + 1
// = 9 + 7n + 3nlogn
// = O(nlogn)
