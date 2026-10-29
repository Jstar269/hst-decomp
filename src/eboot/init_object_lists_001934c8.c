/* HSTMATCH module=EBOOT.BIN start=0x001934c8 end=0x001936f0 symbol=FUN_001934c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_tables.h"

/* Key inserted into a name map: the record's name and its index in the table. */
typedef struct NameKey {
    const char *name;
    unsigned int index;
} NameKey;

/* Any loaded table seen as raw bytes: the records have different sizes (0x9c, 0x6c, 0x70). */
typedef struct TableView {
    unsigned int count;
    char *records;
} TableView;

extern ChallengeIndex *DAT_00341748;
extern TableView *DAT_00341730;
extern TableView *DAT_00341734;
extern TableView *DAT_00341738;
extern TableView *DAT_0034173c;
extern TableView *DAT_00341740;

extern ChallengeIndex *FUN_00000bcc(int);
extern void FUN_00193758(TreeMap *);
extern void FUN_001964f8(void *, TreeMap *, NameKey *);

/* One-time build of the name index: one map per loaded table, each record keyed by its name.
   Returns 1 when the index was built, 0 when it already existed. */
int FUN_001934c8(void)
{
  TableView *pu;
  unsigned int u;
  int i;
  ChallengeIndex *index;
  int ret;
  u8 b1[8];
  NameKey k1;
  u8 b2[8];
  NameKey k2;
  u8 b3[8];
  NameKey k3;
  u8 b4[8];
  NameKey k4;
  u8 b5[8];
  NameKey k5;

  ret = 0;
  if (DAT_00341748 == 0) {
    if ((index = FUN_00000bcc(sizeof(ChallengeIndex))) != 0) {
      FUN_00193758(&index->stamp);
      FUN_00193758(&index->match);
      FUN_00193758(&index->exhibition);
      FUN_00193758(&index->unk30);
      FUN_00193758(&index->vspc);
    }
    DAT_00341748 = index;
    pu = DAT_00341730;
    u = 0;
    if (pu->count != 0) {
      i = 0;
      do {
        k1.name = pu->records + i + CHALLENGE_REC_BIG_NAME;
        k1.index = u;
        FUN_001964f8(b1, &DAT_00341748->unk30, &k1);
        u = u + 1;
        i = i + 0x9c;
      } while (u < pu->count);
    }
    pu = DAT_00341734;
    u = 0;
    if (pu->count != 0) {
      i = 0;
      do {
        k2.name = pu->records + i;
        k2.index = u;
        FUN_001964f8(b2, &DAT_00341748->match, &k2);
        u = u + 1;
        i = i + 0x6c;
      } while (u < pu->count);
    }
    pu = DAT_00341738;
    u = 0;
    if (pu->count != 0) {
      i = 0;
      do {
        k3.name = pu->records + i;
        k3.index = u;
        FUN_001964f8(b3, &DAT_00341748->stamp, &k3);
        u = u + 1;
        i = i + 0x70;
      } while (u < pu->count);
    }
    pu = DAT_0034173c;
    u = 0;
    if (pu->count != 0) {
      i = 0;
      do {
        k4.name = pu->records + i + CHALLENGE_REC_BIG_NAME;
        k4.index = u;
        FUN_001964f8(b4, &DAT_00341748->vspc, &k4);
        u = u + 1;
        i = i + 0x9c;
      } while (u < pu->count);
    }
    pu = DAT_00341740;
    u = 0;
    if (pu->count != 0) {
      i = 0;
      do {
        k5.name = pu->records + i;
        k5.index = u;
        FUN_001964f8(b5, &DAT_00341748->exhibition, &k5);
        u = u + 1;
        i = i + 0x6c;
      } while (u < pu->count);
    }
    ret = 1;
  }
  return ret;
}
