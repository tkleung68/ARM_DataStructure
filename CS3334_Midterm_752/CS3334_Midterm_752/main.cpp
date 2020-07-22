
#include <iostream>
#include <queue>
using namespace std;

class Time{
public:
    int a;
    int r;
    bool p;
    int order;

    Time(int a1, int r1, int o){
        a = a1;
        r = r1;
        order = o;
    }
};
int main() {

    int n;
    while(~scanf("%d", &n)){
        queue<Time> high, low;
        int r,w,p;
        int result[101];
        int count = 0;
        

        for(int i=0;i<n;i++){
            scanf("%d%d%d", &r, &w, &p);
            Time temp = Time(r,w,i);
            if(p==1)
                low.push(temp);
            else
                high.push(temp);
        }
        // first case
        if(low.empty()){
            count = high.front().r + high.front().a;
            result[high.front().order] = count;
            high.pop();
        }else if(high.empty()){
            count = low.front().r + low.front().a;
            result[low.front().order] = count;
            low.pop();
        }else if(low.front().a < high.front().a){
            count = low.front().r + low.front().a;
            result[low.front().order] = count;
            low.pop();
        }else{
            count = high.front().r + high.front().a;
            result[high.front().order] = count;
            high.pop();
        }
        
        
        //second
        while( !low.empty() || !high.empty()){
            if(low.empty()){
                if(high.front().a > count){
                    count = high.front().a + high.front().r;
                    result[high.front().order] = count;
                    high.pop();
                }else{
                    count = count + high.front().r;
                    result[high.front().order] = count;
                    high.pop();
                }
            }else if(high.empty()){
                if(low.front().a > count){
                    count = low.front().a + low.front().r;
                    result[low.front().order] = count;
                    low.pop();
                }else{
                    count = count + low.front().r;
                    result[low.front().order] = count;
                    low.pop();
                }
            }
            else if(low.front().a >= high.front().a){    //nornal case
                if(high.front().a > count){
                    count = high.front().a + high.front().r;
                    result[high.front().order] = count;
                    high.pop();
                }else{
                    count = count + high.front().r;
                    result[high.front().order] = count;
                    high.pop();
                }
            }else{
                if(low.front().a < count){
                    if(high.front().a <= count){
                        count = count + high.front().r;
                        result[high.front().order] = count;
                        high.pop();
                    }else{
                        count = low.front().r + count;
                        result[low.front().order] = count;
                        low.pop();
                    }
                }else if(low.front().a > count){
                    count = low.front().a + low.front().r;
                    result[low.front().order] = count;
                    low.pop();
                
                }else{
                    count = low.front().r + count;
                    result[low.front().order] = count;
                    low.pop();
                }
            }
        }

        
        
        
        for(int i=0;i<n-1;i++)
            printf("%d ", result[i]);
        printf("%d\n", result[n-1]);

    }
    return 0;
}
