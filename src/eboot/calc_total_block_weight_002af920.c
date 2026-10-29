/* HSTMATCH module=EBOOT.BIN start=0x002af920 end=0x002afa48 symbol=FUN_002af920 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared pointer before loop index, unsigned comparison, local obj copy for delay slot move; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define BLOCK_COUNT 640   /* state bytes per block kind */
#define BLOCK_KINDS 3

/* Per-block state bytes for the three block kinds (kind 1 first). */
typedef struct BlockSet {
  char pad000[0x84c];
  u8 state[BLOCK_KINDS][BLOCK_COUNT];  /* 0x84c */
} BlockSet;

extern int DAT_00338b08;
extern int DAT_003415a8;
extern int FUN_000d8c24(int, int, int);

/* Sum the weight of every block whose state is 4 or 5, over the three kinds; uses the global set when source is 0. */
int FUN_002af920(int source)
{
  int sum = 0;
  BlockSet *set = (BlockSet *)source;
  u8 *p;
  int i;
  int rec;
  
  if (source == 0) {
    set = (BlockSet *)(DAT_003415a8 + 0x80);
  }
  p = set->state[0];
  i = 0;
  do {
    if ((u32)(*p - 4) < 2) {
      rec = FUN_000d8c24(DAT_00338b08, 1, i);
      sum = sum + *(short *)(rec + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < BLOCK_COUNT);
  p = set->state[1];
  i = 0;
  do {
    if ((u32)(*p - 4) < 2) {
      rec = FUN_000d8c24(DAT_00338b08, 2, i);
      sum = sum + *(short *)(rec + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < BLOCK_COUNT);
  p = set->state[2];
  i = 0;
  do {
    if ((u32)(*p - 4) < 2) {
      rec = FUN_000d8c24(DAT_00338b08, 3, i);
      sum = sum + *(short *)(rec + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < BLOCK_COUNT);
  return sum;
}
