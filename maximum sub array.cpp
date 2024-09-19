#include<iostream>

using namespace std;


int max(int a, int b)
{
    return (a > b)? a:b; // using ternary operator
}


int  MaxCrossingSum (int arr[], int low, int mid, int high)
{

    int sum = 0;
    int leftpartsum = -1;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if (sum > leftpartsum)
            leftpartsum = sum;
    }


    sum = 0;
    int rightpartsum = -1;
    for (int i = mid+1; i <= high; i++)
    {
        sum = sum + arr[i];
        if (sum > rightpartsum)
            rightpartsum = sum;
    }


    return leftpartsum + rightpartsum;
}


int MaxSubArraySum(int arr[], int low, int high)
{
    int mid;

    if (low == high)
        return arr[low];


    mid = (low + high)/2;
    int  max_sum_left_subarray = MaxSubArraySum(arr, low, mid);
    int max_sum_right_subarray =  MaxSubArraySum(arr, mid+1, high);
    int  max_sum_crossing_subarray = MaxCrossingSum(arr, low, mid, high);

    return max(max(max_sum_left_subarray,max_sum_right_subarray),max_sum_crossing_subarray  );
}

int main()
{
    int n, i;
    cout<<"Enter the number of data element in the array: ";
    cin>>n;

    int a[n];
    cout<<"Enter element "<<endl;
    for(i = 0; i < n; i++)
    {

        cin>>a[i];
    }


    cout<<"Maximum sub-array sum is: "<<MaxSubArraySum(a, 0, n-1);

    return 0;
}

