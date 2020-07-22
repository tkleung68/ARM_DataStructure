
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        int size;
        cin >> size;
        long long int result = size;
        long long int arr[100000];
        stack<int>s;
        
       
        for(int j=0;j<size;j++){
            cin >> arr[j];
            
        }
        
        
        int count = 0;
        
        while(count < size){
            
            if(s.empty() || arr[count]>=arr[s.top()]){
                s.push(count++);
            }else if(arr[count] < arr[s.top()]){
                
                long long int temp = s.top();
                s.pop();
                
                if(s.empty())
                    temp = arr[temp]*count;
                else
                    temp = arr[temp]*(count-s.top()-1);
                
                if(result < temp)
                    result = temp;
            }
            
            
            
        }
        
        //last check
        while(!s.empty()){
            long long int temp = s.top();
            s.pop();
            
            if(s.empty())
                temp = arr[temp]*count;
            else
                temp = arr[temp]*(count-s.top()-1);
            
            if(result < temp)
                result = temp;
                
        }
        
        
        
        cout << result << '\n';
        
        
        
        
    }
    return 0;
}

