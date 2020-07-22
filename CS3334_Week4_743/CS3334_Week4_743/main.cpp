#include <iostream>
#include <string>
using namespace std;

class StackArray{
private:
    int topPos;                 // index of top element
    int capacity;            // allocated memory space of array
    char *stack;              // array representing stack
    int *stackNum;

public:
    
    StackArray(){
        topPos = -1;
        capacity = 100001;
        stack = new char[capacity];
        stackNum = new int[capacity];
    }
    bool IsEmpty(){
        return (topPos==-1);
    }
    void Push(char x,int num){
        stack[++topPos] = x;
        stackNum[topPos] = num;
        
    }
    void Pop(){
        topPos--;
    }
    
    int getTop(){
        return stack[topPos];   // return the top element
    }
    
    int getTopNum(){
        if (IsEmpty()) {     // check if stack is empty
            
            return -1;
        }
        return stackNum[topPos];   // return the top element
    }
    int getSize(){
        return 1+topPos;
    }
    
};

bool IsMatched(char a,char b){
    return( (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']') );
    
}

bool IsSign(char a){
    return ( a=='[' || a==']' || a=='{' || a=='}' || a=='(' || a==')');
}

bool HaveClose(char a){
    return ( a==']' || a=='}' || a==')');
}



int main() {
    StackArray store;
    string strline;
    
    while(getline(cin, strline)){
        
        char temp;

        int inputOrder = 0;
        
        do{
            temp = strline.at(inputOrder);
            inputOrder++;
            if( IsSign(temp))
                store.Push(temp,inputOrder);
        }while(store.getSize()!=1 && inputOrder < strline.length());
        
        
        for(int j=inputOrder;j<strline.length();j++){
            
            inputOrder++;
            temp = strline.at(j);
            if( IsSign(temp)){
                if(IsMatched(store.getTop(),temp)){
                    store.Pop();
                }else{
                    store.Push(temp,inputOrder);
                }
            }
            
        }
        
        
        if(store.IsEmpty()){
            cout << "Success" << '\n';
            
        }else{
            int open = -1;
            int close = -1;
            while(!store.IsEmpty()){
                if(HaveClose(store.getTop()))
                   close = store.getTopNum();
                if(store.getSize()==1){
                    open = store.getTopNum();
                }
                store.Pop();
               
            }
            
            if(close==-1){
                cout << open << '\n';
            }else{
                cout << close << '\n';
            }
        }
    }
    return 0;
}

