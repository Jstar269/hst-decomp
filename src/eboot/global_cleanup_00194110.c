/* HSTMATCH module=EBOOT.BIN start=0x00194110 end=0x00194348 symbol=FUN_00194110 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the delete calls (0xa00) take the tested global as argument (Ghidra dropped it); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_tables.h"

/* Bytes in front of a new[] block (element count cookie). */
#define ARRAY_COOKIE_SIZE 0x10

/* Table of 0x70-byte records: a count, then the array. */
typedef struct StampTableView {
  int count;     /* 0x00 */
  void *records; /* 0x04 */
} StampTableView;

extern ChallengeTableBig * DAT_00341730;
extern ChallengeTableSmall * DAT_00341734;
extern StampTableView * DAT_00341738;
extern ChallengeTableBig * DAT_0034173c;
extern ChallengeTableSmall * DAT_00341740;
extern ChallengeIndex * DAT_00341748;
extern void FUN_000009e4();
extern void FUN_00000a00(void *);
extern int FUN_001936f0();

/* Free the five loaded challenge tables and the name index built over them. */
void FUN_00194110(void)
{
  char *records;
  ChallengeIndex *index;
  
  if (DAT_00341730 != 0) {
    records = (char *)DAT_00341730->records;
    if (records != 0) {
      if (records != 0) {
        FUN_000009e4(records - ARRAY_COOKIE_SIZE);
      }
      DAT_00341730->records = 0;
    }
    if (DAT_00341730 != 0) {
      FUN_00000a00(DAT_00341730);
      DAT_00341730 = 0;
    }
  }
  if (DAT_0034173c != 0) {
    records = (char *)DAT_0034173c->records;
    if (records != 0) {
      if (records != 0) {
        FUN_000009e4(records - ARRAY_COOKIE_SIZE);
      }
      DAT_0034173c->records = 0;
    }
    if (DAT_0034173c != 0) {
      FUN_00000a00(DAT_0034173c);
      DAT_0034173c = 0;
    }
  }
  if (DAT_00341734 != 0) {
    records = (char *)DAT_00341734->records;
    if (records != 0) {
      if (records != 0) {
        FUN_000009e4(records - ARRAY_COOKIE_SIZE);
      }
      DAT_00341734->records = 0;
    }
    if (DAT_00341734 != 0) {
      FUN_00000a00(DAT_00341734);
      DAT_00341734 = 0;
    }
  }
  if (DAT_00341738 != 0) {
    records = (char *)DAT_00341738->records;
    if (records != 0) {
      if (records != 0) {
        FUN_000009e4(records - ARRAY_COOKIE_SIZE);
      }
      DAT_00341738->records = 0;
    }
    if (DAT_00341738 != 0) {
      FUN_00000a00(DAT_00341738);
      DAT_00341738 = 0;
    }
  }
  if (DAT_00341740 != 0) {
    records = (char *)DAT_00341740->records;
    if (records != 0) {
      if (records != 0) {
        FUN_000009e4(records - ARRAY_COOKIE_SIZE);
      }
      DAT_00341740->records = 0;
    }
    if (DAT_00341740 != 0) {
      FUN_00000a00(DAT_00341740);
      DAT_00341740 = 0;
    }
  }
  index = DAT_00341748;
  if (DAT_00341748 != 0) {
    if (DAT_00341748 != 0) {
      FUN_001936f0(&DAT_00341748->vspc,0xffffffff);
      FUN_001936f0(&index->unk30,0xffffffff);
      FUN_001936f0(&index->exhibition,0xffffffff);
      FUN_001936f0(&index->match,0xffffffff);
      FUN_001936f0(&index->stamp,0xffffffff);
      FUN_00000a00(index);
    }
    DAT_00341748 = 0;
  }
}
