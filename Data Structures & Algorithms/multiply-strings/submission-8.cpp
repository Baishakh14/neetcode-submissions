class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<string> vec;
        for (int i = num2.size()-1; i >= 0;i--) {
            string bai = "";
            for (int j = 0; j < num2.size() - i - 1; j++) bai.push_back('0');
            int carry = 0;
            for (int j = num1.size() - 1; j >= 0; j--) {
                int f = (num2[i] - '0') * (num1[j] - '0');
                f += carry;
                int last = f % 10;
                char lc = last + '0';
                bai.push_back(lc);
                carry = f / 10;
            }
            if (carry > 0) {
                string arekta = to_string(carry);
                for (int j = arekta.size() - 1; j >= 0; j--) {
                    bai.push_back(arekta[j]);
                }
            }
            vec.push_back(bai);
        }
        string final = "";
        int carry = 0;
        for (int i = 0; i < num1.size() + num2.size(); i++) {
            bool find = false;
            for (auto &it : vec) {
                if (it.size() <= i) continue;
                find = true;
                carry += it[i] - '0';
            }
            if (!find) break;
            int last = carry % 10;
            final.push_back(last + '0');
            carry /= 10;
        }
        if (carry > 0) {
            string arekta = to_string(carry);
            for (int j = arekta.size() - 1; j >= 0; j--) {
                final.push_back(arekta[j]);
            }
        }
        reverse(final.begin(), final.end());
        return final;
    }
};
