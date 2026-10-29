/* HSTMATCH module=EBOOT.BIN start=0x001a9e34 end=0x001a9f74 symbol=FUN_001a9e34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: Ghidra's goto structure rewritten as nested if/else (A != 0 && B == 0 outer, C == 0 && D != 0 inner, three call-pair copies), byte flags unsigned char; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

/* Singleton returned by FUN_0019d474: only the flag bytes this function reads. */
typedef struct ModeFlags {
  char pad00[0x4d];
  u8 unk4d;   /* 0x4d */
  char pad4e[0x2a4 - 0x4e];
  u8 unk2a4;  /* 0x2a4 */
  char pad2a5[0x2b8 - 0x2a5];
  u8 unk2b8;  /* 0x2b8 */
} ModeFlags;

/* Screen object: the handles this function touches; each slot is a word. */
typedef struct ModeScreen {
  u32 unk00;                 /* 0x00 */
  char pad04[0x5c - 4];
  u32 unk5c;                 /* 0x5c passed to FUN_000ffb3c with 1 or 0 */
  char pad60[0x70 - 0x60];
  u32 unk70;                 /* 0x70 passed to FUN_000ffb3c with the same flag as unk5c */
  char pad74[0x3fc - 0x74];
  u32 unk3fc;                /* 0x3fc */
} ModeScreen;

extern AdhocNet *DAT_00338ac4;
extern void FUN_000ffb3c();
extern void FUN_00103628();
extern void FUN_0010b6d4();
extern ModeFlags *FUN_0019d474();
extern void FUN_001a9f74();
extern void FUN_001aa1cc();
extern void FUN_001aa208();
extern void FUN_001aa244();
extern void FUN_001aa2a4();
extern void FUN_001aa450();
extern void FUN_001aa558();
extern void FUN_001aa770();

/* Sets two handles to 1 or 0 from the mode flags, then runs the sub-updaters. */
void FUN_001a9e34(ModeScreen *self)
{
  u32 *first;
  u32 *second;
  
  FUN_0019d474();
  FUN_0010b6d4(self->unk3fc,0,2);
  FUN_00103628(self->unk00,0);
  first = &self->unk5c;
  second = &self->unk70;
  if (FUN_0019d474()->unk2a4 != 0 && FUN_0019d474()->unk4d == 0) {
    if (DAT_00338ac4->unk178 == 0 && FUN_0019d474()->unk2b8 != 0) {
      FUN_000ffb3c(*first,1);
      FUN_000ffb3c(*second,1);
    }
    else {
      FUN_000ffb3c(*first,0);
      FUN_000ffb3c(*second,0);
    }
  }
  else {
    FUN_000ffb3c(*first,1);
    FUN_000ffb3c(*second,1);
  }
  FUN_001a9f74(self);
  FUN_001aa1cc(self);
  FUN_001aa208(self);
  FUN_001aa558(self);
  FUN_001aa244(self);
  FUN_001aa2a4(self);
  FUN_001aa450(self);
  FUN_001aa770(self);
}
