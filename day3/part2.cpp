#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(){
    ifstream myfile; 
    myfile.open("input.txt");
    string str;
    int ans = 0;
    int i = 0;
    bool prim[52];
    memset(prim, true, sizeof(prim));
    while (getline(myfile, str)) {
        int length = str.size();
        i++;
        bool sec[52] = { false };
        for (int j = 0; str[j]; j++) {
            if(str[j] >= 'a' && str[j] <= 'z'){
                if (prim[str[j] - 'a'])
                    sec[str[j] - 'a'] = true;
            }else{
                if (prim[str[j] - 'A'+26])
                    sec[str[j] - 'A'+26] = true;
            }
        }
        memcpy(prim, sec, 52);
        if(i%3 == 0){
            for (int i = 0; i < 52; i++){
                if (prim[i]){
                    ans += i+1;
                }
            }
            memset(prim, true, sizeof(prim));
        }   
    }
    cout<<"ans "<<ans<<endl;
}