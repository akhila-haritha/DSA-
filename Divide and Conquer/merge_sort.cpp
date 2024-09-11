#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void merge_sort(vector<int>&a,int l,int r);
void merge(vector<int>&a,int l,int m,int r);

void merge_sort(vector<int>&a,int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);}
}

void merge(vector<int>&a,int l,int m,int r){
    int n1 = m-l+1,n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)L[i] =a[l+i];
    for(int j=0;j<n2;j++)R[j] = a[m+1+j];
    int temp[n1+n2];
    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            a[k++] = L[i++];}
        else{
            a[k++] = R[j++];}

    }

    while(i<n1){
        a[k++] = L[i++];}
    
    while(j<n2){
        a[k++] = R[j++];}
    
    

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
    merge_sort(a,0,n);
    //printing elements
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
    
}
