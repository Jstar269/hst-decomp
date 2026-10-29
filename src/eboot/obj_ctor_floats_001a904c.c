/* HSTMATCH module=EBOOT.BIN start=0x001a904c end=0x001a90f8 symbol=FUN_001a904c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the four copied globals and the destination fields are float (lwc1/swc1); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Size of the local buffer passed to FUN_0005b670 and FUN_0005ba00. */
#define SCRATCH_SIZE 704

extern float DAT_002c2f70;
extern float DAT_002c2f74;
extern float DAT_002c2f78;
extern float DAT_002c2f7c;
extern u8 DAT_003092a8;

/* Global object: four words at 0x1e0 are set below (0xbf800000 is the bit pattern of -1.0f). */
typedef struct GlobalObj {
  char pad00[0x1e0];
  u32 unk1e0;  /* 0x1e0 */
  u32 unk1e4;  /* 0x1e4 */
  u32 unk1e8;  /* 0x1e8 */
  u32 unk1ec;  /* 0x1ec */
} GlobalObj;

extern GlobalObj * DAT_003313c4;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();
extern void FUN_0005bc58();

typedef struct O { unsigned int vt; int pad[3]; float a, b, c, d; } O;

O * FUN_001a904c(O *self)
{
  GlobalObj *global;
  u8 scratch [SCRATCH_SIZE];
  
  self->vt = (unsigned int)(&DAT_003092a8);
  self->a = DAT_002c2f70;
  self->b = DAT_002c2f74;
  self->c = DAT_002c2f78;
  self->d = DAT_002c2f7c;
  FUN_0005b670(scratch);
  FUN_0005ba78(DAT_003313c4,scratch);
  global = DAT_003313c4;
  DAT_003313c4->unk1e0 = 0;
  global->unk1e4 = 0;
  global->unk1e8 = 0xbf800000;
  global->unk1ec = 0;
  FUN_0005bc58(DAT_003313c4);
  FUN_0005ba00(scratch,0xffffffff);
  return self;
}
