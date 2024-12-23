//Q.3: Player 1 Can Win the Game

#include <iostream>
using namespace std;

bool canPlayer1Win(int nums[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (canPlayer1Win(nums, n)) {
        cout << "Player 1 can win the game." << endl;
    } else {
        cout << "Player 1 cannot win the game." << endl;
    }
    return 0;
}
