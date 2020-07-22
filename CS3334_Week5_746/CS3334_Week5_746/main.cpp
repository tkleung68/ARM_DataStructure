
#include <iostream>
#include <queue>
using namespace std;


class Time{
    
    
    
public:
    
    int endTime;
    
    Time(int et){
        endTime = et;
    }
};

int main() {
    
    int n;
    while(~scanf("%d", &n)){
        queue<Time> customer;
        int a, o, l;
        int totaltime = 0;
        
        for(int i=0;i<n-1;i++){
            
            scanf("%d%d%d", &a,&o,&l);
            
            
            while(customer.size()>=1 &&a>=customer.front().endTime){
                customer.pop();
            }
            
            //check l
            if(l>=customer.size()){
                
                if(customer.size()>=1){
                    if(a>customer.back().endTime)
                        totaltime = a + o;
                    else
                        totaltime = customer.back().endTime + o;
                }else{
                    totaltime = a + o;
                }
                Time obj = Time(totaltime);
                customer.push(obj);
                
            }
            
            
            
        }
        //finally check
        scanf("%d%d%d", &a,&o,&l);
        while(customer.size()>=1 &&a>=customer.front().endTime){
            customer.pop();
        }
        
        if(l<customer.size()){
            cout << -1 << endl;
        }else{
            
            if(totaltime < a)
                totaltime = a;
            
            cout << totaltime << endl;
        }
    }
    return 0;
}

