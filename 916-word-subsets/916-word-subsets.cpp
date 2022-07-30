class Solution {
public:
    
    vector<int> countFreq(string& word){
        vector<int> freq(26);
        
        for(auto& a : word) 
            freq[a - 'a']++;
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> required(26);
        vector<string> ans;
        
        for(auto& word : B){
            vector<int> freq = countFreq(word);            
            for(int i = 0; i < 26; i++) 
                required[i] = max(required[i], freq[i]);
        }        
        
        for(auto& word : A){
            vector<int> freq = countFreq(word);            
            int i;
            
            for(i=0;i < 26; i++) 
                if(freq[i] < required[i]) 
                    break;
            
            if(i == 26) 
                ans.push_back(word);
        }
        
        return ans;
    }
};