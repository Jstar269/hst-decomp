/* Character parameter table: 556-byte records looked up by name. */
#ifndef HST_CHAR_PARAM_H
#define HST_CHAR_PARAM_H

#define CHAR_PARAM_NAME_LEN 554 /* bytes of name text at the start of the record body */

typedef struct CharParam {
  char pad0[2];
  char name[CHAR_PARAM_NAME_LEN]; /* 0x02 name the record is looked up by */
} CharParam;                      /* size 0x22c */

typedef struct CharParamTable {
  CharParam *entries; /* 0x00 */
  unsigned count;     /* 0x04 number of records */
} CharParamTable;

#endif
