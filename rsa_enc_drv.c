#include <stdlib.h>
#include <stdio.h>
#include "./rsa_enc_dec.h"

/* Maximum message size */
#define MAX_MSG_SZ (2048u)

/**
 * @brief Driver program to encrypt the plaintext message given through standard
 *        input and print the ciphertext on the standard output
 *
 */
void main(int argc, char *argv[]) {

    i16_t e;
    i16_t n;
    i8_t plaintext[MAX_MSG_SZ];
    i16_t ciphertext[MAX_MSG_SZ];
    i8_t *p_cipher = (i8_t *)ciphertext;
    i64_t msg_sz = 0;

    /* Check for valid number of arguments */
    if (argc < 3) {
        fprintf(stderr, "Enter the public key components (e and n)\n");
        return;
    }

    /* Get the values of keys */
    e = atoi(argv[1]);
    n = atoi(argv[2]);

    /* Get the plaintext message */
    while (scanf("%c", &plaintext[msg_sz]) != -1) {
        msg_sz++;
    }

    /* Encrypt the message */
    rsa_encrypt(plaintext, ciphertext, msg_sz, e, n);

    /* Print the ciphertext */
    for (int i = 0; i < 2 * msg_sz; i++) {
        printf("%c", p_cipher[i]);
    }
}