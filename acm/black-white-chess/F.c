/*
 * Black White Chess - F
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/06/27
 * @description
 *   Numbers of place that can chess be placed
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
			return SUCCESS;
		} else {
			return FAIL;
		}
	}
	return FAIL;
}

int (*func[])() = {left, right, up, down, left_up, left_down,
	right_up, right_down};
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
int main(void)
{
	int i, j;
	int count = 0;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			scanf("%hhu", &map[i][j]);
		}
	}
	scanf("%hhu", &chess);
	for (x = 0; x < MAP_SIZE; x++) {
		for (y = 0; y < MAP_SIZE; y++) {
			if (can_place() == SUCCESS) {
				count++;
			}
		}
	}
	printf("%d\n", count);
	
	return 0;
}
