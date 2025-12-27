#include<iostream>
using namespace std;

int low =0,high =9,mid;

    int b_s(int arr[],int num)
{
    while(low<high)
    {

        mid=(low+high)/2;
        if(num==arr[mid])
        {
            //high=mid;
            return mid;
        }
        else if(num<arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}
int b_si(int arr[],int num)
{


    while(low<high)
    {

        mid=(low+high)/2;
        if(num==arr[mid])
        {
            high=mid;
            return mid;
        }
        else if(num<arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

   

int main(){
    int arr[10];
    int num;

    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    cin>>num;

    int result = b_s(arr,num);
    int res = b_si(arr,num);
    int r =result -res+1;
    cout<<endl;
}