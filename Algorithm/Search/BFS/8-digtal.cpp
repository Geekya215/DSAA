#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> state;

state start;
state goal;

int dir[][2] = {1,0,0,1,-1,0,0,-1};

map<int, int> dis;

int hash_f(state& s) {
	long long num = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j)
			num = num*10 + s[i][j];
	}
	return num;
}

void getzero(state& s, int &x, int &y) {

	for(int i = 0 ; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(s[i][j] == 0) {
				x = i;
				y = j;
				return ;
			}
		}
	}
}

int check(state& s, int x, int y) {
	if(x<0 || x>=3 || y<0 || y>=3 || dis.find(hash_f(s)) != dis.end())
		return 0;
	return 1;
}


void bfs() {
	queue<state> q;
	q.push(start);
	int tx, ty;
	while(1) {
		state s = q.front();
		q.pop();

		if(dis.find(hash_f(goal)) != dis.end()) {
			break;
		}

		getzero(s,tx,ty);

		for(int i = 0; i < 4; ++i) {
			int nx = tx + dir[i][0];
			int ny = ty + dir[i][1];
			state temp = s;
			temp[tx][ty] ^= s[nx][ny] ^= temp[tx][ty] ^= s[nx][ny];
			if(check(temp,nx,ny)) {
				// swap position
				q.push(temp);
				dis[hash_f(temp)] = dis[hash_f(s)] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int num;
	for(int i = 0; i < 3; ++i) {
		vector<int> temp;
		for(int j = 0; j < 3; ++j) {
			cin >> num;
			temp.push_back(num);
		}
		start.push_back(temp);
	}

	for(int i = 0; i < 3; ++i) {
		vector<int> temp;
		for(int j = 0; j < 3; ++j) {
			cin >> num;
			temp.push_back(num);
		}
		goal.push_back(temp);
	}

	bfs();

	cout << dis[hash_f(goal)] << endl;
	return 0;
}