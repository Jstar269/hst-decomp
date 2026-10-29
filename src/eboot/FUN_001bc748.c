/* HSTMATCH module=EBOOT.BIN start=0x001bc748 end=0x001bc7e0 symbol=FUN_001bc748 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branches; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Initial values: a high sentinel and a low one (their use is not visible here). */
#define INIT_HIGH 9999
#define INIT_LOW 0xf0000000

#define RECORD_WORDS 40

typedef struct WordRecord {
  u32 w[RECORD_WORDS];  /* 0x00 */
} WordRecord;           /* size 0xa0 */

extern u32 * FUN_000114c0();

/* Fills the record with its initial pattern when init is nonzero, otherwise clears it. */
void FUN_001bc748(WordRecord *rec, int init)
{
  if (init != 0) {
    rec->w[0] = INIT_HIGH;
    rec->w[1] = INIT_HIGH;
    rec->w[2] = INIT_LOW;
    rec->w[3] = INIT_LOW;
    rec->w[4] = INIT_LOW;
    rec->w[5] = INIT_LOW;
    rec->w[6] = INIT_LOW;
    rec->w[7] = INIT_LOW;
    rec->w[8] = INIT_LOW;
    rec->w[9] = INIT_LOW;
    rec->w[10] = INIT_LOW;
    rec->w[0x18] = INIT_LOW;
    rec->w[0x19] = INIT_LOW;
    rec->w[0xb] = INIT_LOW;
    rec->w[0xc] = INIT_LOW;
    rec->w[0xd] = 0;
    rec->w[0xe] = 0;
    rec->w[0xf] = 0;
    rec->w[0x10] = 0;
    rec->w[0x11] = INIT_LOW;
    rec->w[0x12] = INIT_LOW;
    rec->w[0x13] = INIT_HIGH;
    rec->w[0x14] = INIT_HIGH;
    rec->w[0x15] = INIT_HIGH;
    rec->w[0x16] = INIT_HIGH;
    rec->w[0x17] = INIT_HIGH;
  }
  else {
    FUN_000114c0(rec, 0, sizeof(WordRecord));
  }
}
