
#include <iostream>
#include <cmath>
using namespace std;


int f2(char matrix[][1024], int n, int r, int c){
    bool haveWhite = false;
    bool haveBlack = false;
    for(int i=r-1;i>= r - pow(2,n);i--){
        for(int j=c-1;j>= c - pow(2,n);j--){
            if(matrix[i][j]=='1'){
                haveBlack = true;
            }
            if(matrix[i][j]=='0'){
                haveWhite = true;
            }
        }
    }
    
    if(!(haveBlack && haveWhite) || n==0){
        return 1;
    }else{
        int m1,m2,m3,m4;
        m1 =f2(matrix,n-1,r - pow(2,n)/2,c - pow(2,n)/2);
        m2 =f2(matrix,n-1,r - pow(2,n)/2,c);
        m3 =f2(matrix,n-1,r,c - pow(2,n)/2);
        m4 =f2(matrix,n-1,r,c);
        return m1+m2+m3+m4+1;
    }
    
}

int f(char matrix[][1024], int n, int r, int c){
    
    bool haveWhite = false;
    bool haveBlack = false;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]=='1'){
                haveBlack = true;
            }
            if(matrix[i][j]=='0'){
                haveWhite = true;
            }
        }
    }
    
    if(!(haveBlack && haveWhite) || n==0){
        return 1;
    }else{
        int m1,m2,m3,m4;
        m1 =f2(matrix,n-1,r/2,c/2);
        m2 =f2(matrix,n-1,r/2,c);
        m3 =f2(matrix,n-1,r,c/2);
        m4 =f2(matrix,n-1,r,c);
        return m1+m2+m3+m4+1;
    }
    
}




int main() {
    
    
    int num;
    
    while(cin >> num){
        int num2 = pow(2,num);
        char matrix[1024][1024];
        for(int i=0;i<num2;i++){
            for(int j=0;j<num2;j++){
                cin >> matrix[i][j];
                
            }
        }
        
        
        
        cout << f(matrix,num,num2,num2) << endl;
        
        
    }
    return 0;
}

