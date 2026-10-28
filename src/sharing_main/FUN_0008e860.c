/* HSTMATCH module=hstp_trans_main.prx start=0x0008e860 end=0x0008e894 symbol=FUN_0008e860 lang=c99 */
/* Clone of src/eboot/FUN_0008d114.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000114c0(void *, int, int);

typedef struct Rec1c {
  char pad00[8];
  u32 unk08; /* 0x08, initial 1 */
  char pad0c[0x10];
} Rec1c;

/* Clears a Rec1c and sets its word at 0x08 to 1. */
void FUN_0008e860(Rec1c *rec)
{
  FUN_000114c0(rec, 0, sizeof(Rec1c));
  rec->unk08 = 1;
}
