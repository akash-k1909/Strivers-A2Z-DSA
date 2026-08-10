//union of sorted arrays using brute force

 #include <bits/stdc++.h>
 using namespace std;
 vector<int> unionBruteForce(vector<int> arr1, vector<int> arr2) {
    int n1=arr1.size();
    int n2=arr2.size();
    set<int>s;
    for(int i=0;i<n1;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(arr2[i]);
    }
    vector<int>temp;
    for(auto it :s){
        temp.push_back(it);
    }
    return temp;
 }
//using optimal approach

vector<int>sortedarray(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int>unionarr;
    while(i<n1 && j<n2){
       if(a[i]<=b[j]){
        if(unionarr.size()==0 || unionarr.back()!=a[i]){
            unionarr.push_back(a[i]);
        }
        i++;
       } 
       else{
        if(unionarr.size()==0 || unionarr.back()){
            unionarr.push_back(b[j]);
        }
        j++;
       }

    }
    while(j<n2){
        if(unionarr.size()==0 || unionarr.back()){
            unionarr.push_back(b[j]);
        }
        j++;

    }
    while(i<n1){
         if(unionarr.size()==0 || unionarr.back()!=a[i]){
            unionarr.push_back(a[i]);
        }
        i++;

    }

    return unionarr;
}
 

//intersection of ssorted arrays using brute force

//brute force approach

for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(a[i]==b[j] && visited[j]==0){
            intersection.push_back(a[i]);
            visited[j]=1;
            break;
        }
        if(b[j]>a[i]){
            break;
        }
    }

}

//optimal approach
int i=0;
int j=0;
vector<int>intersection;
while(i<n1 && j<n2){
    if(a[i]<b[j]){
        i++;
    }
    else if(a[i]>b[j]){
        j++;
    }
    else{
        intersection.push_back(a[i]);
        i++;
        j++;
    }
    return intersection;

}





