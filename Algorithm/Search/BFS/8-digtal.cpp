#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<vector<int>> state;

map<int, int> dis;

state start;
state goal;


int dir[][2] = {0,1,1,0,-1,0,0,-1};

int hash_f(state& s) {
	int num = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			num = num *10 + s[i][j];
		}
	}
	return num;
}


void read(state& s) {
	int n;
	for(int i = 0; i < 3; ++i) {
		vector<int> temp;
		for(int j = 0; j < 3; ++j) {
			cin >> n;
			temp.pb(n);
		}
		s.pb(temp);
	}
}


void getzero(state& s, int& x, int& y) {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(s[i][j] == 0) {
				x = i;
				y = j;
				return ;
			}
		}
	}
}


int check(int x, int y) {
	if(x<0 || x>=3 || y<0 || y>=3)
		return 0;
	return 1;
}


void bfs() {
	queue<state> q;
	q.push(start);

	int zx,zy;

	while(1) {
		if(dis[hash_f(goal)] != 0) {
			break;
		}

		state s = q.front();
		q.pop();

		getzero(s, zx, zy);

		for(int i = 0; i < 4; ++i) {
			int nx = zx + dir[i][0];
			int ny = zy + dir[i][1];

			if(check(nx, ny)) {
				state temp = s;
				temp[nx][ny] ^= temp[zx][zy] ^= temp[nx][ny] ^= temp[zx][zy];
				if(dis[hash_f(temp)] == 0) {
					dis[hash_f(temp)] = dis[hash_f(s)] + 1;
					q.push(temp);
				}
			}
		}
	}
}


int main() {
	// fropen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	read(start);
	read(goal);
	bfs();
	cout << dis[hash_f(goal)] << endl;
 	return 0;
}