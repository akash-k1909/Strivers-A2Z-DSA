#include<bits/stdc++.h>
using namespace std;
/*this is basic hashinig technique to count freq of ele in array
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    //okavela has array ikkada declare cheste ={0} itla pettanavasarledu as default zeroes but in main if we din it gives garbage values
    //precompute
    int hash[13]={0};//here we are initializing the hash array with 0
    for(int i=0;i<n;i++){//can keep size of hash array 10power6 at max in main but in global i mean outside main 10power7 for int and for bool in main 10power7 and global 10power8
        hash[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<hash[num]<<endl;
    }

}//actual ga number hashing lo 10pow6 kanna ekkuva pettalante we use 
    */
   //below is for character hashing 
/*int main(){
    string s;//for suppose if its given small letters or capitals we can take hash array of 26 if not mentioned should take 256  as total are 256 from 0 to 255 in ascii table
    cin>>s;
    int hash[26]={0};//but if we dont know can keep 256 and in below for loop we can do hash[s[i]]++ 
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;//for small letters
    }//hash bracket loki it always needs integer so even if we character itll be converted to its corres ascii
    //i.e autocast to int
    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<hash[ch-'a']<<endl;//if we use 256 we should do hash[ch]
    }
}*/
//actual ga number hashing lo 10pow6 kanna ekkuva pettalante we use map its actually in stl video
int main(){
    int n;
    cin>>n;
    int arr[n];
    //also we can precompute while taking input itself
    /*//aslo we can use map for string hashing map<char,int> mpp;
    map<int,int> mpp;
      for (int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++; like this
    }

    */
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    //pre-compute
    //here we are only storing what are there in the array and reemainng will automat willl be zero
    //in key value pair we are storing the element and its freq
    map<int,int> mpp;//can use unordered_map
    for (int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    //can also iterate in the map
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
   int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<mpp[num]<<endl;
        //also importsnt thing map stores all the values in sorted order so if we want to print all the values in sorted order we can do it easily by iterating the map
    }//for map time complexity is O(logn) for insertion and fetching worst ,best,avg all are logn
}
