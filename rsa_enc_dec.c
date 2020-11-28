#include "./rsa_enc_dec.h"

/**
 * @brief Finds the value of a^b (mod m)
 *
 * @param a
 * @param b
 * @param m
 * @return i16_t
 */
i16_t mod_exp(i16_t a, i16_t b, i16_t m) {

    /* Set the result to 1 */
    i16_t ans = 1;

    /* Bring the value of base withing the modulo range */
    a = a % m;

    /* Stop if the value of base is 0 */
    if (a == 0) {

        return 0;
    }

    while (b > 0) {
        /* If b is even, then update the answer */
        if (b & 1) {
            ans = (ans * a) % m;
        }

        /* Update the exponent */
        b = b >> 1;

        /* Update the multiplier */
        a = (a * a) % m;
    }

    return ans;
}

/**
 * @brief Encrypts the given message using the given public key components
 *
 * @param plaintext
 * @param ciphertext
 * @param len
 * @param e
 * @param n
 */
void rsa_encrypt(
        i8_t  *plaintext,
        i16_t *ciphertext,
        i64_t len,
        i16_t e,
        i16_t n) {

    /* Encrypt the plaintext message block by block */
    for (int i = 0; i < len; i++) {
        ciphertext[i] = mod_exp((i16_t)plaintext[i], e, n);
    }
}

/**
 * @brief Decrypts the given cipher using the given private key components
 *
 * @param plaintext
 * @param ciphertext
 * @param len
 * @param d
 * @param n
 */
void rsa_decrypt(
        i8_t  *plaintext,
        i16_t *ciphertext,
        i64_t len,
        i16_t d,
        i16_t n) {

    /* Decrpyt the ciphertext message block by block */
    for (int i = 0; i < len; i++) {
        plaintext[i] = (i8_t)mod_exp(ciphertext[i], d, n);
    }
}