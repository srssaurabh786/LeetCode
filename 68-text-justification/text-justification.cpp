
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find the maximum words that fit in this line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int spaces = maxWidth - letters;
            int gaps = j - i - 1;
            string line;

            // Last line or line containing only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) {
                        line += ' ';
                    }
                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int spacePerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(
                        spacePerGap + (k - i < extraSpaces ? 1 : 0),
                        ' '
                    );
                }

                line += words[j - 1];
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
