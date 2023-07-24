//Linear Search Algorithm
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Enter the key element to be searched: ";
    cin >> key;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            cout << "Element found at index " << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Element not found";
    return 0;
}
