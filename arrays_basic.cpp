#include<bits/stdc++.h>
using namespace std;
int largest_element(vector<int> &arr,int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}//this is optimal time is O(n) and space is O(1) and brute force is O(nlogn) and space is O(1) because we sort the array and return the last element of the array which is the largest element in the array.
int second_largest_element(vector<int> &arr,int n){
    //brute force is sorting the array and return the second last element of the array which is the second largest element in the array.time is nlogn+n and space is O(1),nlogn sorting and n for traversing 
    //first sort then check from the back of the array that if there is element less than largest then break
    /*for (int i=n-1;i>=0;i--){
        if(arr[i]<arr[n-1]){
            return arr[i];
        }
        //or can use this if (arr[i] != arr[n-1]){ return arr[i];}
    }
        */
       //2.better appproach is from 1st pass find the largest element and in 2nd pass find the second largest element which is less than the largest element found in 1st pass.time is O(n)+O(n) and space is O(1)
      /* int largest=arr[0];
       for(int i=0;i<n;i++){
           if(arr[i]>largest){
               largest=arr[i];
           }
       }
         int second_largest=INT_MIN;//if negative numbers are present in the array then we can use this otherwise we can use arr[0] as second largest element
         for(int i=0;i<n;i++){
              if(arr[i]>second_largest && arr[i]<largest){
                second_largest=arr[i];
              }
                }
            return second_largest;  */
        //optimal solution is to find the largest and second largest element in one pass time is O(n) and space is O(1)
        int largest=arr[0];
        int second_largest=INT_MIN;//IF THERE ARE NEGATIVE NUMBERS but if only positives then second largest can be taken as -1 or 0
        for(int i=0;i<n;i++){
            if (arr[i]>largest){
                second_largest=largest;
                largest=arr[i];
            }
            else if(arr[i]>second_largest && arr[i]<largest){
                second_largest=arr[i];
            }
        }   
        return second_largest;
}
int second_smallest_element(vector<int> &arr,int n){
    int smallest=arr[0];
    int second_smallest=INT_MAX;//if there are positive numbers in the array but if only negative numbers then we can take second smallest as 0 or -1
    for(int i=0;i<n;i++){
        if (arr[i]<smallest){
            second_smallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<second_smallest && arr[i]>smallest){
            second_smallest=arr[i];
        }
    }   
    return second_smallest;
}
int issorted(vector<int> &arr,int n){
    for (int i=1;i<n;i++){
        if (arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
int remove_duplicates(vector<int> &arr,int n){//here we are given a sorted array and we have to remove the duplicates from the array and return the new length of the array after removing the duplicates and we have to do this in place without using extra space and we have to do this in O(n) time complexity.
    //brute force is to create a set aand insert time complexity is nlogn+n and space complexity is O(n) 
    //in set if we add same element it wont be added and also it will be in sorted order so we can just return the size of the set but this is not optimal solution because we are using extra space and time complexity is also not optimal because of sorting and inserting in set.
    /*set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);//sorted ascending by default
    }
    int index=0;
    for (auto it:s){
        arr[index]=it;
        index++;
    }
    return s.size();//or return index;*/
    //optimal solution is two pointers time is O(n) and space is O(1)   
    int i=0;
    for(int j=1;j<n;j++){//ikkada start from 1 because we are comparing with previous element
        if (arr[j]!=arr[i]){
            arr[i+1]=arr[j];//or can write i++;arr[i]=arr[j];
            i++;
        }
    }
    return i+1;
}
//now next question is left rotate an array by one 
vector<int> left_rotate_by_one(vector<int> &arr,int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}
void right_rotate_by_one(vector<int> &arr,int n){
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}    
//next is left rotate an array by d times and right rotate an array by d times 
void left_rotate_by_d(vector<int> &arr,int n,int d){
    //1st is brute force approach is take a temp array of size d and store the first d elements in the temp array and then shift the remaining elements to the left and then copy the temp array to the end of the original array time is O(n) and space is O(d)
   /* d=d%n;//if d is more then taking mod gives effective rotations
    int temp[d];//or can use vector<int> temp(d);
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }//for this time complexity is d+n-d+d which is O(n) and space complexity is O(d)
    */
   //2nd appproach is to reverse the first d elements and then reverse the remaining n-d elements and then reverse the whole array time is O(n) and space is O(1)
   d=d%n;
   //time complexity is O(d)+O(n-d)+O(n) which is O(n) and space complexity is O(1)
   reverse( arr.begin(),arr.begin()+d);//here instead can also write reverse(arr,arr+d) if we are using array instead of vector it means 0th index to d-1 index
   reverse(arr.begin()+d,arr.end());//as weare using vector we can write arr.begin()+d to arr.end() but if we are using array then we can write reverse(arr+d,arr+n) because we have to reverse from d index to n-1 index
    reverse(arr.begin(),arr.end());
    /*
    code for reverse functio is 
    void reverse(vector<int> &arr,int start,int end){
        while(start<end){
            swap(arr[start],arr[end]);//or by using temp ,temp=arr[start];arr[start]=arr[end];arr[end]=temp;
            start++;
            end--;
        }
    */
} 
//now next is moves all the zeroes to the end of the array while maintaining the relative order of the non-zero elements in the array 
void move_zeroes_to_end(vector<int> &arr,int n){
    //1st brute force is to store all the non zero elements in temp array and copy that to original and keep remaining 0s
   /* vector<int> temp;
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
    }//here time complexity is n+temp.size+n-temp.size() which is O(2n) and space complexity is O(temp.size()) which is O(n) in worst case when all elements are non zero
    */
    //now optimal solution is we have move somehow in one looping 
    //first oka pointer i use chesi first zero ekkada undo chustam
    int j=-1;//j is pointing to the element -1 index  
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;//j is pointing to the first zero in the array
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<n;i++){//1 2 0 0 2 0 0 6 example
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }//here time complexity is x(as there is break so only 1st zero kosmam chustam worst case n so total is x+n-x  which is O(n) and space complexity is O(1) 
    } 
}
int lin_search(vector<int> arr ,int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;//this is for first occurrence of the key and if they want last occurance then start from back if want all occurance then create temp array or some list and store all the occurances in there
}//time is O(n) and space is O(1)

//now the question is to find the union of two sorted arrays and intersection of two sorted arrays and difference of two sorted arrays and symmetric difference of two sorted arrays and also find the union and intersection of two unsorted arrays
//also for union there maybe duplicates in the arrays but in output there shouldnt be duplicates
vector<int> union_of_two_sorteda_arrays(vector<int> &arr1,vector<int> &arr2){
    /*
    //1st approach is to use set and insert elements from set 1 and 2
    set<int> s;
    for(int i=0;i<arr1.size();i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){//here we are using set not unordered set
        s.insert(arr2[i]);
    }
    vector<int> ans;
    for(auto it: s){//time complexity is n1logn+n2logn+n1+n2(here n is size of set) because of inserting in set and traversing the set and space complexity is O(n1+n2)(for set and also we created vector of same size to return) because in worst case all elements are distinct in both arrays (actually we cant tell precisly logn for set because it depends on the number of elements )
        ans.push_back(it);//or can use ans[i++]=it; if we are using array instead of vector
    }//here we are using vector for ans so used this if we use list then also push_back
    */
    //now optimal solutionis to use two pointers traverse both arrays ,compare add if there doesnt exist
    int i=0,j=0;
    vector<int>ans;
    int n1=arr1.size(),n2=arr2.size();
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr1[i]){//here we are checking if the ans vector is empty or the last element in the ans vector is not equal to the current element in arr1 then only we will add it to the ans vector because we dont want duplicates in the ans vector
                ans.push_back(arr1[i]);
            }
            i++;//add chesina cheyakapoina i matram plus coz already checked that element anduke if bayata petta i++
        }
        else {
                if(ans.size()==0 || ans.back()!=arr2[j]){//here checking if ans is empty or last ele is ans is not equal to current in arr2
                    ans.push_back(arr2[j]);
                }
                j++;
            } 
        }
        //the above loops breaks if either i or j becomes n1 or n2 respectively but there may be remaining elements in the other array which we have to add to the ans vector
        while(i<n1){
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        while(j<n2){
            if(ans.size()==0 || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
        return ans;//here time is O(n1+n2) because we are traversing both arrays once and space is O(n1+n2)  this is to return not for solving the answer 
    }
vector<int> intersection_of_two_sorted_arrays(vector<int> &arr1,int n,vector<int> &arr2,int m){
    //brute force is start from any array and check if the element is present in the other array or not create new array visited and if element is present in the other array and not visited then add to the ans vector 
   /* vector<int> ans;int vis[m]={0};//
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                ans.push_back(arr1[i]);
                vis[j]=1;//marking that element as visited in ans array 
                break;
            }
            if(arr1[i]<arr2[j]) break;//because arrays are sorted if arr1[i] is less than arr2[j] then there is no point in checking 
        }  
    }
    return ans;//here time is O(n*m) and space is O(m) for ans array//normallly for less space we can keep less size array
*/
    //optimal is two pointers
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]) i++;
        else if(arr2[j]<arr1[i]) j++;
        else{
            ans.push_back(arr1[i]);//ikkada arr1 nundi start chesi compare chestunnam kabati only arr1 will be pushed
        i++;j++;
        }  //time is O(n+m)(because in worst we will be travesing both arrays) and space is O(1) coz we are only returning non using  , 
    }
    return ans;
}
int finding_missing_number(vector<int> &arr,int n){
    /*
    //brute force
    //question is to find the missing number in an array of size n which contains numbers from 1 to n with one number missing (nnot compusory it is sorted)
    for(int i=1;i<=n;i++){
        bool found=false;
        for(int j=0;j<n-1;j++){//here wee are going through n-1 elements because one number is missing
            if(arr[j]==i){
                found=true;
                break;
            }
            //here we should not write if(!found) return i coz for suppose i=2 and input is 1 4 3 2 as 1st num not equals it return 2 so keep outside this loop

        }
        if(!found) return i;// time complexity is O(n^2) and space complexity is O(1) because we are not using any extra space
    }*/
   //better solution using hashing is to create a hash array of size n+1
   /*vector<int> hash(n+1,0);
   for(int i=0;i<n-1;i++){
    hash[arr[i]]=1;
   }
   for (int i =1;i<=n;i++){
    if(hash[i]==0) return i;
   }//time complexity is O(n) and space complexity is O(n) because of hash array
   */
  //optimal solution is to use the formula of sum of first n natural numbers which is n(n+1)/2 and then subtract the sum of elements in the array from this sum to get the missing number time complexity is O(n) and space complexity is O(1)
  //and other way is using XOR operator because a^a=0 and a^0=a so if we XOR all the elements in the array and XOR with all the numbers from 1 to n then we will get the missing number because all the numbers which are present in the array will cancel out and we will be left with the missing number time complexity is O(n) and space complexity is O(1)
  /*
  int sum=n*(n+1)/2;
  int arr_sum=0;
  for(int i=0;i<n-1;i++){
    arr_sum+=arr[i];
  }
  return sum-arr_sum;//time complexity is O(n) and space complexity is O(1)
  */
//now using xor operator
/*int xor1=0,xor2=0;
for(int i=0;i<n-1;i++){
    xor1^=arr[i];
}
for(int i=1;i<=n;i++){
    xor2^=i;
}
return xor1^xor2;//time complexity is O(2n) and space complexity is O(1)*/
//further optimization is to do both in one loop time complexity is O(n) and space complexity is O(1)
int xor1=0,xor2=0;
for(int i=0;i<n-1;i++){
    xor1^=arr[i];
    xor2^=(i+1);
}
xor2^=n;//because we have to XOR with n also because we are XORing with i+1 in the loop so we have to XOR with n also to get the correct answer
return xor1^xor2;//time complexity is O(n) and space complexity is O(1)
}
int max_consequtive_ones(vector<int> &arr){
    int max_count=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            max_count=max(count,max_count);
        }
        else count=0;//time complexity is O(n) and space complexity is O(1) because we are not using any extra space
    }//here else count is 0 coz resetting the count when we encounter 0 because we are counting consecutive ones so when we encounter 0 we have to reset the count to 0
    return max_count;
}


int main(){ 
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
        
        
    //cout<<largest_element(arr,n)<<endl;
    //cout<<second_largest_element(arr,n)<<endl;
    //cout<<second_smallest_element(arr,n);
    //cout<<issorted(arr,n)<<endl;
    //cout<<remove_duplicates(arr,n)<<endl;
    /*vector<int> ans=left_rotate_by_one(arr,n);
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    right_rotate_by_one(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    */
    /*int d;
    cin>>d;
    left_rotate_by_d(arr,n,d);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
        */
    /*move_zeroes_to_end(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
        */
    /*int key;
    cin>>key;
    cout<<lin_search(arr,n,key)<<endl;
*/
/*
//union of two sorted arrays
    int n1,n2;cin>>n1>>n2;
    vector<int> arr1(n1),arr2(n2);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>arr2[i];  
    }
    // input should be in sorted order because we are finding union of two sorted arrays
    /*vector<int> ans=union_of_two_sorteda_arrays(arr1,arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    vector<int> ans=intersection_of_two_sorted_arrays(arr1,n1,arr2,n2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    */
    //cout<<finding_missing_number(arr,n)<<endl;
    cout<<max_consequtive_ones(arr)<<endl;
    
    

    return 0;
}