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
u8 map1[MAP_SIZE][MAP_SIZE];
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

int chess_count(int chess)
{
	int c = 0;
	int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == chess) {
				c++;
			}
		}
	}
	return c;
}

int can_place();

int main(void)
{
	int i, j;
	int best_x, best_y;
	int max;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			scanf("%hhu", &map1[i][j]);
		}
	}
	scanf("%hhu", &chess);
	
	max = 0;
	for (x = 0; x < MAP_SIZE; x++) {
		for (y = 0; y < MAP_SIZE; y++) {
			int c;

			for (i = 0; i < MAP_SIZE; i++) {
				for (j = 0; j < MAP_SIZE; j++) {
					map[i][j] = map1[i][j];
				}
			}
			if (can_place() != SUCCESS) continue;
			for (i = 0; i < sizeof(func)/sizeof(func[0]); i++) {
				func[i]();
			}
			map[x][y] = chess;
			c = chess_count(chess);
			if (c > max) {
				best_x = x;
				best_y = y;
				max = c;
			}
		}
	}
	if (max > 0) {
		printf("%d %d\n", best_x, best_y);
	} else {
		printf("Impossible\n");
	}
	
	return 0;
}
////////////////////////////////////////////////////
int left1()
{
	int i, j;
	
	if (y - 1 < 0 || map[x][y-1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = y - 1; i >= 0; i--) {
		if (map[x][i] == reverse_chess(chess)) {
			continue;
		} else if (map[x][i] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right1()
{
	int i, j;
	
	if (y + 1 >= MAP_SIZE || map[x][y+1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = y + 1; i <= MAP_SIZE; i++) {
		if (map[x][i] == reverse_chess(chess)) {
			continue;
		} else if (map[x][i] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int up1()
{
	int i, j;
	
	if (x - 1 < 0 || map[x - 1][y] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1; i >= 0; i--) {
		if (map[i][y] == reverse_chess(chess)) {
			continue;
		} else if (map[i][y] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int down1()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || map[x + 1][y] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1; i < MAP_SIZE; i++) {
		if (map[i][y] == reverse_chess(chess)) {
			continue;
		} else if (map[i][y] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}

int left_up1()
{
	int i, j;
	
	if (x - 1 < 0 || y - 1 < 0 || map[x - 1][y - 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right_up1()
{
	int i, j;
	
	if (x - 1 < 0 || y + 1 >= MAP_SIZE || map[x - 1][y + 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x - 1, j = y + 1; i >= 0 && j < MAP_SIZE; i--, j++) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int right_down1()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || y + 1 >= MAP_SIZE || map[x + 1][y + 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1, j = y + 1; i < MAP_SIZE && j < MAP_SIZE; i++, j++) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}
int left_down1()
{
	int i, j;
	
	if (x + 1 >= MAP_SIZE || y - 1 < 0 || map[x + 1][y - 1] != reverse_chess(chess)) {
		return FAIL;
	}
	for (i = x + 1, j = y - 1; i < MAP_SIZE && j >= 0; i++, j--) {
		if (map[i][j] == reverse_chess(chess)) {
			continue;
		} else if (map[i][j] == chess) {
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}

int (*func1[])() = {left1, right1, up1, down1, left_up1, left_down1,
	right_up1, right_down1};
int can_place()
{
	int r;
	int i, j;
	if (map[x][y] == BLANK) {
		for (i = 0; i < sizeof(func)/sizeof(func[0]); i++) {
			r = func[i]();
			if (r == SUCCESS) {
				//printf("Yes\n");
				return SUCCESS;
				break;
			}
		}
		if (i == sizeof(func)/sizeof(func[0])) {
			//printf("No\n");
			return FAIL;
		}
	} else {
		// printf("No\n");
		return FAIL;
	}
}
