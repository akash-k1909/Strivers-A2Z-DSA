//move all zeros to the end of the array
//brute force approach
vector<int> temp;
for(int i=0;i<n;i++){
    if(arr[i]!=0){
        temp.push_back(arr[i]);
    }
}
for(int i=0;i<temp.size();i++){
    arr[i]=temp[i];
}
for(int i=temp.size();i<n;i++){
    arr[i]=0;
}
//time complexity is n+x+n-x so O(n) and space complexity is O(n) for temp array

//optimal approach using two pointer approach


//first find the first zero in the array and then swap it with the next non zero element
int j=-1;
for(int i=0;i<n;i++){
    if(arr[i]==0){
        j=i;
        break;
    }
}
//j is pointing to 0 always and i is pointing to non zero element
for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
    }
}
//time complexity x+n-x is O(n) and space complexity is O(1)

