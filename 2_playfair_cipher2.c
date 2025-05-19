#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define ALPHABET "ABCDEFGHIKLMNOPQRSTUVWXYZ" // No 'J' in the Playfair matrix

// Function to create the Playfair matrix based on the given key
void createPlayfairMatrix(char key[], char matrix[][SIZE]) {
    int i, j, k, len;
    char temp[26] = {0};
    len = strlen(key);

    // Convert the key to uppercase
    for (i = 0; i < len; i++) {
        key[i] = toupper(key[i]);
    }

    // Remove duplicate characters from the key
    for (i = 0, k = 0; i < len; i++) {
        if (temp[key[i] - 'A'] == 0) {
            temp[key[i] - 'A'] = 1;
            matrix[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }

    // Fill the rest of the matrix with remaining characters from the alphabet
    for (i = 0, j = k; i < 26; i++) {
        if (temp[ALPHABET[i] - 'A'] == 0) {
            matrix[j / SIZE][j % SIZE] = ALPHABET[i];
            j++;
        }
    }
}

// Function to find the coordinates of a character in the Playfair matrix
void findPosition(char matrix[][SIZE], char ch, int *row, int *col) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt the plaintext using the Playfair cipher
void playfairEncrypt(char matrix[][SIZE], char plaintext[], char ciphertext[]) {
    int len = strlen(plaintext);
    int i, row1, col1, row2, col2;
    char ch1, ch2;

    for (i = 0; i < len; i += 2) {
        ch1 = plaintext[i];
        ch2 = plaintext[i + 1];

        findPosition(matrix, ch1, &row1, &col1);
        findPosition(matrix, ch2, &row2, &col2);

        // Same row, shift columns
        if (row1 == row2) {
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        }
        // Same column, shift rows
        else if (col1 == col2) {
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        }
        // Forming a rectangle, swap
        else {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }
}

int main() {
    char key[100];
    char matrix[SIZE][SIZE];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext (only uppercase alphabets, no spaces): ");
    scanf("%s", plaintext);

    createPlayfairMatrix(key, matrix);

    playfairEncrypt(matrix, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

