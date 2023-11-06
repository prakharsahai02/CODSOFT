#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    
    srand(time(0));

    
    int random_Num = rand() % 100 + 1;
    
    int UG; //UG= user guess
    bool CG = false; //CG = correct guess

    cout << "Choose the number between 1 and 100 : ";

    while (!CG) {
        cin >> UG;

        if (UG == random_Num) {
            cout << "Congratulations! You guessed it right." << endl;
            CG = true;
        } else if (UG < random_Num) {
            cout << "Too low. Try again: ";
        } else {
            cout << "Too high. Try again: ";
        }
    }

    return 0;
}
