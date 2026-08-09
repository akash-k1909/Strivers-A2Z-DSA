
//left rotate an array by one
vector<int> leftrotatebyone(vector<int>arr,int n){
int temp=arr[0];
for(int i=1;i<n;i++){
    arr[i-1]=arr[i];

}
arr[n-1]=temp;
return arr;
}
//time complexity is O(n) and space complexity is O(1)
//space used in O(n) if theey asked in interview extra space is O(1)
