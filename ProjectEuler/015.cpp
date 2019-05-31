/** Problem 15
 *
 * [Title]:
 * Lattice paths
 *
 * [Description]:
 * Starting in the top left corner of a 2×2 grid, and only being able to move
 *  to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * [Goal]:
 * How many such routes are there through a 20×20 grid?
 */

#include <bits/stdc++.h>
using namespace std;

const int size = 25;
int vis[size][size];
int ans = 0;

int dir[][2] = {0,1,1,0};

int check(int x, int y) {
    if(x<=0 || x>21 || y<=0 || y>21 || vis[x][y]==1)
        return 0;
    return 1;
}

void dfs(int x, int y) {
    if(vis[21][21]==1) {
        ans++;
        return ;
    }

    for(int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(check(nx, ny)) {
            // printf("(%d, %d) => (%d, %d)\n",x,y,nx,ny);
            vis[nx][ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfs(1,1);
    cout << ans << endl;
    return 0;
}