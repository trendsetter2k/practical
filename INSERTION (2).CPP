#include<iostream>
using namespace std;
//insertion sort
void insertionSort(int*arr,int size){

}
int main(){
    int size;
    int *arr;
    cout<<"enter you array size: "<<endl;
    cin>>size;
    arr=new int[size];
    cout<<"enter your elements"<<endl;
    for(int i=0;i<size;i++){
        cout<<"enter element for index "<<i<<" :";
        cin>>arr[i];
    }
    int compare=0;
    for(int i=1;i<size ;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0){
            compare++;
            if(arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1]=key;
    }
    cout<<"\n sorted array: ";
    for(int k=0;k<size;k++){
        cout<<arr[k]<<" ";
    }
    cout<<"no. of comparisons are : "<<compare<<endl;

}