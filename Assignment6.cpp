#include <iostream>
#include <fstream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to count prime numbers in NUMS.TXT
int countPrimesInFile() {
    ifstream file("NUMS.TXT");
    int num, count = 0;

    if (!file) {
        cout << "Error opening file.\n";
        return -1;
    }

    while (file >> num) {  // reads line by line numbers
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    int result = countPrimesInFile();
    
    if (result != -1)
        cout << "Number of prime numbers: " << result << endl;

    return 0;
}
