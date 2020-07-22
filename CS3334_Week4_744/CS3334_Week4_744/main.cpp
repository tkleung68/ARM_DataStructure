
#include <iostream>
using namespace std;

class StackArray{
private:
    int topPos;
    int stack[3001];

    
public:
    
    StackArray(){
        topPos = -1;
    }
    bool IsEmpty(){
        return (topPos==-1);
    }
    void Push(int x){
        stack[++topPos] = x;
        
    }
    void Pop(){
        topPos--;
    }
    
    int getTop(){
        return stack[topPos];   // return the top element
    }

    

    
};

bool Check(StackArray A,StackArray S,int arr[],int n){
 
    for(int k=0;k<n;k++){
        bool keep = true;
        while(keep){
            if((!S.IsEmpty()) && (S.getTop()==arr[k])){
                S.Pop();
                keep = false;
            }else if((A.IsEmpty()) && (S.getTop()!=arr[k])){
                return false;
            }else if(!A.IsEmpty()){
                S.Push(A.getTop());
                A.Pop();
            }
        }
    }
    
    return true;
}

int main() {

    int t;
    
    cin >> t;
    for(int i=0;i<t;i++){
        StackArray A;
        StackArray S;
        int n, m, temp;
        int arr[3001] = {0};
        cin >> n;
        for(int j=0;j<n;j++){   //input stacks elements
            cin >> temp;
            A.Push(temp);
        }
        
        cin >> m;               //permutation
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin >> arr[k];

            }
            if( Check(A,S,arr,n)){
                cout << "Aye" << endl;
            }else{
                cout << "Impossible" << endl;
            }
            
        }
        
        
        
    }
    return 0;
}
