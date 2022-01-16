#include <iostream>
using namespace std;

/**
 * MEMBER FUNCTION NAME:
 *    getTotalWaterAmount
 * PURPOSE:
 *    The function calculates the water retention of
 *    a given terrain.
 * PARAMETER:
 *    int* arr, int size
 * RETURN VALUE:
 *    int: returns the maximum amount of retained water
 */
int getTotalWaterAmount(int* arr, int size)
{
    int* peak = &arr[0];
    int waterDeposit = 0;
    int* minorPeak = &arr[0];
    // find peak
    for(int i = 0; i < size; i++)
    {
        if(arr[i] >= *peak)
        {
            peak = &arr[i];
        }
    }
    // add water deposits from left to right
    for(int x = 0; x <= peak - &arr[0]; x++)
    {
        if(arr[x] < *peak && arr[x] > *minorPeak)
        {
            minorPeak = &arr[x];
        }
        else if(arr[x] < *peak && arr[x] < *minorPeak)
        {
            waterDeposit += *minorPeak - arr[x];
        }
    }
    // add water from right to left if final value isn't peak
    if(peak < &arr[size - 1])
    {
        minorPeak = &arr[size - 1];
        for(int y = size - 1; y > peak - &arr[0] + 1; y--)
        {
            if(arr[y] < *peak && arr[y] > *minorPeak)
            {
                minorPeak = &arr[y];
            }
            else if(arr[y] < *peak && arr[y] < *minorPeak)
            {
                waterDeposit += *minorPeak - arr[y];
            }
        }

    }

    return waterDeposit;
}
int main()
{
    // EXAMPLE
    int arr1[] = {5,2,1,2,1,5};
    cout << getTotalWaterAmount(arr1, sizeof(arr1)/sizeof(arr1[0])); // 14
    cout << endl;

    int arr2[] = {10, 20, 30 , 40, 42, 40, 30, 20, 40, 50, 55, 50, 40, 30, 20, 10, 3};
    cout << getTotalWaterAmount(arr2, sizeof(arr2)/sizeof(arr2[0]));
    cout << endl;

    int arr3[] = {0,1,0};
    cout << getTotalWaterAmount(arr3, sizeof(arr3)/sizeof(arr3[0]));
    cout << endl;

    int arr4[] = {1,2,3,4,5,6,5,4,3,6,22,3,2};
    cout << getTotalWaterAmount(arr4, sizeof(arr4)/sizeof(arr4[0]));
    cout << endl;

    int arr5[] = {0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8};
    cout << getTotalWaterAmount(arr5, sizeof(arr5)/sizeof(arr5[0]));
    cout << endl;

    int arr6[] = {5,4,1,2};
    cout << getTotalWaterAmount(arr6, sizeof(arr6)/sizeof(arr6[0]));
    cout << endl;

    int arr7[] = {5,2,1,3,1,5};
    cout << getTotalWaterAmount(arr7, sizeof(arr7)/sizeof(arr7[0]));
    cout << endl;

    return 0;
}
