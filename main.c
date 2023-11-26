#include <stdio.h>

int main(int argc, char const *argv[])
{
    char * x = "[x]";
    char * o = "[o]";
    char * e = "[ ]";
    char * w = "[█]";
    
    int board[72];
    int i=0;
    for (i; i< 72; i ++){
        board[i]= i;
    }
    i= 0;
    for (i;i<72 ; i++){
        if(i % 9 == 0){
            printf("\n%s",w);
        }
        else if (i < 9 || i > 62)
        {
            printf("%s",w);
        }
        else if (i % 9 == 8)
        {
            printf("%s",w);
        }
        else{
        printf("%s",e);

        }

    }
    printf("\n\n");
    return 0;
}
