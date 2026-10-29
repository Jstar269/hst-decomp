/* HSTMATCH module=hstp_trans_main.prx start=0x0027dc40 end=0x0027de54 symbol=FUN_0027dc40 lang=c99 */
/* Clone of src/eboot/FUN_0026cc00.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2ec4;
extern u8 DAT_003b2ee0;
extern u32 * FUN_0001ec44();
extern int FUN_0005c2f8();
extern u32 * FUN_0010873c();
extern u32 FUN_0027e264();
extern u32 * FUN_0028b7b8();
extern u32 FUN_002a5040();

/* Object built by the constructor: fields are named by offset; the zero/default stores are listed in source order. */
typedef struct InitObj {
  const void *vtable; /* 0x0 */
  char pad4[0x38];
  const void *vtable3c; /* 0x3c vtable of the part built there */
  char pad40[0x50];
  int unk90[21]; /* 0x90 */
  char unke4[0xc]; /* 0xe4 */
  int unkf0; /* 0xf0 */
  char padf4[0x4];
  unsigned char unkf8; /* 0xf8 */
  char padf9[0xb];
  int unk104; /* 0x104 */
  char pad108[0x4];
  int unk10c; /* 0x10c */
  unsigned char unk110; /* 0x110 */
  char pad111[0x3];
  int unk114; /* 0x114 */
  int unk118[4]; /* 0x118 */
  int unk128[4]; /* 0x128 */
  int unk138[4]; /* 0x138 */
  int unk148[4]; /* 0x148 */
  int unk158[6]; /* 0x158 */
  unsigned char unk170[14]; /* 0x170 */
  char pad17e[0x2];
  int unk180; /* 0x180 */
  char pad184[0xc];
  char unk190[0x2c0]; /* 0x190 */
  int unk450; /* 0x450 */
  unsigned char unk454; /* 0x454 */
  char pad455[0x3];
  int unk458; /* 0x458 */
  int unk45c; /* 0x45c */
  char pad460[0x14];
  int unk474; /* 0x474 */
  char pad478[0x448];
  unsigned char unk8c0[6]; /* 0x8c0 */
  char pad8c6[0x2];
  int unk8c8; /* 0x8c8 */
  unsigned char unk8cc[3]; /* 0x8cc */
  char pad8cf;
  int unk8d0; /* 0x8d0 */
  int unk8d4; /* 0x8d4 */
  char pad8d8[0x48];
  char unk920[0x60]; /* 0x920 */
  int unk980; /* 0x980 */
  unsigned char unk984[3]; /* 0x984 */
  char pad987[0x11];
  int unk998; /* 0x998 */
  int unk99c[5]; /* 0x99c */
  char pad9b0[0x58];
  int unka08; /* 0xa08 */
  char pada0c[0x4];
  int unka10; /* 0xa10 */
  unsigned char unka14; /* 0xa14 */
  char pada15[0x2b];
  unsigned char unka40[4]; /* 0xa40 */
  int unka44[5]; /* 0xa44 */
} InitObj;

/* Constructor: builds the embedded parts, sets the fields to their defaults, then runs the final setup call. */
InitObj * FUN_0027dc40(InitObj *self)
{
  FUN_0001ec44();
  FUN_0010873c(&self->vtable3c);
  self->vtable = &DAT_003b2ec4;
  self->vtable3c = &DAT_003b2ee0;
  self->unk90[0] = 0;
  self->unk90[1] = 0;
  self->unk90[2] = 0;
  self->unk90[3] = 0;
  self->unk90[4] = 0;
  self->unk90[5] = 0;
  self->unk90[6] = 0;
  self->unk90[7] = 0;
  self->unk90[8] = 0;
  self->unk90[9] = 0;
  self->unk90[10] = 0;
  self->unk90[11] = 0;
  self->unk90[12] = 0;
  self->unk90[13] = 0;
  self->unk90[14] = 0;
  self->unk90[15] = 0;
  self->unk90[16] = 0;
  self->unk90[17] = 0;
  self->unk90[18] = 0;
  self->unk90[19] = 0;
  self->unk90[20] = 0;
  FUN_0028b7b8(&self->unke4);
  self->unkf0 = 0;
  self->unkf8 = 0;
  self->unk104 = 0;
  self->unk10c = 0;
  self->unk110 = 0;
  self->unk114 = 0;
  FUN_0005c2f8(&self->unk190);
  self->unk450 = 0;
  self->unk454 = 1;
  self->unk458 = 0;
  self->unk45c = 0;
  self->unk474 = 0;
  self->unk8c0[0] = 0;
  self->unk8c0[1] = 0;
  self->unk8c0[2] = 0;
  self->unk8c0[3] = 0;
  self->unk8c0[4] = 0;
  self->unk8c0[5] = 0;
  self->unk8c8 = 0;
  self->unk8cc[0] = 0;
  self->unk8cc[1] = 0;
  self->unk8cc[2] = 0;
  self->unk8d0 = 0;
  self->unk8d4 = 0;
  FUN_002a5040(&self->unk920);
  self->unk980 = -1;
  self->unk984[0] = 0;
  self->unk984[1] = 0;
  self->unk984[2] = 0;
  self->unk998 = 6;
  self->unk99c[0] = 0;
  self->unk99c[1] = 0;
  self->unk99c[2] = 0;
  self->unk99c[3] = 0;
  self->unk99c[4] = 0;
  self->unka08 = 0;
  self->unka10 = 0;
  self->unka14 = 0;
  self->unka40[0] = 0;
  self->unka40[1] = 0;
  self->unka40[2] = 0;
  self->unka40[3] = 0;
  self->unka44[0] = 0;
  self->unka44[1] = 0;
  self->unka44[2] = 0;
  self->unka44[3] = 0;
  self->unka44[4] = 0;
  self->unk158[0] = 0;
  self->unk158[1] = 0;
  self->unk158[2] = 0;
  self->unk158[3] = 0;
  self->unk158[4] = 0;
  self->unk158[5] = 0;
  self->unk170[0] = 0;
  self->unk170[1] = 0;
  self->unk170[2] = 0;
  self->unk170[3] = 0;
  self->unk170[4] = 0;
  self->unk170[5] = 0;
  self->unk170[6] = 0;
  self->unk170[7] = 0;
  self->unk170[8] = 0;
  self->unk170[9] = 0;
  self->unk170[10] = 0;
  self->unk170[11] = 0;
  self->unk170[12] = 0;
  self->unk170[13] = 0;
  self->unk180 = 0;
  self->unk118[0] = 4;
  self->unk128[0] = 4;
  self->unk138[0] = 0;
  self->unk148[0] = 0;
  self->unk118[1] = 4;
  self->unk128[1] = 4;
  self->unk138[1] = 0;
  self->unk148[1] = 0;
  self->unk118[2] = 4;
  self->unk128[2] = 4;
  self->unk138[2] = 0;
  self->unk148[2] = 0;
  self->unk118[3] = 4;
  self->unk128[3] = 4;
  self->unk138[3] = 0;
  self->unk148[3] = 0;
  FUN_0027e264(self);
  return self;
}
