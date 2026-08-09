#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min_index=i;
        for(int j=i;j<=n-1;j++){
            if (arr[j]<arr[min_index]) min_index=j;
        }
        //can use direct swap inbuilt method 

        //swap(arr[i],arr[min_index]);
        int temp=arr[min_index];//or temp swapping
        arr[min_index]=arr[i];
        arr[i]=temp;
    }//time complexity is worst,best,avg O(n^2) and space complexity is O(1) because if outer loop 1st iteration inner runs n times next n-1 ila add cheste sum of natural nums
}
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        int flag=0;
        for(int j=0;j<=i-1;j++){
            if (arr[j]>arr[j+1]){ 
                swap(arr[j],arr[j+1]);
                flag=1;}
        }  
        if (flag==0) break;
        cout<<"runs"<<endl;//if swap not hpnd then this wont be printed
    }//time complexity is n-1+n-2... so O(n^2) in worst and avg case and O(n) in best case when array is already sorted and space complexity is O(1)
}// so we can optimize this if no swaps hpnd then break 
void insertion_sort(int arr[],int n){//takes an element and places it in correct 
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;   }
    }
}
void merge(vector<int >&arr,int low,int mid,int high){//here we are passing by reference so that we can change the original array and not a copy of it and we are using temp vector to store the sorted elements and then copying them back to original array
    vector<int> temp;//here can also use arr[] but nervhukundam ani
    int left=low;
    int right=mid+1;//left arr lo start and right lo start compare chesta merge chestam

    while(left<=mid && right<=high){ 
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }}
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
}
void merge_sort(vector <int> &arr,int low,int high){
    if (low==high) return;
    int mid=(high+low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);//time complexity is O(nlogn) because we are dividing the array into two halves logn times and for each level we should go through all the elements so  O(n) time and space complexity is O(n) because we are using temp vector to store the sorted elements
}
int partition(vector <int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;

}
void quick_sort(vector <int> &arr,int low,int high){
    if(low>=high) return;
    int pindex=partition(arr,low,high);
    quick_sort(arr,low,pindex-1);
    quick_sort(arr,pindex+1,high);
}//time complexity is O(nlogn) in average and best case when pivot divides the array into two halves and O(n^2) in worst case when pivot is smallest or largest element and space complexity is O(logn) in average and best case and O(n) in worst case because of recursive stack space //normally its o(1) but here we are using recursion so we should consider stack space as well
int main(){
    int n;
    cin>>n;
    //int arr[n];
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //selection_sort(arr,n);
    //bubble_sort(arr,n);
    //insertion_sort(arr,n);
    //merge_sort(arr,0,n-1);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
