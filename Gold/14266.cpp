#include <iostream>
#include <deque>
#include <utility>
#include <memory.h>

#define S 1001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int s;
bool visited[2*S][2*S];

int makeEmoticon()
{
    visited[1][0] = true;
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(1, 0));

    int time = 0;
    bool isFinished = false;

    while (!dq.empty()) {
        int size = (int)dq.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = dq.front();
            dq.pop_front();

            int numEmoticon = curr.first;
            int numClipboard = curr.second;

            if (numEmoticon == s)
            {
                isFinished = true;
                break;
            }

            // 1. store in clipboard
            if (!visited[numEmoticon][numEmoticon])
            {
                visited[numEmoticon][numEmoticon] = true;
                dq.push_back(make_pair(numEmoticon, numEmoticon));
            }

            int next = numEmoticon + numClipboard;
            if (next < 2*s && !visited[next][numClipboard])
            {
                visited[next][numClipboard] = true;
                dq.push_back(make_pair(next, numClipboard));
            }

            next = numEmoticon - 1;
            if (next >= 0 && !visited[next][numClipboard])
            {
                visited[next][numClipboard] = true;
                dq.push_back(make_pair(next, numClipboard));
            }
        }

        if (isFinished)
            break;

        time++;
    }

    return time;
}

int main(void)
{
    FAST_IO;
    cin >> s;
    memset(visited, 0, 4*S*S*sizeof(bool));

    cout << makeEmoticon();
    return 0;
}