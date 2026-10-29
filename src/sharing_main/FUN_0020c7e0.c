/* HSTMATCH module=hstp_trans_main.prx start=0x0020c7e0 end=0x0020c81c symbol=FUN_0020c7e0 lang=c99 */
/* Clone of src/eboot/FUN_001fe010.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct Owner {
  char pad0[200];
  char unkC8[0x1250 - 200];  /* 0xc8 */
  char unk1250[1];           /* 0x1250 */
} Owner;

extern void FUN_0020c384();
extern void FUN_0020c520();
extern void FUN_002100e0();
extern void FUN_00210598();

void FUN_0020c7e0(Owner *self)
{
  FUN_0020c520();
  FUN_0020c384(self);
  FUN_002100e0(self->unkC8);
  FUN_00210598(self->unk1250);
}
