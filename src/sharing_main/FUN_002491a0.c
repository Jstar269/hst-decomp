/* HSTMATCH module=hstp_trans_main.prx start=0x002491a0 end=0x00249474 symbol=FUN_002491a0 lang=c99 */
/* Clone of src/eboot/FUN_00239008.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0388;
extern u8 DAT_003b2b7c;
extern u8 DAT_003eaad8;
extern u32 DAT_003f39ec;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000550a0();
extern int * FUN_000658cc();
extern int FUN_0006778c();
extern void FUN_001c170c();
extern int * FUN_0024b314();
extern u32 * FUN_0024c0ec();

/* A string-pair block: a base object (vtable first) followed by two string objects. */
typedef struct TextBlock {
  u32 vtable;         /* 0x00 */
  char pad04[0xc];
  u32 first[4];       /* 0x10 */
  u32 second[4];      /* 0x20 */
} TextBlock;          /* size 0x30 */

typedef struct ScreenObj {
  u32 vtable;                          /* 0x0000 */
  char pad0004[0x50 - 4];
  u32 unk50[4];                        /* 0x0050 destroyed with the -1 variant */
  char pad0060[0x1818 - 0x60];
  u32 member1818[5];                   /* 0x1818 */
  u32 member182c[3];                   /* 0x182c */
  u32 member1838[3];                   /* 0x1838 */
  u32 member1844[5];                   /* 0x1844 */
  TextBlock block1858;                 /* 0x1858 */
  TextBlock block1888;                 /* 0x1888 */
  char pad18b8[0x18d4 - 0x18b8];
  TextBlock block18d4;                 /* 0x18d4 */
  TextBlock block1904;                 /* 0x1904 */
} ScreenObj;

/* Deleting destructor of the screen: restores its vtable, runs a global cleanup call, destroys the four text
   blocks and the other members, then the base, and frees when flag > 0. */
ScreenObj * FUN_002491a0(ScreenObj *self,short flag)
{
  u32 *text;
  int *member;
  
  if (self != (ScreenObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b2b7c);
    FUN_001c170c((int *)&DAT_003eaad8,6);
    DAT_003f39ec = 0;
    if ((char *)&self->block1904 != (char *)0) {
      text = self->block1904.second;
      self->block1904.vtable = (unsigned int)(&DAT_003b0388);
      if ((((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
          (text != (u32 *)0x0)) && (text != (u32 *)0x0)) {
        FUN_0006778c((int)text,0);
      }
      text = self->block1904.first;
      if (((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
         ((text != (u32 *)0x0 && (text != (u32 *)0x0)))) {
        FUN_0006778c((int)text,0);
      }
      FUN_000658cc(&self->block1904,0);
    }
    if ((char *)&self->block18d4 != (char *)0) {
      text = self->block18d4.second;
      self->block18d4.vtable = (unsigned int)(&DAT_003b0388);
      if (((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
         ((text != (u32 *)0x0 && (text != (u32 *)0x0)))) {
        FUN_0006778c((int)text,0);
      }
      text = self->block18d4.first;
      if ((((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
          (text != (u32 *)0x0)) && (text != (u32 *)0x0)) {
        FUN_0006778c((int)text,0);
      }
      FUN_000658cc(&self->block18d4,0);
    }
    if ((char *)&self->block1888 != (char *)0) {
      text = self->block1888.second;
      self->block1888.vtable = (unsigned int)(&DAT_003b0388);
      if (((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
         ((text != (u32 *)0x0 && (text != (u32 *)0x0)))) {
        FUN_0006778c((int)text,0);
      }
      text = self->block1888.first;
      if (((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
         ((text != (u32 *)0x0 && (text != (u32 *)0x0)))) {
        FUN_0006778c((int)text,0);
      }
      FUN_000658cc(&self->block1888,0);
    }
    if ((char *)&self->block1858 != (char *)0) {
      text = self->block1858.second;
      self->block1858.vtable = (unsigned int)(&DAT_003b0388);
      if ((((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
          (text != (u32 *)0x0)) && (text != (u32 *)0x0)) {
        FUN_0006778c((int)text,0);
      }
      text = self->block1858.first;
      if (((text != (u32 *)0x0) && (text != (u32 *)0x0)) &&
         ((text != (u32 *)0x0 && (text != (u32 *)0x0)))) {
        FUN_0006778c((int)text,0);
      }
      FUN_000658cc(&self->block1858,0);
    }
    member = (int *)self->member1844;
    if ((member != (int *)0x0) && (member != (int *)0x0)) {
      FUN_000550a0(member,0);
    }
    member = (int *)self->member1838;
    if ((member != (int *)0x0) && (member != (int *)0x0)) {
      FUN_000550a0(member,0);
    }
    member = (int *)self->member182c;
    if ((member != (int *)0x0) && (member != (int *)0x0)) {
      FUN_000550a0(member,0);
    }
    member = (int *)self->member1818;
    if ((member != (int *)0x0) && (member != (int *)0x0)) {
      FUN_0024b314(member,0);
    }
    FUN_0024c0ec(self->unk50,-1);
    FUN_0001ed28(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
