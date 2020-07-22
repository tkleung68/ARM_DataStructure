//Max Heap
#include <iostream>
using namespace std;

#define TOTAL_SLOTS 100
class MyHeap{
private:
    int size;
    int items[TOTAL_SLOTS];
public:
    MyHeap(){
        size = 0;
    }
    void Insert(int key){
        int temp;
        int i = size;
        items[i]=key;
        while (items[i] > items[(i-1)/2] && i!=0)
        {   //swap
            temp=items[i];
            items[i]=items[(i-1)/2];
            items[(i-1)/2]=temp;
            i=(i-1)/2;
        }
        size++;
       
    }
    void popRoot(){
        int i = 0;
        int temp;
        items[0] = items[size-1];
        size--;
        
        while((2*i+1<=size && items[i]< items[2*i+1]) || (2*i+2 <= size &&items[i]< items[2*i+2])){
            
            if(items[2*i+1] > items[2*i+2]){
                temp = items[i];
                items[i] = items[2*i+1];
                items[2*i+1] = temp;
                
                i = 2*i+1;
            }else{
                temp = items[i];
                items[i] = items[2*i+2];
                items[2*i+2] = temp;
                
                i = 2*i+2;
            }
        }
        
    }
    
    void print(){
        int sum = 0;
        for(int i=0;i<size;i++){
            sum+= items[i];
        }
        cout << sum << '\n';
    }
    
};





int main() {
    
    int n;
    while(~scanf("%d",&n)){
        int temp;
        char o;
        MyHeap maxHeap;
        for(int i=0;i<n;i++){
            getchar();
            o = getchar();
            
            switch(o) {
                case 'a' :
                    scanf("%d",&temp);
                    maxHeap.Insert(temp);
                    break;
                case 'p' :
                    maxHeap.popRoot();
                    break;
                case 'r' :
                    maxHeap.print();
                    break;
            }
        }
    }
    
    return 0;
}
