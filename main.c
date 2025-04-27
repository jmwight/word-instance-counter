#include <stdio.h>
#include <stdlib.h>
#include "getword.h"

#define MXWLEN	50 /* 99.999% of all words are <= 50 characters */
#define TRUE	1u /* unsigned */
#define FALSE	0u

struct wnode *addword(struct wnode *wn, char *w, unsigned int *nw)
void fillwnodelist(struct wnode *wn, struct **wnodelist, int wnodelistlen)
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
	struct attr wattr;
	char w[MAXWLEN + 1]; /* + 1 for the trailing \0 character at the end of
				strings */
	struct wnode *root = NULL;
	unsigned int nw, uniquewcnt, totalwcnt;
	nw = uniquewcnt = totalwcnt = 0;

	/* get all words, put into tree, and get counts of unique words and
	 * total words */
	while((wattr = getword(w, MXWLEN + 1)) != EOF)
	{
		root = addword(root, w, &nw);
		totalwcnt++;
		/* add total count of unique words if we added new one to tree.
		 * This will be useful for creating size of array we will need
		 * to sort later by number of word appearances */
		if(nw)
		{
			uniquewcnt++;
			nw = FALSE;
		}
	}

	/* create a flat array that qsort can work with (it can't work with a
	 * binary tree */
	struct wnode *wnodearr[uniquewcnt];
	fillwnodelist(wnodearr, uniquewcnt);

	qsort_r(wnodearr, sizeof wnodearr / sizeof *wnodearr, sizeof *wnodearr,
			wcntcmp);

	/* print the results */
	/* pointer way of doing it */
	struct wnode *wnodeend, *wnodeptr;
	wnodeptr = wnodearr;
	wnodeend = wnodearr + uniquewcnt; /* one past the end */

	for( ; wnodeptr < wnodeend; wnodeptr++)
		printf("%d,\t%s\n", wnodeptr->count, wnodeptr->word);

	/* array index way of doing it */
	/*int i;
	for(i = 0; i < uniquewcnt; i++)
		printf("%d,\t%s\n", wnodearr->count, wnodearr->word);*/
}

/* addword: add word to binary tree if not already present and update word
 * count */
struct wnode *addword(struct wnode *wn, char *w, unsigned int *nw)
{
	if(wn == NULL)
	{
		/* method 1 */
		wn = (struct wnode *) malloc(sizeof(struct wnode));
		wn->word = w;
		wn->count = 1;
		wn->left = wn->right = NULL;
		*nw = TRUE;
	}
	/* input word is less than current node word */
	if(strcmp(w, wn->word) < 0)
		wn->left = addword(wn->left, w, nw);
	else if(strcmp(w, wn->word > 0))
		wn->right = addword(wn->right, w, nw);
	/* word is equal add to count */
	else
		wn->count++;

	return wn;
}

/* fillwnodelist: fill array of pointers to wnode */
void fillwnodelist(struct wnode *wn, struct **wnodelist, int wnodelistlen)
{
	if(wn != NULL)
	{
		fillwnodelist(wn->left, wnodelist, wnodelistlen);
		if(wnodelistlen-- > 0)
			*wnodelist++ = wn; /* TODO: MAKE SURE THIS IS CORRECT*/
		else
		{
			printf("Error: ran out of wordlist");
			return;
		}
		fillwnodelist(wn->right, wnodelist, wnodelistlen);
	}
}

/* wcntcmp: compare two counts inside two wnodes. Function to be used in input
 * to qsort for comparison function */
int wcntcmp(void *w0, void *w1)
{
	/* TODO: finish */
}
