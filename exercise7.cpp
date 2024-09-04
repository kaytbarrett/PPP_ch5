/*
    Write a program that reads digits and composes them into integers. For example, 123 is read as
    the characters 1, 2, and 3. The program shoud output 123 is 1 hundred and 2 tens and 3 ones. The 
    number should be output as an int value. Handle numbers with one through four digits. Hint: To get
    the integer value 5 from the character '5' subtract '0', that is '5'-'0'==5.
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to turn vector digits into an integer
int vectorToNum(vector<int> v){

    int num = 0;

    for(int i = 0; i < v.size(); i++){
        num += v[i] * pow(10, (v.size() - i - 1));
    }

    return num;
}

// Function to generate the descriptive output of the digits
string vectorOutput(vector<int> v) {
    string output = " is ";

    int length = v.size();
    if (length == 1) {
        output += to_string(v[0]) + " ones.";
    } else if (length == 2) {
        output += to_string(v[0]) + " tens and " + to_string(v[1]) + " ones.";
    } else if (length == 3) {
        output += to_string(v[0]) + " hundreds " + to_string(v[1]) + " tens and " + to_string(v[2]) + " ones.";
    } else if (length == 4) {
        output += to_string(v[0]) + " thousands " + to_string(v[1]) + " hundreds " + to_string(v[2]) + " tens and " + to_string(v[3]) + " ones.";
    }

    return output;
}

int main(){

    vector<int> digits;
    char c; 
    string input;

    cout << "Please enter a number that is between one and four digits (ex. 123): " << endl;

    cin >> input;

    // Validate the length of the input
    if (input.length() < 1 || input.length() > 4) {
        cerr << "Error: Please enter a number that is between one and four digits." << endl;
        exit(EXIT_FAILURE);
    }
    
    for (char c : input) {
        int cToNum;
        cToNum = c - '0';
        digits.push_back(cToNum);
    }

    cout << vectorToNum(digits) << vectorOutput(digits) << endl;

}