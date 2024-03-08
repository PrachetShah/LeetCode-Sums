class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        deque<int> deque(tokens.begin(), tokens.end());

        while (!deque.empty()) {
            // When we have enough power, play token face-up
            if (power >= deque.front()) {
                power -= deque.front();
                deque.pop_front();
                score += 1;
            // We don't have enough power to play a token face-up
            // When there is at least one token remaining,
            // and we have enough score, play token face-down
            } else if (deque.size() > 1 && score > 0) {
                power += deque.back();
                deque.pop_back();
                score -= 1;
            // We don't have enough score, power, or tokens 
            // to play face-up or down and increase our score
            } else {
                return score;
            }
        }
        return score;
    }
};