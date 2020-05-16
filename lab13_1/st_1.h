#ifndef ST_H_INCLUDED
#define ST_H_INCLUDED

typedef struct symbletable *ST;

ST STinit(int maxN);
int hasha(char *v, int M);
int STinsert(ST st, char *s);
int STsearch(ST st, char *c);
char* STsearch_str(ST st, int i);
#endif // ST_H_INCLUDED
