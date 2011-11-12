/*
 * THE MARS ROVER
 *
 *   Test problem from ThoughtWorks
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/10/15
 * @description
 */

/*
Specification
A squad of robotic rovers are to be landed by NASA on a plateau on Mars. This plateau, which is curiously rectangular, must be navigated by the rovers so that their on board cameras can get a complete view of the surrounding terrain to send back to Earth. A rover's position is represented by a combination of an x and y co-ordinates and a letter representing one of the four cardinal compass points. The plateau is divided up into a grid to simplify navigation. An example position might be 0, 0, N, which means the rover is in the bottom left corner and facing North. In order to control a rover, NASA sends a simple string of letters. The possible letters are 'L', 'R' and 'M'. 'L' and 'R' makes the rover spin 90 degrees left or right respectively, without moving from its current spot. 'M' means move forward one grid point, and maintain the same heading. Assume that the square directly North from (x, y) is (x, y+1).

Input
The first line of input is the upper-right coordinates of the plateau, the lower-left coordinates are assumed to be 0,0. The rest of the input is information pertaining to the rovers that have been deployed. Each rover has two lines of input. The first line gives the rover's position, and the second line is a series of instructions telling the rover how to explore the plateau. The position is made up of two integers and a letter separated by spaces, corresponding to the x and y co-ordinates and the rover's orientation. Each rover will be finished sequentially, which means that the second rover won't start to move until the first one has finished moving.

Output
The output for each rover should be its final co-ordinates and heading.

Test Input
5 5
1 2 N
LMLMLMLMM
3 3 E
MMRMMRMRRM

Expected Output
1 3 N
5 1 E
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

struct rover {
	uint8_t face;
	int x, y;
};

enum {
	EAST,
	SOUTH,
	WEST,
	NORTH,
	NR_FACES,
};

char face_i2c[NR_FACES] = "ESWN";
uint8_t face_c2i['W'+1] = {
	['E'] = EAST, ['S'] = SOUTH, ['W'] = WEST, ['N'] = NORTH
}; /* only for gcc */

#define INSTRUCTION_MAX 1024

int width, height;

void instruction(struct rover *pr, char c_ins)
{
	assert(c_ins=='L' || c_ins=='R' || c_ins=='M');
	switch(c_ins) {
	case 'L': pr->face = (pr->face+NR_FACES-1) % NR_FACES;
		  break;
	case 'R': pr->face = (pr->face+1) % NR_FACES;
		  break;
	case 'M': 
		  switch(pr->face) {
		  case EAST:	pr->x++; break;
		  case SOUTH:	pr->y--; break;
		  case WEST:	pr->x--; break;
		  case NORTH:	pr->y++; break;
		  default: break;
		  }
		  break;
	default:break;
	}
	assert(pr->x >= 0);
	assert(pr->x <= width);
	assert(pr->y >= 0); 
	assert(pr->y <= height);
}

int main(void)
{
	struct rover r;
	char c_face, str_ins[INSTRUCTION_MAX];

	scanf("%d%d", &width, &height);
	assert(width >= 0);
	assert(height >= 0);
	while(scanf("%d%d %c", &r.x, &r.y, &c_face) != EOF) {
		int i, len;

		assert(r.x >= 0);
		assert(r.y >= 0);
		assert(c_face=='E' || c_face=='S' || c_face=='W' || c_face=='N');
		r.face = face_c2i[c_face];
		scanf("%s", str_ins);
		len = strlen(str_ins);
		for (i = 0; i < len; i++) {
			instruction(&r, str_ins[i]);
		}
		printf("%d %d %c\n", r.x, r.y, face_i2c[r.face]);
	}
	return 0;
}
