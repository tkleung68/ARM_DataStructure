
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isSign(char x) {
    return(x == '+' || x == '-' || x == '*');
    
}

int toInt(char x) {
    return (x - '0');
}

int main()
{
    string str;
    stack <int> s;
    int temp = 0;
    
    while (getline(cin,str)) {
        
        
        for (int i = 0; i < str.length(); i++) {
            
            if (isSign(str.at(i)) && str.at(i)!=' '){
                
                if (str.at(i) == '+') {
                    temp = s.top();
                    s.pop();
                    temp += s.top();
                    s.pop();
                    s.push(temp);
                }
                else if (str.at(i) == '-') {
                    temp = s.top();
                    s.pop();
                    temp = s.top() - temp;
                    s.pop();
                    s.push(temp);
                }
                else {
                    temp = s.top();
                    s.pop();
                    temp = s.top() * temp;
                    s.pop();
                    s.push(temp);
                }
                
                
            }
            else if(str.at(i) != ' ') {
                s.push(toInt(str.at(i)));
            }
            
            
            
            
            
        }
        
        cout << s.top() << endl;
        
        
        
        
    }
    
    return 0;
}

