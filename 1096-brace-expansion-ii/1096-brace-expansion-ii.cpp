class Solution {
public:
    int i = 0;

    // Cartesian product / concatenation
    set<string> concat(const set<string>& a, const set<string>& b) {
        set<string> res;

        for (const string& x : a) {
            for (const string& y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // Parse concatenation
    // Example: abc, {a,b}{c,d}
    set<string> parseConcat(string& s) {
        set<string> res = {""};

        while (i < s.size() && s[i] != ',' && s[i] != '}') {

            set<string> cur;

            if (s[i] == '{') {
                i++; // skip '{'

                // Parse everything inside {}
                cur = parseUnion(s);

                i++; // skip '}'
            }
            else {
                // Single character
                cur.insert(string(1, s[i]));
                i++;
            }

            // Concatenate
            res = concat(res, cur);
        }

        return res;
    }

    // Parse union
    // Example: a,b,c
    set<string> parseUnion(string& s) {
        set<string> res;

        while (i < s.size() && s[i] != '}') {

            set<string> cur = parseConcat(s);

            res.insert(cur.begin(), cur.end());

            if (i < s.size() && s[i] == ',') {
                i++; // skip ','
            }
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        i = 0;

        set<string> ans = parseUnion(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};