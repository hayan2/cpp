#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

const int ROW = 8;
const int COL = 8;

void whitePawnAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {
	const int MOVE = 2;
	
	int dr[MOVE] = { -1, 1 };
	int dc[MOVE] = { 1, 1 };

	for (int i = 0; i < MOVE; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;

		attacked[nr][nc] = true;
	}
}

void blackPawnAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

void knightAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

void bishopAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

void rookAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

void queenAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

void kingAttacks(char board[ROW][COL], bool attacked[ROW][COL], int r, int c) {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inp;
		
	while (cin >> inp) {
		vector<string> cache;
		istringstream iss(inp);
		string buf;

		while (getline(iss, buf, '/')) cache.push_back(buf);

		char board[ROW][COL];
		bool attacked[ROW][COL];

		memset(board, '.', sizeof board);
		memset(attacked, false, sizeof attacked);

		for (int i = 0; i < ROW; i++) {
			int j = 0;
			for (char ch : cache[i]) {
				if (isdigit(ch)) j += (ch - '0');
				else {
					board[i][j] = ch;
					j++;
				}
			}
		}

		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (board[i][j] == 'p') {
					blackPawnAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'P') {
					whitePawnAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'n' || board[i][j] == 'N') {
					knightAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'b' || board[i][j] == 'B') {
					bishopAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'r' || board[i][j] == 'R') {
					rookAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'q' || board[i][j] == 'Q') {
					queenAttacks(board, attacked, i, j);
				}
				else if (board[i][j] == 'k' || board[i][j] == 'K') {
					kingAttacks(board, attacked, i, j);
				}
			}
		}
	}

	return 0;
}