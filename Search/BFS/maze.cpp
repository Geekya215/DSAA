#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pos;
typedef pair<pos, char> dirc;

const int size = 1e2+5;

dirc dir[4] = {
    dirc(pos(1,0),'D'),
    dirc(pos(0,1),'R'),
    dirc(pos(-1,0),'U'),
    dirc(pos(0,-1),'L')
};


int sx,sy,gx,gy;
int n,m;
int a[size][size];
int vis[size][size];
int dis[size][size];
pos tr[size][size];
char dtr[size][size];
stack<pos> s;

int check(int i, int j) {
    if(i<=0 || i>n || j<=0 || j>m || vis[i][j]==1 || a[i][j]==1)
	    return 0;
    return 1;
}


void bfs(int x, int y) {
    pos p(x,y);
    queue<pos> q;
    q.push(p);

    while(!q.empty()) {
        p = q.front();
	q.pop();
	for(int i = 0; i < 4; ++i) {
	    int tx = p.fi + dir[i].fi.fi;
	    int ty = p.se + dir[i].fi.se;
	    if(check(tx,ty)) {
		q.push(pos(tx,ty));
		vis[tx][ty] = 1;
		dis[tx][ty] = dis[p.fi][p.se] + 1;
		tr[tx][ty] = p;
		dtr[tx][ty] = dir[i].se;
	    }
	}	
    }
}

void print_path() {
    int tx = gx;
    int ty = gy;
    int x,y;
    int cnt = 0;
    s.push(pos(gx,gy));
    while(tx!=sx || ty!=sy) {
        s.push(tr[tx][ty]);
	x = tr[tx][ty].fi;
	y = tr[tx][ty].se;
	tx = x, ty = y;
    }

    tx = s.top().fi;
    ty = s.top().se;
    s.pop();
    while(!s.empty()) {
	x = s.top().fi;
	y = s.top().se;
	printf("step[%d]:(%d,%d) => (%d,%d) <%c>\n",++cnt,tx,ty,x,y,dtr[x][y]);
	tx = x;
	ty = y;
	s.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
	for(int j = 1; j <= m; ++j) 
	    cin >> a[i][j];
    }
    cin >> sx >> sy >> gx >> gy;
    bfs(sx,sy);
    cout << dis[gx][gy] << endl;
    print_path();
}
