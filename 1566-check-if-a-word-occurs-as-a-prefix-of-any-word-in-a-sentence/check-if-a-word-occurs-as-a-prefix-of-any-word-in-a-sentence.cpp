class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> wordsList;
        string currentWord;
        for (char character : sentence) {
            if (character != ' ') {
                currentWord += character;
            } else {
                if (!currentWord.empty()) {
                    wordsList.push_back(currentWord);
                    currentWord = ""; 
                }
            }
        }
        if (!currentWord.empty()) {
            wordsList.push_back(currentWord);
        }
        for (int wordIndex = 0; wordIndex < wordsList.size(); ++wordIndex) {
            if (wordsList[wordIndex].length() >= searchWord.length()) {
                bool isMatch = true;
                for (int charIndex = 0; charIndex < searchWord.length();
                     ++charIndex) {
                    if (wordsList[wordIndex][charIndex] !=
                        searchWord[charIndex]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) {
                    return wordIndex + 1;
                }
            }
        }
        return -1;
    }
};