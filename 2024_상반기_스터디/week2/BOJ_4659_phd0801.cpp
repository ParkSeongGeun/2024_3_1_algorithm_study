#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string s;

char moo[5] = {'a', 'e', 'i', 'o', 'u'};
set<char> myset = {'a', 'e', 'i', 'o', 'u'};

int main() {
    while(cin >> s){
        if(s=="end"){
            return 0;
        }
        int flag = 0;
        // 1st :  모음 포함
        for(int i=0;i<s.length();i++){
            for(int j=0;j<5;j++){
                if(s[i] == moo[j]){
                    flag = 1;
                }
            }
        }
        
        if(flag == 0){
            cout << "<" << s << ">" << " is not acceptable\n";
        }
        
        // 2nd 모음, 자음이 3개 연속으로 오는 지 검사
        if(flag != 0) {
            //cout << "2rd" << " : " << flag << "\n";
            int zaeum = 0;
            int moeum = 0;
            if (myset.find(s[0]) != myset.end()) {
                moeum++;
            } else {
                zaeum++;
            }
            //cout << "z: " << zaeum << "m: " << moeum << "\n";
            for(int i=1;i < s.length();i++){
                // 일단 모음
                if(myset.find(s[i])!=myset.end()){
                // 전에도 모음
                    if(zaeum > 0){
                        moeum = 1;
                        zaeum = 0;
                    } else {
                        moeum++;
                        zaeum = 0;
                    }
                } else { // 자음일때
                    if(zaeum > 0){
                        zaeum++;
                        moeum = 0;
                    } else {
                        moeum = 0;
                        zaeum = 1;
                    }
                }
                //cout << "z: " << zaeum << " m: " << moeum << "\n";
          
                if(zaeum >= 3||moeum >=3 ){
                    cout << "<" << s << ">" << " is not acceptable\n";
                    flag = 0;
                    break;
                }
            }

            
        }

        if(flag != 0) {
            //cout << "3rd" << " : " << flag << "\n";
            char c = s[0];
            for(int i=1;i<s.length();i++){
                if(s[i]==s[i-1]){
                    if(s[i]=='e'||s[i]=='o'){
                        continue;
                    } else {
                        flag = 0;
                        cout << "<" << s << ">" << " is not acceptable\n";
                        break;
                    }
                }
            }
        }

        if(flag != 0){
            cout << "<" << s << ">" << " is acceptable\n";
        }
    }
}