class Solution {
private:
    bool isSimilar(string word1, string word2) {
        bool isFirstTime = false;
        for (int i = 0; i < word2.size(); i++) {
            if (word2[i] != word1[i]) {
                if (isFirstTime)
                    return false;
                isFirstTime = true;
                ;
            }
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int index;
        for (index = 0; index < wordList.size(); index++) {
            if (wordList[index] == beginWord)
                break;
        }
        if (index == wordList.size())
            wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> adjacencyList(n);
        int startIndex = -1;
        int targetIndex = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                targetIndex = i;
            } else if (wordList[i] == beginWord) {
                startIndex = i;
            }
        }
        if (targetIndex == -1)
            return 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(wordList[i], wordList[j])) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(startIndex);
        vector<int> visited(n, 0);
        visited[startIndex] = 1;
        int numWords = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (auto neighbour : adjacencyList[node]) {
                    if (!visited[neighbour]) {
                        if (neighbour == targetIndex) {
                            return numWords + 1;
                        }
                        visited[neighbour] = 1;
                        q.push(neighbour);
                    }
                }
            }
            numWords++;
        }
        return 0;
    }
};