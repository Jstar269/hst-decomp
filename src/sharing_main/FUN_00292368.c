/* HSTMATCH module=hstp_trans_main.prx start=0x00292368 end=0x002923dc symbol=FUN_00292368 lang=c99 helpers=FUN_002918a8@0x002918a8-0x002918d4 */
/* Hand-written reconstruction from the disassembly (the same source as its EBOOT twin src/eboot/FUN_00280ff0.c with the Sharing addresses: the same-file static log stub FUN_002918a8 is defined in front of it and placed at its own retail address by helpers=; the field store sits in front of the FUN_002c7638 call); exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_003e1e04;
extern char DAT_003a780c[];
extern void FUN_000c0ea0(u32, void (*)(void));
static void FUN_002918a8(...)
{
}
extern void FUN_00291b78(void *, int, int);
extern void FUN_002c7638(void *);
extern void FUN_00291b18(void);

typedef struct Host {
  char pad0[4];
  int value;                 /* 0x04 stored from the second argument */
  char pad8[8];
  char sub[0x2c00 - 0x10];   /* 0x10 sub-object passed to FUN_002c7638 */
  unsigned char busy;        /* 0x2c00 */
} Host;

void FUN_00292368(Host *self, int value)
{
  if (self->busy != 0) {
    FUN_002918a8(DAT_003a780c);
    return;
  }
  FUN_00291b78(self, 3, 0);
  self->value = value;
  FUN_002c7638(self->sub);
  FUN_000c0ea0(DAT_003e1e04, FUN_00291b18);
}
