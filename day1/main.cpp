#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main(){
    ifstream myfile; 
    myfile.open("input.txt");
    string myline;
    int i = 0;
    int max_val = INT_MIN;
    int current = 0;
    vector<int> total;
    while (getline(myfile, myline)) {
        if(myline.empty()){
            max_val = max(current, max_val);
            total.push_back(current);
            current = 0;
        }else{
            current += stoi(myline);
        }
    }
    sort(total.begin(), total.end(), greater<int>());
    cout<<total[0]+total[1]+total[2];
}