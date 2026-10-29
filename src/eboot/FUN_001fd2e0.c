/* HSTMATCH module=EBOOT.BIN start=0x001fd2e0 end=0x001fd46c symbol=FUN_001fd2e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* A table reader: vtable pointer followed by two members torn down by FUN_00066338. */
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

extern u8 DAT_003070bc;   /* vtable of TableReader */
extern u8 DAT_003095b0;   /* vtable of RegulationScreen */
extern u32 DAT_0034a13c;  /* the live regulation screen, cleared on destruction */
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int * FUN_00064a08();
extern int FUN_00066338();
extern int FUN_001ffcc0();
extern int FUN_00201a44();
extern void FUN_00204394();
extern void FUN_0005ba00();

/* Deleting destructor: tears down the readers and sub-objects, then frees when flags > 0. */
RegulationScreen * FUN_001fd2e0(RegulationScreen *self,short flags)
{
  u32 *member;
  
  if (self != (RegulationScreen *)0x0) {
    self->vtable = (unsigned int)(&DAT_003095b0);
    FUN_00204394();
    DAT_0034a13c = 0;
    if (&self->readerTall != (TableReader *)0x0) {
      member = self->readerTall.memberB;
      self->readerTall.vtable = (unsigned int)(&DAT_003070bc);
      if ((((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
          (member != (u32 *)0x0)) && (member != (u32 *)0x0)) {
        FUN_00066338((int)member,0);
      }
      member = self->readerTall.memberA;
      if (((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
         ((member != (u32 *)0x0 && (member != (u32 *)0x0)))) {
        FUN_00066338((int)member,0);
      }
      FUN_00064a08(&self->readerTall,0);
    }
    if (&self->readerParams != (TableReader *)0x0) {
      member = self->readerParams.memberB;
      self->readerParams.vtable = (unsigned int)(&DAT_003070bc);
      if (((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
         ((member != (u32 *)0x0 && (member != (u32 *)0x0)))) {
        FUN_00066338((int)member,0);
      }
      member = self->readerParams.memberA;
      if ((((member != (u32 *)0x0) && (member != (u32 *)0x0)) &&
          (member != (u32 *)0x0)) && (member != (u32 *)0x0)) {
        FUN_00066338((int)member,0);
      }
      FUN_00064a08(&self->readerParams,0);
    }
    FUN_00201a44((int)self->sub1250,-1);
    FUN_00000788((int)self->lights,FUN_0005ba00,0x2c0,2);
    FUN_001ffcc0((int)self->sub0c8,-1);
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
