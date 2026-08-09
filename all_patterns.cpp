#include<bits/stdc++.h>
using namespace std;
void patternp1(int n){
    for(int i=0;i<n;i+=1){
    
        for(int j=0;j<n;j+=1){
            cout<<"* ";
        }
        cout<<endl;
}}
void patternp2(int n){
    for(int i=0;i<n;i+=1){
        for(int j=0;j<=i;j+=1){
            cout<<"* ";
        }
        cout<<endl;
}}
void patternp17(int n){
    for(int i=0;i<n;i++ ){
        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //character
        char ch='A';
        int breakpoint=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){
            cout<<ch;
            if(j<=breakpoint) ch++;//ivi jarige iteration lo ch remeber cheskuniddi but for dataka again ch paina emicham oo danto start ayiddi 
            else ch--;
        }
        //ii line lo cout<<ch pettina ans vastadi kani j<2*i+1 ani pettali

        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void patternp19(int n){
    //int inis=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*i;j++){//j<inis
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        //inis+=2;
        cout<<endl;
    }
    //int inis=2*n-2
     for(int i =1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*(n-i);j++){//j<inis
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //inis-=2;
        cout<<endl;
    }
}

    
   

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i+=1){
        int n;
        cin>>n;//in backend for contest they ll check for these many test cases
        patternp19(n);
    }
}