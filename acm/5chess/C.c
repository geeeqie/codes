/*
 * 5chess - C
 *
 * @author Geeeqie
 * @date 2011/06/27
 * @description
 */
#include <stdio.h>

typedef unsigned char u8;
#define MAP_SIZE 15

u8 map[MAP_SIZE][MAP_SIZE];

int main(void)
{
	int i, j;
	int x, y;
	int count;
	u8 chess;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			scanf("%hhu", &map[i][j]);
		}
	}
	scanf("%d%d", &x, &y);
	chess = map[x][y];
	count = 1;
	// left
	for (i = y - 1; i >= 0; i--, count++) {
		if (map[x][i] != chess) {
			break;
		}
	}
	for (i = y + 1; i < MAP_SIZE; i++, count++) {
		if (map[x][i] != chess) {
			break;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
