/* HSTMATCH module=hstp_trans_main.prx start=0x000c4cc4 end=0x000c4d4c symbol=FUN_000c4cc4 lang=c99 */
/* Clone of src/eboot/FUN_000c1624.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { INIT_BLOCK_SIZE = 0x4c, INIT_COPY_SIZE = 0x10 };

typedef struct InitRecord {
  char pad00[0x20];
  char block20[INIT_COPY_SIZE];   /* 0x20 copied from a constant block */
  u8 *unk30;                      /* 0x30 */
  char *unk34;                    /* 0x34 */
  u8 *unk38;                      /* 0x38 */
  u8 *unk3c;                      /* 0x3c */
  u8 *unk40;                      /* 0x40 */
  u32 unk44;                      /* 0x44 */
  u8 unk48;                       /* 0x48 */
} InitRecord;

extern u8 DAT_002d0310;
extern u8 DAT_0037c3ac;
extern u8 DAT_0037c3bc;
extern u8 DAT_0037c3c4;
extern char DAT_0037c3b4[];
extern u32 * FUN_00011090();
extern u32 * FUN_000114c0();

/* Clears a record and fills it with its default constants and string pointers. */
void FUN_000c4cc4(InitRecord *self)
{
  if (self != 0) {
    FUN_000114c0(self,0,INIT_BLOCK_SIZE);
    FUN_00011090(self->block20,&DAT_002d0310,INIT_COPY_SIZE);
    self->unk30 = &DAT_0037c3ac;
    self->unk34 = DAT_0037c3b4;
    self->unk38 = &DAT_0037c3bc;
    self->unk3c = &DAT_0037c3c4;
    self->unk40 = &DAT_0037c3c4;
    self->unk44 = 1;
    self->unk48 = 1;
  }
}
