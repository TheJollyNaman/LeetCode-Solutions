class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        int fizz=0, buzz=0;
        
        for(int i=1; i<=n; i++) {

            fizz++; 
            buzz++;
            
            if(fizz==3 and buzz==5) {
                ans.push_back("FizzBuzz");
                fizz=0; 
                buzz=0;
            }
            else if(fizz==3) {
                ans.push_back("Fizz");
                fizz=0;
            }
            else if(buzz==5) {
                ans.push_back("Buzz");
                buzz=0;
            }
            else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};