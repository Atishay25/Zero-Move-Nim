#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// By Aryan Mathe (210050021)

#define LOG(x) cout << x << endl

// This function finds the MEX value of a set of values which is present in a 
// list named "arr" using a simple algoritm. In that algorithm we iterate through
// the elements of the array, and negate the element which has index equal to the 
// current element. After doing this process for all teh elements we simply finds 
// the index which has a non negative element adn returns it's index.
int find_mex(int index, vector<vector<int>>& dp){

    vector<int>arr = dp[1];
    arr[index] = dp[0][index];

    int i=0;

    // Handling the case for 0.
    for(int i=0; i<=index; i++){
        arr[i] = arr[i] + 1;
    }

    // Negating the elements
    for(int i=0; i<=index; i++){
        int temp = arr[i];
        if(abs(temp)-1 <= index){
            arr[abs(temp) - 1] = -arr[abs(temp) - 1];
        }
    }

    // Finding the index which has +ve element.
    for(i=0; i<=index; i++){
        if(arr[i] > 0){
            break;
        }
    }
    
    return i;
}

int get_Nimber_AdvNim(vector<int>& pile){

    // Getting the max_size of the DP array.
    int max_val = INT_MIN;
    for(auto i:pile){
        max_val = max(i, max_val);
    }

    // Creating the vector(array)
    vector<vector<int>> dp(2);

    // dp[0] ==> An array which has the nimber equivalent to the standard NIM game
    dp[0] = vector<int>(max_val+1, 0);

    // dp[0] ==> An array which consists of the nimber equivalent of the Advanced NIM game
    dp[1] = vector<int>(max_val+1, 0);

    for(int i=0; i<max_val+1; i++){
        dp[0][i] = i;
    }

    // Finding the Nimber value for all the pile sizes less that and equal to the max pile size.
    for(int i=1; i<dp[0].size(); i++){
        dp[1][i] = find_mex(i, dp);
    }
    
    // Finding the final nimber equivalent of all the piles using "XOR SUM".
    int final_ans = 0;
    for(auto i:pile){
        final_ans^=dp[1][i];
    }

    // returning the final nimber equivalent of the entire game.
    return final_ans;
}

int main(){
    cout << "Input Number of Piles: ";
    int num_of_pile;
    cin >> num_of_pile;
    LOG("");
    cout << "Input Pile Sizes for each of them: ";

    vector<int> piles(num_of_pile);
    for(int i=0; i<num_of_pile; i++){
        cin >> piles[i];
    }

    int final_ans = get_Nimber_AdvNim(piles);
    LOG("");
    LOG("Nimber Equivalent: " << final_ans);

    // If the nimber value is "0" then that's a P position and Second Player wins.
    if(final_ans == 0){
        LOG("");
        LOG("Second Player Wins !!");
    }
    // If the nimber value is non zero that that's a N position and First Player Wins.
    else{
        LOG("");
        LOG("First Player Wins !!");
    }
    return 0;
}