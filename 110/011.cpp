#include <bits/stdc++.h>
using namespace std;

int main() {
    int noOfQuestions = 8;
    int noOfLevels = 8;
    int prevScore = 0, currentScore = 1;
    int totalScore = 0;
    for (int i = 0; i < noOfLevels; i++) {
        // can u help me check any calculation error?
        totalScore += noOfQuestions * (currentScore = prevScore + currentScore, prevScore = currentScore);
    }
    // should be equal to total score of this quiz
    cout << totalScore;
    return 0;
}
