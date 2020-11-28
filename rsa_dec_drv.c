#include <stdlib.h>
#include <stdio.h>
#include "./rsa_enc_dec.h"

/* Maximum message size */
#define MAX_MSG_SZ (2048u)

/**
 * @brief Driver program to decrypt the ciphertext message given through standard
 *        input and print the ciphertext on the standard output
 *
 */
void main(int argc, char *argv[]) {

    i16_t d;
    i16_t n;
    i8_t plaintext[MAX_MSG_SZ];
    i16_t ciphertext[MAX_MSG_SZ];
    i8_t *p_cipher = (i8_t *)ciphertext;
    i64_t msg_sz = 0;

    /* Check for valid number of arguments */
    if (argc < 3) {
        fprintf(stderr, "Enter the private key components (d and n)\n");
        return;
    }

    /* Get the values of keys */
    d = atoi(argv[1]);
    n = atoi(argv[2]);

    /* Get the ciphertext message */
    while (scanf("%c", &p_cipher[msg_sz]) != -1) {
        msg_sz++;
    }

    /* Update the message size */
    msg_sz = msg_sz / 2;

    /* Decrypt the message */
    rsa_decrypt(plaintext, ciphertext, msg_sz, d, n);

    /* Print the plaintext */
    for (int i = 0; i < msg_sz; i++) {
        printf("%c", plaintext[i]);
    }
}