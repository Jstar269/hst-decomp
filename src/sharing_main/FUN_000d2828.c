/* HSTMATCH module=hstp_trans_main.prx start=0x000d2828 end=0x000d2854 symbol=FUN_000d2828 lang=c99 */
/* Clone of src/eboot/FUN_000cec2c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005ffd8();

typedef struct SubHolder {
  char pad00[0x3c];
  u8 active;          /* 0x3c */
  char pad3d[3];
  char sub[4];        /* 0x40 embedded sub-object */
} SubHolder;

/* Passes the embedded sub-object on when the active flag is set. */
void FUN_000d2828(SubHolder *holder)
{
  if (holder->active != '\0') {
    FUN_0005ffd8(holder->sub,0);
  }
}
