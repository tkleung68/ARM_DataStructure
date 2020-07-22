#include <iostream>
using namespace std;



class TreeNode{
private:
    int data;
    TreeNode* one;
    TreeNode* two;
    TreeNode* three;
    TreeNode* four;
    int count;
public:
    TreeNode(int x){
        data = x;
        one = NULL;
        two = NULL;
        three = NULL;
        four = NULL;
        count = 0;
    }
    //create a new left child of a given node
    void setnext(int x) {
        switch(count){
            case 0: *one = TreeNode(x);
                count++;
                break;
            case 1: *two = TreeNode(x);
                count++;
                break;
            case 2: *three = TreeNode(x);
                count++;
                break;
            case 3: *four = TreeNode(x);
                count++;
                break;
        }
    }

};

class Mytree
{
private:
    TreeNode* root;
public:
    Mytree(int x){
        *root = TreeNode(x);
    }
    void InsertNode(int x){
        
    }
    
};





int main() {
    
    return 0;
}
