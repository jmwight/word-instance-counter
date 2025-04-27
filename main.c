#include <stdio.h>
#include <stdlib.h>

struct wnode *addword(struct wnode *wn, char *w)
void fillwnodelist(struct **wnodelist, int wnodelistlen)
int wcntcmp(void *w0, void *w1)

struct wnode
{
	char *word;
	unsigned int count;
	struct wnode *left;
	struct wnode *right;
};

int main(void)
{
	/* TODO: basic layout for function */
}

/* addword: add word to binary tree if not already present and update word 
 * count */
struct wnode *addword(struct wnode *wn, char *w)
{
	/* TODO finish */
}

/* fillwnodelist: fill array of pointers to wnode */
void fillwnodelist(struct **wnodelist, int wnodelistlen)
{
	/* TODO: finish */
}

/* wcntcmp: compare two counts inside two wnodes. Function to be used in input
 * to qsort for comparison function */
int wcntcmp(void *w0, void *w1)
{
	/* TODO: finish */
}
