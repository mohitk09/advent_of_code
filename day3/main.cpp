#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;


int main(){
    ifstream myfile; 
    myfile.open("input.txt");
    string myline;
    int ans = 0;
    while (getline(myfile, myline)) {
        unordered_map<char, bool> map;
        int length = myline.size();
        for(int i=0;i<length/2;i++){
            map[myline[i]] = true;
        }
        for(int i=length/2;i<length;i++){
            char commonCharacter = myline[i];
            if(map.find(commonCharacter) != map.end()){
                if(commonCharacter >= 'a' && commonCharacter <= 'z'){
                    ans += commonCharacter-'a'+1;
                }else{
                    ans += commonCharacter-'A'+27;
                }
                break;
            }
        }
                
    }
    cout<<"ans "<<ans<<endl;
}