#include <iostream>
using namespace std;
void merge(int *arr,int start,int end)
{
    int mid=start+((end-start)/2);
    int len1=mid-start+1;
    int len2=end-mid;
    int *arr1=new int[len1];
    int *arr2=new int[len2];
    int k=start;
    for(int x=0;x<len1;x++)
    {
        arr1[x]=arr[k++];
    }
    k=mid+1;
    for(int x=0;x<len2;x++)
    {
        arr2[x]=arr[k++];
    }
    int index1=0;
    int index2=0;
     k=start;
    while(index1<len1 && index2<len2)
    {
        if(arr1[index1]<arr2[index2])
        {
            arr[k++]=arr1[index1++];
        }
        else
        {
            arr[k++]=arr2[index2++];
        }
    }
    while(index1<len1)
    {
        arr[k++]=arr1[index1++];

    }
    while(index2<len2)
    {
        arr[k++]=arr2[index2++];
    }
    delete []arr1;
    delete []arr2;



}
void mergesort(int arr[],int start,int end)
{
    //base case
    if(start>=end)
    {
        return;
    }
    int mid=start+((end-start)/2);
    //left part
    mergesort(arr,start,mid);
    //right part
    mergesort(arr,mid+1,end);
    //merging both
    merge(arr,start,end);
}
int main() {
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Let's fill the array"<<endl;
    for(int x=0;x<size;x++)
    {
        cin>>arr[x];
    }
    mergesort(arr,0,size-1);
    cout<<"The sorted array is : "<<endl;
    for(int x=0;x<size;x++)
    {
        cout<<arr[x]<<endl;
    }

}
