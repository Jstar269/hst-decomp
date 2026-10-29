/* HSTMATCH module=hstp_trans_main.prx start=0x0011678c end=0x00116848 symbol=FUN_0011678c lang=c99 */
/* Clone of src/eboot/FUN_0010ee50.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037ffe4;
extern u8 DAT_003b0cd4;
extern u8 DAT_003b10c0;
extern int DAT_003ba2c4;
extern void FUN_00042ee8();
extern void FUN_00042fb0();
extern int * FUN_001096ac();

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

Widget * FUN_0011678c(Widget *self)
{
  FUN_001096ac(self,&DAT_0037ffe4);
  self->vtable = (int)(&DAT_003b0cd4);
  self->vtable = (int)(&DAT_003b10c0);
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
  FUN_00042ee8(DAT_003ba2c4);
  FUN_00042fb0(DAT_003ba2c4);
  return self;
}
