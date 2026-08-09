//sorted in non decreasing order
bool issorted(int n,vector<int>a){
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            return false;
        }
    }
    return true;
}