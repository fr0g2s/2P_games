// textGUI.c

#include <stdio.h>
#include "textGUI.h"

#define CHARWIDTH 12
#define CHARHEIGHT 8

char player1[8][12] = {
       "   o o o   ",
       "  o     o  ",
       " o       o ",
       " o       o ",
       " o       o ",
       "  o     o  ",
       "   o o o   "
};
char player2[8][12] = {
       "  x     x  ",
       "   x   x   ",
       "    x x    ",
       "     x     ",
       "    x x    ",
       "   x   x   ",
       "  x     x  "
};
char space[12] = {"           "};

void drawMap(int map[MAPSIZE][MAPSIZE])
{
	unsigned int x, y;
	char *pix;

	x = y = 0;	// start drawing from (0,0)

	printf("\n\tmap size = %d * %d\n", MAPSIZE, MAPSIZE);

	for(int i=0;i<MAPSIZE;i++, x++){
		for(int line=0;line<MAPSIZE*6;line++){ printf("* "); }
		puts("");

		for(int h=0;h<CHARHEIGHT-1;h++){
			y=0;
			printf("* ");			
			
			for(int row=0;row<MAPSIZE;row++){
				if(map[x][y] == -1) pix=player1[h];
				else if(map[x][y] == 1) pix=player2[h];
				else pix=space;

				for(int w=0;w<CHARWIDTH;w++){	printf("%c",pix[w]);  }
				y++;
			}
			puts("*");
		}
	}
	for(int line=0;line<MAPSIZE*6;line++){ printf("* "); }
	puts("");
}

