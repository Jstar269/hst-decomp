/* HSTMATCH module=EBOOT.BIN start=0x0010ee50 end=0x0010ef0c symbol=FUN_0010ee50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d9210;
extern u8 DAT_00307a08;
extern u8 DAT_00307df4;
extern int DAT_00310fc4;
extern void FUN_00042e04();
extern void FUN_00042ecc();
extern int * FUN_00103d80();

typedef struct Widget {
  int vtable;          /* 0x000 */
  char pad004[0xd0 - 4];
  int unkd0;           /* 0x0d0 */
  int unkd4;           /* 0x0d4 */
  short unkd8;         /* 0x0d8 */
  char padda[2];
  int unkdc;           /* 0x0dc bit pattern of 1.0f */
  int unke0;           /* 0x0e0 bit pattern of 1.0f */
  int unke4;           /* 0x0e4 */
  int unke8;           /* 0x0e8 */
  signed char unkec;   /* 0x0ec */
  char padED;
  short unkee;         /* 0x0ee */
  short unkf0;         /* 0x0f0 */
  short unkf2;         /* 0x0f2 */
  short unkf4;         /* 0x0f4 */
  char padf6[2];
  int unkf8;           /* 0x0f8 */
  char padfc[0x8fc - 0xfc];
  short unk8fc;        /* 0x8fc */
  char pad8fe[2];
  int unk900;          /* 0x900 */
  int unk904;          /* 0x904 */
  short unk908;        /* 0x908 */
  signed char unk90a;  /* 0x90a */
} Widget;

Widget * FUN_0010ee50(Widget *self)
{
  FUN_00103d80(self,&DAT_002d9210);
  self->vtable = (int)(&DAT_00307a08);
  self->vtable = (int)(&DAT_00307df4);
  self->unkd0 = 0;
  self->unkd4 = 0;
  self->unkd8 = 0;
  self->unkdc = 0x3f800000;
  self->unke0 = 0x3f800000;
  self->unke4 = 0;
  self->unke8 = 0;
  self->unkec = 0;
  self->unkee = 0;
  self->unkf0 = 0;
  self->unkf2 = 0xffe0;
  self->unkf4 = 0x10;
  self->unkf8 = 0;
  self->unk8fc = 0;
  self->unk900 = 0;
  self->unk904 = 0;
  self->unk908 = 0xffff;
  self->unk90a = 1;
  FUN_00042e04(DAT_00310fc4);
  FUN_00042ecc(DAT_00310fc4);
  return self;
}
