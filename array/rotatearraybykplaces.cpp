//left rotate array by k places


//brute force approach

vector<int> temp;
for(int i=0;i<d;i++){
    temp.push_back(arr[i]);
}
for(int i=d;i<n;i++){
    arr[i-d]=arr[i];
}
for(int i=n-d;i<n;i++){
    arr[i]=temp[i-n+d];
}

//optimal without using extra space
reverse(arr.begin(),arr.begin()+d);
reverse(arr.begin()+d,arr.end());
reverse(arr.begin(),arr.end());

//no extra space used, time complexity is O(n) and space complexity is O(1)