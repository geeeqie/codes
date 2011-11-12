/*
 * Black White Chess - E
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/06/27
 * @description
 *   diplay the placed status
 */
#include <stdio.h>

typedef unsigned char u8;
#define MAP_SIZE 8

u8 map[MAP_SIZE][MAP_SIZE];
int x, y;
int count;
u8 chess;

enum {
	SUCCESS = 0,
	FAIL = 1,
};
enum {
	BLANK = 0,
	WHITE = 1,
	BLACK = 2,
};

#define reverse_chess(c) (c == BLACK ? WHITE : BLACK)
int left()
{
	int i, j;
	
	if (y - 1 < 0 || map[x][y-1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = y - 1; i >= 0; i--) {
		if (map[x][i] == reverse_chess(chess)) {
			continue;
		} else if (map[x][i] == chess) {
			int m;
			for (m = i + 1; m <= y - 1; m++) {
				map[x][m] = reverse_chess(map[x][m]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right()
{
	int i, j;
	
	if (y + 1 >= MAP_SIZE || map[x][y+1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = y + 1; i <= MAP_SIZE; i++) {
		if (map[x][i] == reverse_chess(chess)) {
			continue;
		} else if (map[x][i] == chess) {
			int m;
			for (m = i - 1; m >= y + 1; m--) {
				map[x][m] = reverse_chess(map[x][m]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int up()
{
	int i, j;
	
	if (x - 1 < 0 || map[x - 1][y] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1; i >= 0; i--) {
		if (map[i][y] == reverse_chess(chess)) {
			continue;
		} else if (map[i][y] == chess) {
			int m;
			for (m = i + 1; m <= x - 1; m++) {
				map[m][y] = reverse_chess(map[m][y]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int down()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || map[x + 1][y] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1; i < MAP_SIZE; i++) {
		if (map[i][y] == reverse_chess(chess)) {
			continue;
		} else if (map[i][y] == chess) {
			int m;
			for (m = i - 1; m >= x + 1; m--) {
				map[m][y] = reverse_chess(map[m][y]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}

int left_up()
{
	int i, j;
	
	if (x - 1 < 0 || y - 1 < 0 || map[x - 1][y - 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			int m, n;
			for (m = i+1, n = j+1; m <= x - 1 && n <= y - 1; m++, n++) {
				map[m][n] = reverse_chess(map[m][n]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right_up()
{
	int i, j;
	
	if (x - 1 < 0 || y + 1 >= MAP_SIZE || map[x - 1][y + 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1, j = y + 1; i >= 0 && j < MAP_SIZE; i--, j++) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			int m, n;
			for (m = i+1, n = j-1; m <= x - 1 && n >= y + 1; m++, n--) {
				map[m][n] = reverse_chess(map[m][n]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right_down()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || y + 1 >= MAP_SIZE || map[x + 1][y + 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1, j = y + 1; i < MAP_SIZE && j < MAP_SIZE; i++, j++) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			int m, n;
			for (m = i-1, n = j-1; m >= x + 1 && n >= y + 1; m--, n--) {
				map[m][n] = reverse_chess(map[m][n]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int left_down()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || y - 1 < 0 || map[x + 1][y - 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1, j = y - 1; i < MAP_SIZE && j >= 0; i++, j--) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			int m, n;
			for (m = i-1, n = j+1; m >= x + 1 && n <= y - 1; m--, n++) {
				map[m][n] = reverse_chess(map[m][n]);
			}
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}

int (*func[])() = {left, right, up, down, left_up, left_down,
	right_up, right_down};

int main(void)
{
	int i, j;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			scanf("%hhu", &map[i][j]);
		}
	}
	scanf("%d%d%hhu", &x, &y, &chess);
	for (i = 0; i < sizeof(func)/sizeof(func[0]); i++) {
		func[i]();
	}
	map[x][y] = chess;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			printf("%hhu", map[i][j]);
			if (j != MAP_SIZE - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
