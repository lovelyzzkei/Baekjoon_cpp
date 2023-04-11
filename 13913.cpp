#include <iostream>
#include <deque>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX_N 100001

using namespace std;

int start, k;
deque<int> dq;
int visited[MAX_N];


void BackTrace(int end)
{
    deque<int> stack;

    while (end != start) {
        stack.push_back(end);
        end = visited[end];
    }
    stack.push_back(start);

    while (!stack.empty()) {
        cout << stack.back() << " ";
        stack.pop_back();
    }

}

bool inRange(int n)
{
    return n >= 0 && n < MAX_N;
}


int main(void)
{
    cin >> start >> k;

    int step = 0, size, curr;
    bool isArrived = false;

    for (int i = 0; i < MAX_N; i++)
        visited[i] = -1;

    dq.push_back(start);

    while (!dq.empty()) {
        size = dq.size();
        for (int i = 0; i < size; i++) {
            curr = dq.front();
            dq.pop_front();

            if (curr == k)
            {
                isArrived = true;
                break;
            }

            if (inRange(curr+1) && visited[curr+1] == -1) 
            {
                visited[curr+1] = curr;
                dq.push_back(curr+1);
            }
            if (inRange(curr-1) && visited[curr-1] == -1)
            {
                visited[curr-1] = curr;
                dq.push_back(curr-1);
            }
            if (inRange(curr*2) && visited[curr*2] == -1)
            {
                visited[curr*2] = curr;
                dq.push_back(curr*2);
            }

        }

        if (isArrived)
            break;
        step++;
    }
    
    cout << step << endl;
    BackTrace(k);

    return 0;
}