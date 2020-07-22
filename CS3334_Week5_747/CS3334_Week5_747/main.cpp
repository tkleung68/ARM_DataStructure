
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int order;
    int data;
    Node(int o, int d){
        order = o;
        data = d;
    }
    void sub(){data-=1;}
};

int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        int num, time;
        cin >> num >> time;
        queue<Node> s,tempq;
        int max, max_order;
        vector<int> result;
        int x;
        
        //input data
        int input;
        for(int j=0;j<num;j++){
            scanf("%d", &input);
            Node temp = Node(j+1,input);
            s.push(temp);
        }
        
        //processing
        while(!s.empty()){
            max = s.front().data;
            max_order = s.front().order;
            
            if(s.size() >= time){
                x = time;
            }else{
                x = s.size();
            }
            for(int j=0;j<x;j++){
                if(s.front().data > max){
                    max_order = s.front().order;
                    max = s.front().data;
                }
                tempq.push(s.front());
                s.pop();
            }
            result.push_back(max_order);
            //put back;
            
            x = tempq.size();
            for(int j=0;j<x;j++){
                if(tempq.front().order==max_order){
                    tempq.pop();
                }else{
                    tempq.front().sub();
                    s.push(tempq.front());
                    tempq.pop();
                }
            }
 
        }
        
        cout << result[0];
        for(int j=1;j<num;j++){
            cout << " " << result[j];
        }
        cout << '\n';

        
    }

    return 0;
}

