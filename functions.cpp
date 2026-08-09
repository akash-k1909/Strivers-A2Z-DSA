#include<bits/stdc++.h>
using namespace std;

/*
void print(string s1){
    cout<<"hey "<<s1<<endl;
}
int main(){
    string s1;
    cin>>s1;
    print(s1);
    

    string s2;
    cin>>s2;
    print(s2);
    
return 0;

}

int sum(int num1,int num2){//can aslo do this by void 
    int num3=num1+num2;
    return num3;//kani ikkada cout<<num3
}
int main(){
    int num1,num2;
    cin>>num1>>num2;
    int final=sum(num1,num2);//ikkada sum(num1,num2) idokkati unte chalu inka cout<<finla avasarla 
    cout<<final;
    return 0;
}


//pass by value and reference 
void dosomething(string s){//ikkada &s pedite original will be sent so this  will be called pass by reference
    s[0]='t';
    cout<<s<<endl;
}
int main(){
    string s="raj";//this is pass value only copy will be sent 
    dosomething(s);
    cout<<s<<endl;
return 0;
}
*/
//now for for arrays
void dosomething(int arr[],int n){
    arr[0]+=10;
    cout<<"value inside func  :"<<arr[0]<<endl;

}
int main(){
    int n=5;
    int arr[n];
    
    for(int i=0;i<=4;i+=1){
        cin>>arr[i];
    }
    dosomething(arr,n);
    cout<<"value inside int main :"<<arr[0]<<endl;
    return 0;

}