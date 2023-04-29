#include <iostream>
#include <vector>
using namespace std;

// Simple implementation using the result obtained
// of Grundy number and winning state for Advanced Nim
void game(vector<int> &piles){
    int Nimsum = 0;
    for (int i = 0; i < piles.size(); i++){
        // If the size of the pile is odd then it's Grundy Number will be G(N+1)
        if (piles[i] % 2 == 1)
            Nimsum ^= (piles[i] + 1);
        // If the size of the pile is even then it's Grundy Number will be G(N-1)
        else
            Nimsum ^= (piles[i] - 1);
    }
    // If the Nim sum is non-zero then Player 1 will win the game
    cout << endl << "Nimber Equivalent: " << Nimsum << endl;
    if (Nimsum != 0){
        cout << endl << "First Player Wins !!" << endl;
    }
    // If the Nim sum is zero then Player 2 will win the game
    else{
        cout << endl << "Second Player Wins !!" << endl;
    }
}

int main(){
    cout << "Input Number of Piles: ";
    int num_of_pile;
    cin >> num_of_pile;
    cout << endl << "Input Pile Sizes for each of them: ";
    vector<int> piles(num_of_pile);
    for (int i = 0; i < num_of_pile; i++){
        cin >> piles[i];
    }
    game(piles);
}