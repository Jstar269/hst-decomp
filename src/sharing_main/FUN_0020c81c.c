/* HSTMATCH module=hstp_trans_main.prx start=0x0020c81c end=0x0020c850 symbol=FUN_0020c81c lang=c99 */
/* Clone of src/eboot/FUN_001fe04c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct Owner {
  char pad0[200];
  char unkC8[0xcd0 - 200];  /* 0xc8 */
  char unkCD0[0x1250 - 0xcd0];  /* 0xcd0 */
  char unk1250[1];          /* 0x1250 */
} Owner;

extern void FUN_0021019c();
extern void FUN_002108fc();

void FUN_0020c81c(Owner *self)
{
  FUN_0021019c(self->unkC8);
  FUN_002108fc(self->unk1250,self->unkCD0);
}
