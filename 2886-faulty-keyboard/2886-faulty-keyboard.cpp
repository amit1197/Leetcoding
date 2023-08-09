class Solution {
public:
    string finalString(string s) {
        // string c="";
        // for(auto i:s){
        //     if(i=='i'){
        //         reverse(c.begin(),c.end());
        //     }
        //     else{
        //         c+=i;
        //     }
        // }
        // return c;

        int n = s.size();

        int m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'i') {
                continue;
            }
            m++;
        }

        vector<char> out(m, 'a');

        int currIdx = n - 1;
        int head = 0;
        int tail = m - 1;

        int ptr = tail;

        while(currIdx >= 0) {
            if (s[currIdx] == 'i') {
                ptr = (ptr == head) ? tail : head;
                currIdx--;
                continue;
            }

            if (ptr == tail) {
                out[tail--] = s[currIdx];
                ptr = tail;
            } else {
                out[head++] = s[currIdx];
                ptr = head;
            }

            currIdx--;
        }

        string res;
        for (int i = 0; i < out.size(); i++) {
            res.push_back(out[i]);
        }

        return res;
    }
};