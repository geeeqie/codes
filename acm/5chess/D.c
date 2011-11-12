/*
 * 5chess - D
 *
 * @author Geeeqie
 * @date 2011/06/28
 * @description
 */
#include <stdio.h>

typedef unsigned char u8;
#define MAP_SIZE 15

enum {
	SUCCESS = 0,
	FAIL = 1,
};

u8 map[MAP_SIZE][MAP_SIZE];
int x, y;

int horizontal_5chess(int chess)
{
	int i;
	int count = 1;
	// left
	for (i = y - 1; i >= 0; i--, count++) {
		if (map[x][i] != chess) {
			break;
		}
	}
	// right
	for (i = y + 1; i < MAP_SIZE; i++, count++) {
		if (map[x][i] != chess) {
			break;
		}
	}
	return (count == 5) ? SUCCESS:FAIL;
}

int vertical_5chess(int chess)
{
	int i;
	int count = 1;
	// left
	for (i = x - 1; i >= 0; i--, count++) {
		if (map[i][y] != chess) {
			break;
		}
	}
	// right
	for (i = x + 1; i < MAP_SIZE; i++, count++) {
		if (map[i][y] != chess) {
			break;
		}
	}
	return (count == 5) ? SUCCESS:FAIL;
}

int left_top_right_down_5chess(int chess)
{
	int i, j;

	int count = 1;
	// to left top
	for (i = x - 1, j = y - 1; (i >= 0) && (j >= 0); i--, j--, count++) {
		if (map[i][j] != chess) {
			break;
		}
	}
	// to right down
	for (i = x + 1, j = y + 1; (i < MAP_SIZE) && (j < MAP_SIZE); i++, j++, count++) {
		if (map[i][j] != chess) {
			break;
		}
	}
	return (count == 5) ? SUCCESS:FAIL;
}

int right_top_left_down_5chess(int chess)
{
	int i, j;

	int count = 1;
	// to right top
	for (i = x - 1, j = y + 1; (i >= 0) && (j < MAP_SIZE); i--, j++, count++) {
		if (map[i][j] != chess) {
			break;
		}
	}
	// to left down
	for (i = x + 1, j = y - 1; (i < MAP_SIZE) && (j >= 0); i++, j--, count++) {
		if (map[i][j] != chess) {
			break;
		}
	}
	return (count == 5) ? SUCCESS:FAIL;
}

int (*func[])(int) = {horizontal_5chess, vertical_5chess, left_top_right_down_5chess, right_top_left_down_5chess};

int main(void)
{
	int i, j;
	int count;
	u8 chess;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			scanf("%hhu", &map[i][j]);
		}
	}
	scanf("%d%d%hhu", &x, &y, &chess);
	for (i = 0; i < sizeof(func) / sizeof(func[0]); i++) {
		if (func[i](chess) == SUCCESS) {
			printf("Yes\n");
			break;
		}
	}

	if (i == (sizeof(func) / sizeof(func[0]))) {
		printf("No\n");
	}
	
	return 0;
}
