/*
    A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to
    a vault. There are 60 possible numbers, and you need three different numbers for the combination.
    There are P(60,3) permutations, where P is defined by the formula P(a,b)=(a!)/((a-b)!) where ! is 
    used as a suffix factorial operator.

    Combinations are similar to permutations, except that the order of the objects doesn't matter. For
    example, if you were making a "banana split" sundae and wished to use three different flavors of ice
    cream out of five that you had, you probably wouldn't care if you put a scoop of vanilla at the 
    beginning or at the end. The formula for combinations is C(a,b)=(P(a,b)/b!)

    Design a program that asks users for two numbers, asks them whether they want to calculate permutations
    or combinations, and prints the result. This will have several parts. Do an analysis of the above
    requirements. Write exactly what the program will have to do. Then, go into the design phase. Write
    pseudo code for the program and break it into sub-components. This program should have error checking.
    Making sure that all erroneous inuts will generate good error messages.
*/

#include <iostream>

using namespace std;

// Function to calculate permutations
long long calculatePermutations(int a, int b){

    long long total = 1;

    // Calculate P(a, b) = a * (a-1) * ... * (a-b+1)
    for (int i = 0; i < b; i++) {
        total *= (a - i);
    }

    return total;
}

// Function to calculate combinations
long long calculateCombinations(int a, int b){
    int numerator = calculatePermutations(a, b);
    int denominator = 1;

    // Calculate b! for combinations
    for (int i = b; i > 1; i--){
        denominator *= i;
    }

   return numerator/denominator;
}

int main(){
    int a = 0;
    int b = 0;
    char input;

    cout << "Please enter two numbers (ex. 10 3): " << endl;
    cin >> a >> b;


    if (b > a || a < 0 || b < 0) {
        cerr << "Invalid input: a must be >= b and both must be non-negative." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Do you want to calculate permutations or combinations? (Enter 'p' or 'c'): " << endl;
    cin >> input;

    if (input == 'p'){
        cout << "Permutations: " << calculatePermutations(a, b) << endl;
    } else if (input == 'c'){
        cout << "Combinations: " << calculateCombinations(a, b) << endl;
    } else {
        cerr << "That is not a valid input" << endl;
        exit(EXIT_FAILURE);
    }

}