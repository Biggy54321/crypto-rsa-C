#ifndef RSA_ENC_DEC_H
#define RSA_ENC_DEC_H

#include "./rsa_types.h"

void rsa_encrypt(
        i8_t  *plaintext,
        i16_t *ciphertext,
        i64_t len,
        i16_t e,
        i16_t n);

void rsa_decrypt(
        i8_t  *plaintext,
        i16_t *ciphertext,
        i64_t len,
        i16_t d,
        i16_t n);

#endif