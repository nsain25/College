//Fractional Knapsack Problem

#include <iostream>
using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    cout << "\nThe result vector is:- ";
    for (i = 0; i < n; i++)
        cout << x[i] << "\t";

    cout << "\nMaximum profit is:- " << tp;
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    cout << "\nEnter the no. of objects:- ";
    cin >> num;

    cout << "\nEnter the wts and profits of each object:- ";
    for (i = 0; i < num; i++)
    {
        cin >> weight[i] >> profit[i];
    }

    cout << "\nEnter the capacity of knapsack:- ";
    cin >> capacity;

    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    printf("\nNAME: NANDINI SAIN");
    printf("\nENROLLMENT NO. : A2305221060");
    return 0;
}

// Time complexity of fractional knapsack algorithm is O(nlogn).
// Counting the steps
// = 7 + 6n + 6nlogn
// = 6nlogn + 6n + 7
// = O(nlogn)
