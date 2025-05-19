#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char AZ[25]={'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void ij(char** str){
    for(int i=0; i<strlen(*str); i++){
        if(*(*str+i)=='j')  *(*str+i)='i';
    }
}

int mat_srch(char* mat, char** keyword, int letter){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i+j<=letter){
                if(*(mat+i+j)==*(*keyword+letter)){
                    i=0; j=0;
                    letter++;
                }
            }
            else
                i=5; j=5;
        }
    }
    return letter;
}

void fill(char mat[5][5], int pos){
    for(int k=0; k<25; k++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(AZ[k]==mat[i][j]){
                    i=5; j=5;
                }
                else if(i*5+j==pos-1){
                    int temp_i = (j+1)%5==0?i+1:i;
                    int temp_j = (j+1)%5;
                    mat[temp_i][temp_j]=AZ[k];
                    pos++;
                }
            }
        }
    }
}

void print(char mat[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%c\t", mat[i][j]);
        }
        printf("\n");
    }
}

void coordinates(char mat[5][5], char*** plain, int k, int* x1, int* y1, int* x2, int* y2){
    // Cell index [x][y]
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(mat[i][j]==*(**plain+k)){
                *x1=i;
                *y1=j;
            }
            if(mat[i][j]==*(**plain+k+1)){
                *x2=i;
                *y2=j;
            }
        }
    }
}

void rectangle(char mat[5][5], char** cipher, int k, int x1, int y1, int x2, int y2){
    if(x1==x2){
        *(*cipher+k)=mat[x1][(y1+1)%5];
        *(*cipher+k+1)=mat[x2][(y2+1)%5];
    }
    else if(y1==y2){
        *(*cipher+k)=mat[(x1+1)%5][y1];
        *(*cipher+k+1)=mat[(x2+1)%5][y2];
    }
    else{                
        *(*cipher+k)=mat[x1][y2];
        *(*cipher+k+1)=mat[x2][y1];
    }
}

void cipher_gen(char** plain, char mat[5][5]){
    char* cipher=(char*)malloc(sizeof(char));
    int x1, y1, x2, y2;
    int len=strlen(*plain);
    for(int k=0; k<len; k=k+2){
        // For different characters in pair
        if(*(*plain+k)!=*(*plain+k+1)){
            coordinates(mat, &plain, k, &x1, &y1, &x2, &y2);
            rectangle(mat, &cipher, k, x1, y1, x2, y2);
        }

        // For same characters in pair
        else if(*(*plain+k)==*(*plain+k+1)){
            // Adding 'X' on 2nd position of the pair by shifting each letters to one step right from that position
            for(int i=strlen(*plain); i>k+1; i--)
                *(*plain+i)=*(*plain+i-1);
            *(*plain+k+1)='x';
            len++;

            coordinates(mat, &plain, k, &x1, &y1, &x2, &y2);
            rectangle(mat, &cipher, k, x1, y1, x2, y2);
        }

        // For single character having no pair
        else{
            *(*plain+k+1)='x';
            len++;
            coordinates(mat, &plain, k, &x1, &y1, &x2, &y2);
            rectangle(mat, &cipher, k, x1, y1, x2, y2);
        }
    }
    printf("Cipher: ");
    for(int i=0; i<len; i++){
        printf("%c", *(cipher+i));
    }
    free(cipher);
}

int main(){
    char* keyword=(char*)malloc(sizeof(char));
    char matrix[5][5];
    char* plain=(char*)malloc(sizeof(char));
    printf("Keyword: ");
    scanf("%s", keyword);
    // Chaning 'J' to 'I' if any
    ij(&keyword);

    for(int i=0,letter=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(letter<strlen(keyword)){
                // Check if there exists matching character in the matrix previously. If so give a unique one.
                letter=mat_srch(&matrix[0][0], &keyword, letter);
                
                matrix[i][j]=*(keyword+letter++);
            }
            else{
                // Fill remaining alphabets in the matrix
                fill(matrix, i*5+j);
                i=5; j=5;
            }
        }
    }
    print(matrix);

    printf("\nPlain text: ");
    scanf("%s", plain);
    ij(&plain);
    cipher_gen(&plain, matrix);

    free(keyword);
    free(plain);
    return 0;
}