#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Word
{
    char e[11],o[11];
}w[100000],*ptr,tmp;

int word_cmp(const void* aa, const void *bb)
{
    static Word *a, *b;
    a = (Word*)aa; b = (Word*)bb;
    return strcmp(a->o,b->o);
}

int main()
{
    char cpeek;
    int w_cnt=0;
    while(true)
    {
        cpeek = getchar();
        if( cpeek == '\n' )
            break;
        ungetc(cpeek, stdin);
        scanf("%s %s", w[w_cnt].e, w[w_cnt].o);
        getchar();
        w_cnt++;
    }
    qsort(w,w_cnt,sizeof(Word),word_cmp);
//    for(int i=0;i<w_cnt;i++)
//        printf("%s %s\n",w[i].e,w[i].o);
    while( scanf("%s",tmp.o) != EOF )
    {
        ptr = (Word*)bsearch( &tmp, w, w_cnt, sizeof(Word), word_cmp );
        if( ptr == NULL )
            puts("eh");
        else puts(ptr->e);
    }
}
