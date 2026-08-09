class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 used to match word2[j]
        // when matching word2 from right to left.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Build last[]
        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // We are still allowed to use one mismatch
        bool canSkip = true;

        j = 0;

        // Greedily scan word1 from left to right
        for (i = 0; i < n && j < m; i++) {

            // Case 1: exact match
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Case 2: use this index as our one mismatch
            else if (
                canSkip &&
                (j == m - 1 || i < last[j + 1])
            ) {

                ans[j] = i;

                // Mismatch has now been used
                canSkip = false;

                j++;
            }
        }

        // Couldn't construct a complete sequence
        if (j < m)
            return {};

        return ans;
    }
};