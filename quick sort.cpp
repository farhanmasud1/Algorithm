#include<iostream>

using namespace std;

void swap(int arr[], int i, int j)

{

    int temp = arr[i];

    arr[i] = arr[j];

    arr[j] = temp;

}


int partition(int arr[], int l, int r)

{

    int pivot = arr[r];

    int i = l -1;


    for(int j = l; j<r; j++)

    {

        if(arr[j] < pivot)

        {

            i++;

            swap(arr, i, j);

        }

    }

    swap(arr, i+1, r);

    return i+1;


}


void quickSort(int arr[],int l, int r)

{

    if(l<r)

    {

        int pi = partition(arr, l,r);

        quickSort(arr, l, pi-1);

        quickSort(arr, pi+1, r);


    }

}




int main()

{

    int arr[100],n,i;

    cout<<"Enter number of element :";

    cin>>n;

    cout<<"Enter elements : "<<endl;

    for(i = 0; i<n; i++)

    {

        cin>>arr[i];

    }

    cout<<endl<<"Before Quicksort"<<endl;

    for(i = 0; i<n; i++)

    {

        cout<<arr[i]<<" ";

    }

    quickSort(arr, 0,n-1);

    cout<<endl<<endl<<"After Quicksort"<<endl;

    for(i = 0; i<n; i++)

    {

        cout<<arr[i]<<" ";

    }

    cout<<endl;


}
