class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<string> vec;

        string now = num2;
        reverse(now.begin(), now.end());

        for (int i = 0; i < now.size(); i++) {

            string bai = "";

            for (int j = 0; j < i; j++)
                bai.push_back('0');

            int carry = 0;
            int f = now[i] - '0';

            for (int j = num1.size() - 1; j >= 0; j--) {

                int s = num1[j] - '0';

                int val = f * s + carry;

                bai.push_back((val % 10) + '0');

                carry = val / 10;
            }

            if (carry > 0) {
                string arekta = to_string(carry);

                for (int j = arekta.size() - 1; j >= 0; j--)
                    bai.push_back(arekta[j]);
            }

            vec.push_back(bai);
        }

        string final = "";
        int carry = 0;

        int mx = num1.size() + num2.size();

        for (int i = 0; i < mx; i++) {

            int sum = carry;
            bool find = false;

            for (auto &it : vec) {
                if (i >= it.size()) continue;

                find = true;
                sum += it[i] - '0';
            }

            if (!find && carry == 0)
                break;

            final.push_back((sum % 10) + '0');

            carry = sum / 10;
        }

        while (carry > 0) {
            final.push_back((carry % 10) + '0');
            carry /= 10;
        }

        reverse(final.begin(), final.end());

        return final;
    }
};