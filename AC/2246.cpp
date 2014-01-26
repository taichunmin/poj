#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int matrix[26][2],mat_top,mat[100000][2],op_top,strl,ans;
char op[100000];

int inline code(char ca)
{
    if( ca == '(' )
        return 1;
    if( ca == ')' )
        return 2;
    if( ca == '*' )
        return 3;
    return 4;
}
bool do_op(char ca)
{
    if(ca=='*')
    {
        if(mat_top<2)
            return false;
        if( mat[mat_top-2][1] != mat[mat_top-1][0] )
            return false;
        ans += mat[mat_top-2][0] * mat[mat_top-2][1] * mat[mat_top-1][1];
        mat[mat_top-2][1] = mat[mat_top-1][1];
        mat_top--;
        return true;
    }
    return false;
}
void debug()
{
    fflush(stdin);
    printf("op : ");
    for(int i=0;i<op_top;i++)
        printf("%c ",op[i]);
    puts("");
    printf("mat: ");
    for(int i=0;i<mat_top;i++)
        printf("(%d,%d) ",mat[i][0],mat[i][1]);
    puts("");
    getchar();
}

int main()
{
    int ia,ib,ic;
    cin>>ia;
    char ca,str[100000];
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<ia;i++)
    {
        cin>>ca>>ib>>ic;
        matrix[ ca-'A' ][0]=ib;
        matrix[ ca-'A' ][1]=ic;
    }
    getchar();
    while(gets(str)!=NULL)
    {
        mat_top=op_top=ans=0;
        strl = strlen(str);
        bool is_error = false;
        for(int i=0;i<strl;i++)
        {
            if( i>0 && str[i-1]!='(' && str[i]!=')' )
                op[ op_top++ ] = '*';
            if( code(str[i]) == 4 )
            {
                mat[ mat_top ][0] = matrix[str[i]-'A'][0];
                mat[ mat_top ][1] = matrix[str[i]-'A'][1];
                mat_top++;
            }
            else
            {
                while( op_top > 0 && str[i]!='(' && code(op[op_top-1])>=code(str[i]) )
                    is_error |= !do_op(op[--op_top]);
                if( str[i] == ')' )
                    op_top--;
                else op[ op_top++ ] = str[i];
            }
//            debug();
        }
        while( op_top > 0 )
            is_error |= !do_op(op[--op_top]);
        if(is_error || mat_top!=1)
            puts("error");
        else printf("%d\n",ans);
    }
}
