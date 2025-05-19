#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int max, depth;
    printf("Max size of string: ");
    scanf("%d", &max);
    printf("Depth: ");
    scanf("%d", &depth);
    char* plain = malloc(max*sizeof(char));
    char* cipher = malloc(max*sizeof(char));
    printf("Plain text: ");
    scanf("%s", plain);
    for(int k=0, j=0; k<depth; k++){
        for(int i=k; i<strlen(plain); i+=(depth-1)*2, j++){
            *(cipher+j)=*(plain+i);
        }
    }
    // print
    for(int i=0; i<strlen(cipher); i++){
        printf("%c", *(cipher+i));
    }
    return 0;
}