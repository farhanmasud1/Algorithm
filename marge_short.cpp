#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)//merge function to merge two subarrays
{
    int i = l;//left subarray index i.
    int j = m+1;//right subarray index j.
    int k = l;//temp array index k.
    int temp[5];//temp array temp.

    while(i<= m && j<=r)//comparing elements of left and right subarray
    {
        if(arr[i]<= arr[j])//if element of left subarray is less than or equal to element of right subarray.
        {
            temp[k] = arr[i];//copying element from left subarray to temp array.
            i++;
            k++;
        }
        else//if element of right subarray is less than element of left subarray.
        {
            temp[k] = arr[j];//copying element from right subarray to temp array.
            j++;
            k++;
        }

    }
    while(i<=m)//copying all elements from left subarray to temp as it is if right subarray is empty.
    {
        temp[k] = arr[i];
        k++;
        i++;

    }
    while(j<=r)//copying all elements from right subarray to temp as it is if left subarray is empty.
    {
        temp[k] = arr[j];
        k++;
        j++;

    }
    for(i = l; i<k; i++)//copying all elements from temp array to original array after merging.
    {
        arr[i]=temp[i];
    }
}
void mergeSort(int arr[],int l, int r)//merge sort function to sort array.
{
    if(l<r)//checking if left index is less than right index to check if array is not empty.
    {
        int m = (l+r)/2;//finding middle index m.
        mergeSort(arr,l,m);//calling merge sort function for left subarray.
        mergeSort(arr,m+1,r);//calling merge sort function for right subarray.
        merge(arr,l,m,r);//calling merge function.
    }
}
int main()
{
    int arr[5];//array of 5 elements arr.
    int number;
    cout<<"Enter number of elements : ";
    cin>>number;
    cout<<"Enter 5 element: "<<endl;
    for(int i = 0; i<number; i++)//taking input.
    {
        cin>>arr[i];
    }
    cout<<"Before mergesort"<<endl;
    for(int i =0; i<number; i++)//printing array before sorting.
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,number - 1);//calling merge sort function.
    cout<<endl<<"After mergesort"<<endl;
    for(int i=0; i<number; i++)//printing array after sorting.
    {
        cout<<arr[i]<<" ";
    }

}

