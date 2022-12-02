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
    int ans = 0;
    while (getline(myfile, myline)) {
        char first = myline[0];
        char second = myline[2];
        // lose
        if(second == 'X'){
            // paper
            if(first-'A' == 1){
                ans += 1;
            }else if(first-'A' == 0){
                ans += 3;
            }else{
                ans += 2;
            }
        }
        // draw
        else if(second == 'Y'){
            ans += first-'A'+1+3;
        } 
        else{
            if(first-'A' == 1){
                ans += 3;
            }else if(first-'A' == 0){
                ans += 2;
            }else{
                ans += 1;
            }
            ans += 6;
        }        
    }
    cout<<"ans "<<ans<<endl;
}

/*
A Y -> win 0, 1
A Z -> 0, 2

B X -> 1, 0
B Z -> win 1, 2

C X -> win 2, 0
C Y -> 2, 1
 
*/

/*
with open("aoc1.txt", "r") as f: 
c=['','B X','C Y','A Z','A X','B Y','C Z','C X','A Y','B Z']; 
print(sum([c.index(a) for a in f.read().split('\n')]))
*/