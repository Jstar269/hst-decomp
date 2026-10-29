/* Challenge data tables (loaded record arrays) and the name index built over them. */
#ifndef HST_CHALLENGE_TABLES_H
#define HST_CHALLENGE_TABLES_H

#include "hst/types.h"
#include "hst/tree_map.h"

/* Record sizes of the loaded tables. */
#define CHALLENGE_REC_BIG_SIZE 0x9c   /* 156 bytes: the name sits at offset 0x0f */
#define CHALLENGE_REC_SMALL_SIZE 0x6c /* 108 bytes: the name sits at offset 0 */
#define CHALLENGE_REC_BIG_NAME 0x0f

/* How an entry refers to another record: not at all, by name in table A (the one indexed by unk30), by name in the VsPc list. */
enum {
  CHALLENGE_REF_NONE = 0,
  CHALLENGE_REF_TABLE_A = 1,
  CHALLENGE_REF_VSPC = 2
};

typedef struct ChallengeRecBig {
  char raw[CHALLENGE_REC_BIG_SIZE];
} ChallengeRecBig;

typedef struct ChallengeRecSmall {
  char raw[CHALLENGE_REC_SMALL_SIZE];
} ChallengeRecSmall;

/* Table of 156-byte records: a count, then the array. */
typedef struct ChallengeTableBig {
  int count;                  /* 0x00 */
  ChallengeRecBig *records;   /* 0x04 */
} ChallengeTableBig;

/* Table of 108-byte records. */
typedef struct ChallengeTableSmall {
  int count;                  /* 0x00 */
  ChallengeRecSmall *records; /* 0x04 */
} ChallengeTableSmall;

/* One name -> record-index map per table; a node's value is the index into the table's records. */
typedef struct ChallengeIndex {
  TreeMap stamp;       /* 0x00 */
  TreeMap match;       /* 0x10 */
  TreeMap exhibition;  /* 0x20 */
  TreeMap unk30;       /* 0x30 */
  TreeMap vspc;        /* 0x40 */
} ChallengeIndex;      /* size 0x50 */

#endif
