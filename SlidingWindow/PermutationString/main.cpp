#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

    bool isPerm(const unordered_map<char, int>& s1map, const unordered_map<char, int>& s2map) {
        return s1map == s2map;
    }

    // bool soln1(string s1, string s2)     {
    //     unordered_map<char, int> s1map;
    //     for(const char c : s1) {
    //         s1map[c]++;
    //     }
    //     int l = 0, r = 0, n = s2.size();
    //     unordered_map<char, int> wnd;
    //     while(r < n) {
    //         char rchar = s[r];
    //         if(s1map.find(rchar) == s1map.end()) {
    //             r++;
    //             continue;
    //         }
    //         wnd[rchar]++;
    //         if(isPerm(wnd, s1map)) return true;
    //         while(wnd.find(rchar) != wnd.end() && !isPerm) {
    //             char lchar = s[l];
    //             wnd[lchar]--;
    //             l++;
    //         }
    //         r++;
    //     }
    //     return false;
    // }

    void printMap(const unordered_map<char, int>& umap) {
        for(const auto& iter : umap) {
            cout<<iter.first<<" : "<<iter.second<<endl;
        }
    }

    bool checkInclusion(string s1, string s2) {
        int s1cnt = s1.size();
        int n = s2.size();
        unordered_map<char, int> s1map;
        for(const char c : s1) {
            s1map[c]++;
        }

        cout<<"s1"<<endl;
        printMap(s1map);

        cout<<"wnd:"<<endl;
        for(int i = 0; i <= n-s1cnt; i++) {
            // if(s1.find(s2[i]) != std::string::npos) {
            //     continue;
            // }
            unordered_map<char, int> wnd;
            for(int j = i; j < i+s1cnt-1; j++) {
                wnd[s2[j]]++;
            }
            
            printMap(wnd);
            cout<<endl;

            if(isPerm(wnd, s1map)) {
                return true;
            }
        }

        return false;
    }


int main() {
    string s1 = "adc";
    string s2 = "dcda";
    bool res = checkInclusion(s1, s2);
    string resstr = res == true ? "true" : "false";

    cout<<"result: "<<resstr<<endl;

    return 0;
}