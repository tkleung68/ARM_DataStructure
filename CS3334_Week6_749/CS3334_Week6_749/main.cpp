#include <iostream>
using namespace std;

int searchPosition(int arr[], int x , int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}


void printPostOrder(int pre[], int in[], int n, int x)
{
    
    int root = searchPosition(in, pre[0], n);
    
    if (root != 0){
         printPostOrder(pre + 1, in, root, x);
    }
    
    
    if (root != n - 1){
        printPostOrder(pre + root + 1, in + root + 1, n - root - 1, x);
    }
    
    
    cout << pre[0];
    if(pre[0]!=x){
        cout << " ";
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        
        int n;
        cin >> n;
        int in[99];
        int pre[99];
        for(int j=0;j<n;j++){
            scanf("%d",&pre[j]);
        }
        
        for(int j=0;j<n;j++){
            scanf("%d",&in[j]);
        }
        
        printPostOrder(pre, in, n, pre[0]);
        cout << '\n';
    }
    return 0;
    
}

