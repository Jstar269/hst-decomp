/* Global profile object (the pointer cached in a global at start-up): per-id counters and a few flag bytes. */
#ifndef HST_PROFILE_DATA_H
#define HST_PROFILE_DATA_H

#define PROFILE_COUNT_MAX 0xc9 /* the per-id counters saturate here */
#define PROFILE_FLAG_BITS 5    /* number of bits in flag_bits that are used */

typedef struct ProfileData {
  char pad00[0x10];
  unsigned char counts[0xe0];   /* 0x10 per-id counters, saturating at PROFILE_COUNT_MAX */
  unsigned char flag_bits;      /* 0xf0 one bit per flag index */
  char padf1[0x138 - 0xf1];
  int unk138;                   /* 0x138 */
  unsigned char unk13c;         /* 0x13c */
  unsigned char unk13d;         /* 0x13d */
} ProfileData;

#endif
