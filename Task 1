#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int R_Number = rand() % 100 + 1;
    int guess = 0;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hey "+name+", Welcome to the Game!\n";
    cout << "The game generates a random number between 1 and 100.\n";
    cout << "Can you guess it?\n";
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < R_Number) {
            cout << "Too low! Let's Try again.\n";
        } else if (guess > R_Number) {
            cout << "Too high! Let's Try again.\n";
        } else {
            cout << "Congrats ! You guessed the right number: " << R_Number << "\n";
            break;
        }
    }
    return 0;
}
