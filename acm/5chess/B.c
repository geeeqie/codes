/*
 * 5chess - B
 *
 * @author Geeeqie
 * @date 2011/06/27
 * @description
 *   Number of same chess on the top right
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
	for (i = x-1, j = y+1, count = 1; (i >= 0) && (j < MAP_SIZE); i--, j++, count++) {
		if (map[i][j] != chess) {
			break;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
