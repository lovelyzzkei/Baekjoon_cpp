#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <memory.h>

#define R 1001
#define C 1001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int r, c;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char maze[R][C];
bool visited[R][C];
bool burned[R][C];
deque<pair<int, int>> user;
deque<pair<int, int>> fire;

bool isEdge(int y, int x)
{
    return (y == 0 || y == r-1 || x == 0 || x == c-1);
}

bool inRange(int y, int x)
{
    return (0 <= y && y < r) && (0 <= x && x < c);
}

int escapeMaze()
{
    int time = 0;
    bool isEscape = false;

    while (!user.empty()) {
        int size = user.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = user.front();
            int cy = curr.first;
            int cx = curr.second;
            user.pop_front();

            if (burned[cy][cx])
                continue;

            if (isEdge(cy, cx))
            {   
                isEscape = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (inRange(ny, nx) && !visited[ny][nx] && !burned[ny][nx] && maze[ny][nx] == '.')
                {
                    visited[ny][nx] = true;
                    user.push_back(make_pair(ny, nx));
                }
            }
        }

        size = fire.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = fire.front();
            int cy = curr.first;
            int cx = curr.second;
            fire.pop_front();

            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (inRange(ny, nx) && !burned[ny][nx] && maze[ny][nx] == '.')
                {
                    burned[ny][nx] = true;
                    fire.push_back(make_pair(ny, nx));
                }
            }

        }

        time++;
        if (isEscape)
            break;
    }

    return (isEscape) ? time : -1;
}

int main(void)
{
    FAST_IO;
    cin >> r >> c;

    memset(visited, 0, R*C*sizeof(bool));
    memset(burned, 0, R*C*sizeof(bool));

    string input;

    for (int i = 0; i < r; i++) {
        cin >> input;
        for (int j = 0; j < c; j++) {
            maze[i][j] = input[j];
            if (input[j] == 'J')
            {
                user.push_back(make_pair(i, j));
                visited[i][j] = true;
                maze[i][j] = '.';
            }
            if (input[j] == 'F')
            {
                fire.push_back(make_pair(i, j));
                burned[i][j] = true;
                maze[i][j] = '.';
            }
        }
    }


    int escapeTime = escapeMaze();
    if (escapeTime != -1) 
        cout << escapeTime;
    else
        cout << "IMPOSSIBLE";

    return 0;
}