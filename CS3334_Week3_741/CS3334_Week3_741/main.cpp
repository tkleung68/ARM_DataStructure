#include <iostream>
#include <string>
using namespace std;

char findBiggest(string big) {
    char biggest;
    int len = big.length();
    biggest = big.at(0);
    for (int i = 0; i < len; i++)
        if (big.at(i) > biggest) {
            biggest = big.at(i);
        }
    return biggest;
}

void findSubstr(string str) {
    int pos = 0;
    int count = 0;
    char result[52] = "";
    string cut;
    
    pos = str.find(findBiggest(str));
    result[count] = str.at(pos);
    cut = str;
 
        
        for (int i = pos + 1; i <= cut.length() -1; i++) {
            cut = cut.substr(i);
            pos = cut.find(findBiggest(cut));
            //if (pos == cut.length()-1) {
            count++;
            result[count] = cut.at(pos);
            //    break;
            //}
        }
        
    
    cout << result << endl;
}

int main() {
    int num;
    string str;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> str;
        findSubstr(str);
    }
    return 0;
}
