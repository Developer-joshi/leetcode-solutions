auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int summ = accumulate(rolls.begin(), rolls.end(),0); 
        int sumn = mean*(m+n) - summ;  
        // The sum of the missing rolls must be at least n (all rolls are at least 1)and at most 6 * n (all rolls are at most 6)
        if (sumn<n || sumn>6*n) return {}; 
        vector<int> result(n, 1);  
        sumn -= n;  
        for (int i = 0;i < n && sumn > 0;i++) {
            int add = min(5, sumn);  // We can add at most 5 to each roll (since max is 6)
            result[i] += add;
            sumn -= add;
        }
        return result;
    }
};
