#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int BOARD_SIZE = 9;
const int MOVE_R = 0;
const int MOVE_L = 1;
const int MOVE_B = 2;
const int MOVE_T = 3;
const int MOVE_RT = 4;
const int MOVE_LT = 5;
const int MOVE_RB = 6;
const int MOVE_LB = 7;
const int KING = 1;
const int STONE = -1;

int dx[BOARD_SIZE] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[BOARD_SIZE] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int board[BOARD_SIZE][BOARD_SIZE] = { 0, };
int kx = 0, ky = 0, sx = 0, sy = 0;

bool canMove(int x, int y) {
	return (x >= 1 && y >= 1 && x < BOARD_SIZE && y < BOARD_SIZE);
}

void solve(const int move) {
	int nx = kx + dx[move];
	int ny = ky + dy[move];

	if (!canMove(nx, ny)) return;

	if (board[nx][ny] == STONE) {
		int snx = nx + dx[move];
		int sny = ny + dy[move];

		if (!canMove(snx, sny)) return;

		board[nx][ny] = KING;
		board[snx][sny] = STONE;

		sx = snx, sy = sny;
	}
	else board[nx][ny] = KING;

	board[kx][ky] = 0;
	kx = nx, ky = ny;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	string king, stone;
	cin >> king >> stone >> m;

	board[kx = king[0] - 'A' + 1][ky = king[1] - '0'] = KING;
	board[sx = stone[0] - 'A' + 1][sy = stone[1] - '0'] = STONE;
	
	string move = "";
	while (m--) {
		cin >> move;
		
		if (move == "R") solve(MOVE_R);
		else if (move == "L") solve(MOVE_L);
		else if (move == "B") solve(MOVE_B);
		else if (move == "T") solve(MOVE_T);
		else if (move == "RT") solve(MOVE_RT);
		else if (move == "LT") solve(MOVE_LT);
		else if (move == "RB") solve(MOVE_RB);
		else if (move == "LB") solve(MOVE_LB);
	}	

	cout << char(kx + 'A' - 1) << ky << "\n" << char(sx + 'A' - 1) << sy;

	return 0;
}