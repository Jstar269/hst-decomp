/* HSTMATCH module=EBOOT.BIN start=0x001d6ab0 end=0x001d6bb0 symbol=FUN_001d6ab0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the first four copied globals and destination fields as float; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Float bit patterns stored as integers (the object is initialised with word stores). */
#define FBITS_ONE      0x3f800000 /* 1.0f */
#define FBITS_HALF     0x3f000000 /* 0.5f */
#define FBITS_NEG_HALF 0xbf000000 /* -0.5f */
#define FBITS_NEG_ONE  0xbf800000 /* -1.0f */
#define FBITS_0_65     0x3f266666 /* 0.65f */
#define FBITS_240      0x43700000 /* 240.0f */
#define FBITS_136      0x43080000 /* 136.0f */

#define SCRATCH_SIZE 704 /* bytes of the temporary object built on the stack */

/* Object of 0x80 bytes initialised to default values. */
typedef struct VecDefaults {
  float unk00;  /* 0x00 copied from a global */
  float unk04;  /* 0x04 copied from a global */
  float unk08;  /* 0x08 copied from a global */
  float unk0c;  /* 0x0c copied from a global */
  u32 unk10;        /* 0x10 */
  u32 unk14;        /* 0x14 */
  u32 unk18;        /* 0x18 */
  u32 unk1c;        /* 0x1c */
  u32 unk20;        /* 0x20 */
  u32 unk24;        /* 0x24 */
  char pad28[8];
  u32 unk30;        /* 0x30 */
  u32 unk34;        /* 0x34 */
  u32 unk38;        /* 0x38 */
  u32 unk3c;        /* 0x3c */
  u32 unk40;        /* 0x40 */
  u32 unk44;        /* 0x44 */
  u32 unk48;        /* 0x48 */
  u32 unk4c;        /* 0x4c */
  u32 unk50;        /* 0x50 */
  u32 unk54;        /* 0x54 */
  u32 unk58;        /* 0x58 */
  u32 unk5c;        /* 0x5c */
  u32 unk60;        /* 0x60 */
  u32 unk64;        /* 0x64 */
  u32 unk68;        /* 0x68 */
  u32 unk6c;        /* 0x6c */
  u32 unk70;        /* 0x70 */
  u32 unk74;        /* 0x74 */
  u32 unk78;        /* 0x78 */
  u32 unk7c;        /* 0x7c */
} VecDefaults;

extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern u32 DAT_003313c4;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();

/* Fill the object with default values, then build, register and release a temporary object around them. */
VecDefaults * FUN_001d6ab0(VecDefaults *self)
{
  u8 scratch [SCRATCH_SIZE];
  
  self->unk00 = DAT_002bc410;
  self->unk04 = DAT_002bc414;
  self->unk08 = DAT_002bc418;
  self->unk0c = DAT_002bc41c;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = FBITS_ONE;
  self->unk1c = FBITS_ONE;
  self->unk20 = FBITS_240;
  self->unk24 = FBITS_136;
  self->unk30 = FBITS_NEG_HALF;
  self->unk34 = FBITS_HALF;
  self->unk38 = FBITS_NEG_ONE;
  self->unk3c = 0;
  self->unk40 = 0;
  self->unk44 = 0;
  self->unk48 = FBITS_NEG_ONE;
  self->unk4c = 0;
  self->unk50 = FBITS_ONE;
  self->unk54 = FBITS_ONE;
  self->unk58 = FBITS_ONE;
  self->unk5c = 0;
  self->unk60 = 0;
  self->unk64 = 0;
  self->unk68 = 0;
  self->unk6c = 0;
  self->unk70 = FBITS_0_65;
  self->unk74 = FBITS_0_65;
  self->unk78 = FBITS_0_65;
  self->unk7c = FBITS_ONE;
  FUN_0005b670(scratch);
  FUN_0005ba78(DAT_003313c4,scratch);
  FUN_0005ba00(scratch,0xffffffff);
  return self;
}
