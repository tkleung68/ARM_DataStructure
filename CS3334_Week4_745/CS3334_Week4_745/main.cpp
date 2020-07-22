    #include <iostream>
    using namespace std;

    class StackArray{
    private:
        int topPos;
        int stack[12000];
        
        
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
            return stack[topPos];
        }
        
        int getSize(){
            return topPos+1;
        }
        
    };


    int main() {
        
        int t;
        cin >> t;
        
        for(int i=0;i<t;i++){
            int n, temp, o;
            
            
            cin >> n;
            StackArray A;
            cin >> temp;
            A.Push(temp);
            for(int j=1;j<n;j++){
                cin >> temp;
                if(temp>A.getTop()){
                    A.Push(temp);
                }else{
                    A.Push(A.getTop());
                }
            }
            cin >> o;
            for(int j=0;j<o;j++){
                char operators;
                cin >> operators;
                switch(operators){
                    case 'm': cout << A.getTop() << endl;
                        break;
                    case 'r':
                        A.Pop();
                        break;
                    case 'a': cin >> temp;
                        if(temp>A.getTop()){
                            A.Push(temp);
                        }else{
                            A.Push(A.getTop());
                        }
                        break;
                }
            }
        }
        
        
        
        return 0;
    }
