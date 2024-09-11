#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void quick_sort(vector<int>&a,int l,int r);
int partiton(vector<int>&a,int l,int r);

void quick_sort(vector<int>&a,int l,int r){
    if(l<r){
        int pivot = partiton(a,l,r);
        quick_sort(a,l,pivot-1);
        quick_sort(a,pivot+1,r);
    }
}

int partiton(vector<int>&a,int l,int r){
    
    int pivot = a[l]; int pos = l;
    int i=l+1, j=r;
    while(i<j){
        while(a[i]<pivot)i++;
        while(a[j]>pivot)j--;

        if(a[i]>pivot && a[j]<pivot){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
            }
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;

}


int main(){
    int n;
    cout<<"Enter the number of elements: ";
    //no.of elements
    cin>>n;
    //declare variables for mn and mx
    int mn = INT_MAX, mx = INT_MIN;
    vector<int>a;
    cout<<"\nReading elements from user input: ";
    //reading elements from user input
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        a.push_back(s);}
    //apply function
    quick_sort(a,0,n-1);
    //printing elements
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
    
}
