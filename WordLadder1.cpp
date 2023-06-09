class Solution {
public:
        int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        //initial searching of elements
        for(int i=0;i<startWord.size();i++){
            char c = startWord[i];
            for(char ch='a'; ch<='z';ch++){
                startWord[i]=ch;
                if(st.find(startWord)!=st.end()){
                    q.push({startWord, 1});
                    st.erase(startWord);
                }
            }
            startWord[i] = c;
        }
            
        // N X (WordSize X 26) x logN -- unordered Set complexity
        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            if(word==targetWord)
                return count+1;
            q.pop();
            for(int i=0;i<word.size();i++){
                char c = word[i];
                for(char ch='a'; ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, count+1});
                        st.erase(word);
                    }
                }
                word[i] = c;
            }
        }
        return 0;
        
    }

};
