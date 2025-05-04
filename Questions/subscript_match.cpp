//Leetcode3407. Substring Matching Pattern

class Solution {
    public:
        bool hasMatch(string s, string p) {
            int idx=p.find('*');
            string p1, p2;
            p1 = p.substr(0, idx);
            p2 = p.substr(idx+1);
    
            if(p1.size()+ p2.size()==0) return true;
    
            if(p1.size()==0 && p2.size()>0)
            {
                if(s.find(p2)==string::npos) return false;
                else return true;
            }
    
            else if(p2.size()==0 && p1.size()>0)
            {
                if(s.find(p1)==string::npos) return false;
                else return true;
            }
            else
            {
                idx = s.find(p1);
                if(idx<0) return false;
                int start = idx+p1.size();
                //cout<<"start: "<<start<<" found?: "<<s.find(p2, start)<<" p2 is:"<<p2<<endl;
                if(s.find(p2, start)!=string::npos) return true;
            }
    
            return false;
    
        }
    };