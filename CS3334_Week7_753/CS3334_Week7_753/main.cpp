#include <iostream>
#include <string>
using namespace std;

int find(string strline,int n){
    int position = 0;
    for(int i=0;i<strline.length();i++){
        if(strline.at(i)=='('){
            position++;
            if(position == n){
                return i;
            }
        }
    }
    return 0;
}


int main() {
    
    string strline;
    ios_base::sync_with_stdio(false);
    
    
    while(cin >> strline){
        int arr[1000];
        for(int i=0;i<strline.length()/2;i++){
            arr[i] = 0;
        }
        
        
        for(int j=0;j<strline.length()/2;j++){
            int open = 0;
            int end = 0;
            bool conti = true;
            int n = find(strline,j+1);
            for(int k= n;k<strline.length() && conti;k++){
                if(strline.at(k)=='(')
                    open++;
                if(strline.at(k)==')')
                    end++;
                
                if(open==end){
                    arr[j] = open;
                    conti = false;
                }
                
                
            }
        }
        
        
        int result = arr[0];
        for(int j=1;j<strline.length()/2;j++)
            result = result^arr[j];
        
        
        
        cout << result << '\n' ;
    }
            
            
            
    
            
            
            
    
    
    
    return 0;
}
