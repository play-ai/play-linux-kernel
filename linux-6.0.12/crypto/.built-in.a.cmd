cmd_crypto/built-in.a := rm -f crypto/built-in.a;  printf "crypto/%s " api.o cipher.o compress.o algapi.o scatterwalk.o proc.o aead.o geniv.o skcipher.o seqiv.o echainiv.o ahash.o shash.o akcipher.o kpp.o rsapubkey.asn1.o rsaprivkey.asn1.o rsa.o rsa_helper.o rsa-pkcs1pad.o acompress.o scompress.o algboss.o testmgr.o cmac.o hmac.o crypto_null.o md5.o sha256_generic.o sha512_generic.o gf128mul.o cbc.o ctr.o gcm.o ccm.o aes_generic.o crc32c_generic.o authenc.o authencesn.o rng.o drbg.o jitterentropy.o jitterentropy-kcapi.o ghash-generic.o asymmetric_keys/built-in.a hash_info.o | xargs ar cDPrST crypto/built-in.a