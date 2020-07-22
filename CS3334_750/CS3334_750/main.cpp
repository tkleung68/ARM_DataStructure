#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int info;
    Node *parent;
    Node(int i){
        info = i;
        parent = NULL;
    }
    Node(int i,Node* n){
        info = i;
        parent = n;
    }
    Node(){}
    int h(){
        
        if(this->parent == NULL)
            return 1;
        int hei;
        hei = this->parent->h();
        
        return hei+1;
        
    }

    
};

Node* search(Node *arr,int num,int size){
    for(int k=0;k<size;k++){
        if(arr[k].info == num)
            return &arr[k];
    }
    return NULL;
}


bool touch(Node* t,int num){
    
    if(t->info ==num)
        return true;
    bool m1 = false;
    if(t->parent !=NULL)
        m1 = touch(t->parent,num);
    
    return m1;
    
}

int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        Node arr[1000];
        
        int root;
        int son;
        int parent;
        
        cin >> root >> son;
        Node *temp = new Node(root);
        arr[0] = Node(*temp);

      
   
        
        
        
        for(int j=1;j<son;j++){
            cin >> root >> parent;
            
            arr[j] = Node(root,search(arr,parent,son));
        }

        
        cin >> root >> parent;

        
        temp = search(arr,root,son);
        Node *temp2 = search(arr,parent,son);
        
        if(touch(temp,parent) || touch(temp2,root)){
            if(temp->h() < temp2->h()){
                cout << temp->info << '\n';
            }else{
                cout << temp2->info <<'\n';
            }
        }else{
            bool ok = true;
            if(temp->h() < temp2->h()){
                while(ok){
                    if(touch(temp2,temp->parent->info)){
                        cout << temp->parent->info << '\n';
                        ok = false;
                    }
                    temp = temp->parent;
                }
            }else{
                while(ok){
                    if(touch(temp,temp2->parent->info)){
                        cout << temp2->parent->info << '\n';
                        ok = false;
                    }
                    temp2 = temp2->parent;
                }
            }
        }

        




        
        
        
    }
    
    
}
