class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
        return string(1, static_cast<char>(258));

        string res="";
        char separate = static_cast<char>(257);
        for(auto s: strs){
            res+=s;
            res+=separate;
        }
        res.pop_back();
        return res;
    }

    vector<string> decode(string s) {
       if (s == string(1, static_cast<char>(258))) {
            return {};
        }
        char separate = static_cast<char>(257);
        vector<string> result;
        string current = "";

        for (char c : s) {
            if (c == separate) {
                result.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }
        result.push_back(current); 

        return result;
    }
};
