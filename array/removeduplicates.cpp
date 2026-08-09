//remove duplicates from sorted array
//unique means set
//method 1 using set

int removeduplicates(vector<int>a,int n){
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int index=0;
    for(auto it:s){
       a[index]=it;
       index++;
    }
    return index;
    // or return s.size();
}
//complexity nlogn+n,space is O(n) for set

//method 2 using two pointer approach

int i =0;
for(int j=1;j<n;j++){
    if(a[i]!=a[j]){
        a[i+1]=a[j];
        i++;
    }
}
return i+1;