#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void print(){
    if(cnt==3) return;
    cout<<cnt<<endl;
    cnt++;
    print();
}
void print_n_times_meth1(int n){
    if (n==0) return;
    cout<<"hi"<<endl;
    print_n_times_meth1(n-1);
}    
void print_n_times_meth2(int i,int n){
    if(i>n) return;
    cout<<"hi"<<endl;
    print_n_times_meth2(i+1,n);//time complexity is O(n) and space complexity is O(n) because of recursive stack
    //actually this wont use extra space like taking array but uses internal memory which is stack space 
}
void print_1_to_n_meth1(int n){
    if (n==0) return;
    print_1_to_n_meth1(n-1);
    cout<<n<<" ";
}
void print_1_to_n_meth2(int i,int n){
    if (i>n) return;
    cout<<i<<" ";
    print_1_to_n_meth2(i+1,n);}
void print_n_to_1_meth1(int n){
    if (n==0) return;
    cout<<n<<" ";
    print_n_to_1_meth1(n-1);
}
void print_n_to_1_meth2(int i,int n){
    if(i<1) return;
    cout<<i<<" ";
    print_n_to_1_meth2(i-1,n);
}
void print_1_to_n_meth3(int i,int n){
    //shouldnot use i+1
    if (i<1) return;
    print_1_to_n_meth3(i-1,n);
    cout<<i<<" ";
}
void print_n_to_1_meth3(int i,int n){
    //should not use i-1
    if(i>n) return;
    print_n_to_1_meth3(i+1,n);
    cout<<i<<" ";
}
void sum_of_n_meth1(int i,int sum){//parametrized function
    if(i<1){
        cout<<sum;
        return;
    }
    sum_of_n_meth1(i-1,sum+i);
}
int sum_of_n_meth2(int n){//functional recursion
    if(n==0) return 0;
    return n + sum_of_n_meth2(n-1); 
}
int fact(int n){
    if (n==1) return 1;
    return n*fact(n-1);//time complexity is O(n) and space complexity is O(n) because of recursive stack coz all functions are waiting for the result of the next function call and they are stored in the stack until the base case is reached and then they start returning values and getting popped out of the stack
}
void rev_arr(int i,int arr[],int n){//in arrays it is passed by reference so we can change the original array
    /*method 1 by using two pointers
    void rev_arr(int arr[],int n,int st,int lst){
        if(st>=lst) return;
        swap(arr[st],arr[lst]);
        rev_arr(arr,n,st+1,lst-1);
    }*/
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    rev_arr(i+1,arr,n);
}
bool is_palindrome(int i,string s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return is_palindrome(i+1,s);//time complexity is O(n/2) coz we go till n/2 only and space complexity is O(n/2) because of recursive stack
//also this auxillary space we arent using any new data structure we are just using the recursive stack 
}
int fibonacci(int n){
    if (n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);//time complexity is O(2^n) because we are making two recursive calls for each function call and space complexity is O(n) because of recursive stack

}
int main(){
    //print();
    int n;
    cin>>n;
    //print_n_times_meth1(n);
    //print_n_times_meth2(1,n);
    //print_1_to_n_meth1(n);
    //print_1_to_n_meth2(1,n);
    //print_n_to_1_meth1(n);
    //print_n_to_1_meth2(n,n);
    //print_1_to_n_meth3(n,n);
    //print_n_to_1_meth3(1,n);
    //sum_of_n_meth1(n,0);
    //cout<<sum_of_n_meth2(n);
    //cout<<fact(n);
    /*
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rev_arr(0,arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    */
   /*string s;
   cin>>s;
    cout<<is_palindrome(0,s);
    */
   cout<<fibonacci(n);

    

    return 0;
}