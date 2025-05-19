#include <stdio.h>
#include <string.h>
#define SIZE 5

char AZ[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char cipher[SIZE];
int key;

int alpha_num(char temp[], int idx){
    for(int i=0; i<26; i++){
        if(temp[idx]==AZ[i])
            return i;
    }
}

void encryption(char plain[]){
    int e[SIZE];
    for(int i=0; i<SIZE; i++)
        e[i]=((alpha_num(plain, i))+key)%26;
    for(int i=0; i<SIZE; i++)
        cipher[i]=AZ[e[i]];
}

void decryption(){
    int d[SIZE];
    char temp[SIZE];
    for(int i=0; i<SIZE; i++)
        d[i]=(alpha_num(cipher, i)+26-key)%26;
    for(int i=0; i<SIZE; i++)
        temp[i]=AZ[d[i]];
    printf("\n\ndecrypting...\nPlain text: %s", temp);
}

int main(){
    char plain[SIZE];
    printf("Plain text: ");
    scanf("%s", plain);
    printf("Key: ");
    scanf("%d", &key);
    encryption(plain);
    printf("\nencrypting...\nCipher text: %s", cipher);
    decryption();
    
    return 0;
}