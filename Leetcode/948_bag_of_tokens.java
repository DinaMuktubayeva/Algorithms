import java.util.Arrays;

// Our strategy suggests while loops for face ups,
// because we don't know the actual number of 
// consequtive face ups that we're going to play

// After each face up, we update the maximum score, if possible.
// After all possible face ups have been played, 
// we check if we can play face down to gain power. 

// If we can, we only do this once before checking 
// if we can play face up again - this is to maximise the score.

// To repeat the entire process, we again need a while loop,
// because we don't know the number of iterations. At maximum,
// this while loop will run until there're no tokens left.
// We need to keep track of the smallest and the greatest tokens
// to minimise power losses and maximise power gains.

class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        if (tokens.length == 0)
            return 0;
        if (tokens.length == 1) {
            if (tokens[0] > P)
                return 0;
            else
                return 1;
        }

        Arrays.sort(tokens);

        // If we have too little power for the smallest
        // token value, we can't play at all
        if (tokens[0] > P)
            return 0;

        // Indexes of the smallest and the greatest
        // available tokens, respectively
        int lo = 0, hi = tokens.length - 1;

        // Current score and maximum score
        int curScore = 0, maxScore = 0;

        // While we have tokens to play
        while (hi >= lo) {

            // While we can spend our power
            while (P >= tokens[lo]) {

                // Spend power on the smallest token
                // and then increase lo and score
                P -= tokens[lo++];
                ++curScore;

                // Check if the maximum
                // has to be updated
                if (curScore > maxScore)
                    maxScore = curScore;
            }

            // We can't spend the power anymore,
            // so check if we can gain some power
            if (curScore != 0) {

                // Gain power from the greatest token
                // and then decrease hi and score
                P += tokens[hi--];
                --curScore;
            }
        }

        return maxScore;
    }
}