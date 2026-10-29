/* HSTMATCH module=EBOOT.BIN start=0x000c1624 end=0x000c16ac symbol=FUN_000c1624 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
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

extern u8 DAT_002c00e8;
extern u8 DAT_002d5a5c;
extern u8 DAT_002d5a6c;
extern u8 DAT_002d5a74;
extern char DAT_002d5a64[];
extern u32 * FUN_00011090();
extern u32 * FUN_000114c0();

/* Clears a record and fills it with its default constants and string pointers. */
void FUN_000c1624(InitRecord *self)
{
  if (self != 0) {
    FUN_000114c0(self,0,INIT_BLOCK_SIZE);
    FUN_00011090(self->block20,&DAT_002c00e8,INIT_COPY_SIZE);
    self->unk30 = &DAT_002d5a5c;
    self->unk34 = DAT_002d5a64;
    self->unk38 = &DAT_002d5a6c;
    self->unk3c = &DAT_002d5a74;
    self->unk40 = &DAT_002d5a74;
    self->unk44 = 1;
    self->unk48 = 1;
  }
}
