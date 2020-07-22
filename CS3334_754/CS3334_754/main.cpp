
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    scanf("%d",&n);
    
    for(int i=0; i<n;i++){
        int roomnum, clientnum;
        scanf("%d%d",&roomnum, &clientnum);
        
        int room[30000];
        for(int j=0;j<roomnum;j++){
            scanf("%d", &room[j]);
        }
        sort(room,room+roomnum);

        int min = 1;
        int max = room[roomnum-1] - room[0];
        
        
        bool finished = false;
        int key = 1;
        int testkey = ceil((min + max)/2.0);
        while(!finished){
            
            //check if the case pass;
            int count = 0;
            int pointer = 0;
            int back = 0;
            while(pointer !=roomnum && count != clientnum-1){
                
                
                if(room[pointer]-room[back]>=testkey){
                    back = pointer;
                    pointer++;
                    count++;
                }else{
                    pointer++;
                }
            }
            
            // go right
            if(count == clientnum-1){
                min = testkey;
                key = testkey;
                testkey = ceil((min + max)/2.0);
                if(testkey ==min){
                    finished = true;
                }
                
            }else{// go left
                max = testkey;
                testkey = ceil((min + max)/2.0);
                if(testkey==max)
                    finished = true;
            }
            
        
            
        }
        cout << key << "\n";
        
        
    }
    return 0;
}
