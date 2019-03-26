#include <bits/stdc++.h>

using namespace std;

int main() {
    string mazeString;
    int amount;

    while(getline(cin, mazeString)) {

        amount = 0;
        for(int i = 0; i <= mazeString.length(); i++) {
            if(mazeString[i] >= 48 && mazeString[i] <= 57) {
                amount += ((int)mazeString[i] - 48);
            } else
            if(mazeString[i] == 'b') {
                for(int j = 0; j < amount; j++) {
                    cout << " ";
                }
                amount = 0;
            } else 
            if(mazeString[i] == '!' || mazeString[i] == 0) {
                cout << endl;
            }
            else if((mazeString[i] >= 65 && mazeString[i] <= 122) || mazeString[i] == 42){
                for(int k = 0; k < amount; k++) {
                    cout << mazeString[i];
                }
                amount = 0;
            }
        }
    }
    return 0;
}