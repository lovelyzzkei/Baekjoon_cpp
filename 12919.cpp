#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
#include <unordered_map>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string a, b;
unordered_map<string, bool> visited;


int main(void)
{
    FAST_IO;
    cin >> a >> b;

    deque<string> dq;
    dq.push_back(b);
    visited[b] = true;

    while (!dq.empty()) {
        int size = dq.size();
        for (int i = 0; i < size; i++) {
            string curr = dq.front();
            dq.pop_front();

            if (!curr.compare(a)) 
            {
                cout << 1 << endl;
                return 0;
            }

            if (curr.size() < a.size()) {
                cout << 0 << endl;
                return 0;
            }
            int strSize = (int)curr.size();
            if (curr[strSize-1] == 'A')
            {
                string next1 = curr.substr(0, strSize-1);
                if (visited.find(next1) == visited.end()) 
                {
                    visited[next1] = true;
                    dq.push_back(next1);
                }
            }
            
            if (curr[0] == 'B')
            {
                reverse(curr.begin(), curr.end());
                string next2 = curr.substr(0, strSize-1);
                if (visited.find(next2) == visited.end())
                {
                    visited[next2] = true;
                    dq.push_back(next2);
                }

            }


        }
    }

    cout << 0 << endl;
    return 0;
}