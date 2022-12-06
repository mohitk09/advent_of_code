#include <iostream>
#include <fstream>
#include <string>
#include <cstring>  

using namespace std;


int main(){
    ifstream myfile; 
    myfile.open("input.txt");
    string myline;
    int ans = 0;
    while (getline(myfile, myline)) {
        int index = myline.find(',');
        string part1 = myline.substr(0, index);
        string part2 = myline.substr(index+1, myline.size()-index);

        int index1 = part1.find('-');
        int start1 = stoi(part1.substr(0, index1));
        int end1 = stoi(part1.substr(index1+1, part1.size()-index1));
        
        int index2 = part2.find('-');
        int start2 = stoi(part2.substr(0, index2));
        int end2 = stoi(part2.substr(index2+1, part2.size()-index2-1));
        
        int start = max(start1, start2);
        int end = min(end1, end2);
        
        if(start <= end){
            ans++;
        }
    }
    cout<<"ans "<<ans<<endl;
}