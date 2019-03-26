#include <bits/stdc++.h>

using namespace std;

int main() {
    string from = "\"";
    string to1 = "``";
    string to2 = "''";
    bool foundOnce = true;
    string toRead;

    while(getline(cin, toRead)) {

        for( size_t findDouble = toRead.find(from); findDouble != std::string::npos; findDouble = toRead.find(from, findDouble)) {
            if(foundOnce)
                toRead.replace(findDouble, from.size(), to1);
            else
                toRead.replace(findDouble, from.size(), to2);
            findDouble += to1.size();
            foundOnce = !foundOnce;
        }
        cout << toRead << endl;
    }

    return 0;
}