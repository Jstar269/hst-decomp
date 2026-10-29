/* HSTMATCH module=hstp_trans_main.prx start=0x0020bab0 end=0x0020bc3c symbol=FUN_0020bab0 lang=c99 */
/* Clone of src/eboot/FUN_001fd2e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* A table reader: vtable pointer followed by two members torn down by FUN_0006778c. */
typedef struct TableReader {
  u32 vtable;       /* 0x00 */
  char pad04[0xc];
  u32 memberA[4];   /* 0x10 */
  u32 memberB[4];   /* 0x20 */
} TableReader;

typedef struct RegulationScreen {
  u32 vtable;             /* 0x0 */
  char pad04[0xc4];   /* 0x4 */
  char sub0c8[0xcd0 - 0xc8];   /* 0xc8 */
  char lights[0x580];     /* 0xcd0, two 0x2c0-byte records */
  char sub1250[0x44];     /* 0x1250 */
  TableReader readerParams; /* 0x1294 */
  TableReader readerTall;   /* 0x12c4 */
} RegulationScreen;

extern u8 DAT_003b0388;   /* vtable of TableReader */
extern u8 DAT_003b287c;   /* vtable of RegulationScreen */
extern u32 DAT_003f3474;  /* the live regulation screen, cleared on destruction */
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000658cc();
extern int FUN_0006778c();
extern int FUN_0020e490();
extern int FUN_00210214();
extern void FUN_00212bfc();
extern void FUN_0005c688();

/* Deleting destructor: tears down the readers and sub-objects, then frees when flags > 0. */
RegulationScreen * FUN_0020bab0(RegulationScreen *self,short flags)
{
  u32 *member;
  
  if (self != (RegulationScreen *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b287c);
    FUN_00212bfc();
    DAT_003f3474 = 0;
    if (&self->readerTall != (TableReader *)0x0) {
      member = self->readerTall.memberB;
      self->readerTall.vtable = (unsigned int)(&DAT_003b0388);
      if ((((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
          (member != (u32 *)0x0)) && (member != (u32 *)0x0)) {
        FUN_0006778c((int)member,0);
      }
      member = self->readerTall.memberA;
      if (((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
         ((member != (u32 *)0x0 && (member != (u32 *)0x0)))) {
        FUN_0006778c((int)member,0);
      }
      FUN_000658cc(&self->readerTall,0);
    }
    if (&self->readerParams != (TableReader *)0x0) {
      member = self->readerParams.memberB;
      self->readerParams.vtable = (unsigned int)(&DAT_003b0388);
      if (((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
         ((member != (u32 *)0x0 && (member != (u32 *)0x0)))) {
        FUN_0006778c((int)member,0);
      }
      member = self->readerParams.memberA;
      if ((((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
          (member != (u32 *)0x0)) && (member != (u32 *)0x0)) {
        FUN_0006778c((int)member,0);
      }
      FUN_000658cc(&self->readerParams,0);
    }
    FUN_00210214((int)self->sub1250,-1);
    FUN_00000788((int)self->lights,FUN_0005c688,0x2c0,2);
    FUN_0020e490((int)self->sub0c8,-1);
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
