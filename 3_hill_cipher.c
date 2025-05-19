// Hill cipher Demonstration works for capital plain text;
 #include <stdio.h>
#include <string.h>

#define MOD 26

// Function to encrypt a 2x2 matrix using the Hill cipher key
void encrypt(int key[][2], int plaintext[], int ciphertext[]) {
    ciphertext[0] = (key[0][0] * plaintext[0] + key[0][1] * plaintext[1]) % MOD;
    ciphertext[1] = (key[1][0] * plaintext[0] + key[1][1] * plaintext[1]) % MOD;
}

// Function to calculate the modular inverse of a number
int modInverse(int num) {
    int inverse = 1;
    while ((num * inverse) % MOD != 1) {
        inverse++;
    }
    return inverse;
}

// Function to decrypt a 2x2 matrix using the Hill cipher ke y
void decrypt(int key[][2], int ciphertext[], int plaintext[]) {
    int determinant = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    if (determinant < 0) {
        determinant += MOD;
    }

    int inverse = modInverse(determinant);

    plaintext[0] = (inverse * (key[1][1] * ciphertext[0] - key[0][1] * ciphertext[1])) % MOD;
    plaintext[1] = (inverse * (-key[1][0] * ciphertext[0] + key[0][0] * ciphertext[1])) % MOD;

    // Ensure the plaintext values are positive
    if (plaintext[0] < 0) {
        plaintext[0] += MOD;
    }
    if (plaintext[1] < 0) {
        plaintext[1] += MOD;
    }
}

int main() {
    int key[2][2] = {{6, 9}, {7, 5}}; // Example key matrix
    char plaintext[100];

    printf("Enter the plaintext (only uppercase alphabets, no spaces):\n");
    scanf("%s", plaintext);

    int length = strlen(plaintext);
    int cipher_length = length % 2 == 0 ? length : length + 1;
    int ciphertext[cipher_length];
    int plaintext_matrix[2];
    int i;

    for ( i = 0; i < length; i += 2) {
        plaintext_matrix[0] = plaintext[i] - 'A';
        plaintext_matrix[1] = plaintext[i + 1] ? plaintext[i + 1] - 'A' : 0;

        encrypt(key, plaintext_matrix, &ciphertext[i]);
    }

    printf("Ciphertext: ");
    for (i = 0; i < cipher_length; i++) {
        printf("%c", ciphertext[i] + 'A');
    }
    printf("\n");

    int decrypted_length = cipher_length;
    int decrypted_text[decrypted_length];

    for (i = 0; i < cipher_length; i += 2) {
        decrypt(key, &ciphertext[i], &decrypted_text[i]);
    }

    printf("Decrypted text: ");
    for (i = 0; i < decrypted_length; i++) {
        printf("%c", decrypted_text[i] + 'A');
    }
    printf("\n");

    return 0;
}

