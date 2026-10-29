/* HSTMATCH module=hstp_trans_main.prx start=0x002b62c0 end=0x002b62f8 symbol=FUN_002b62c0 lang=c99 */
/* Clone of src/eboot/FUN_002a6b30.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct Obj {
  char pad00[0x880];
  int unk880;       /* 0x880, when zero the extra step runs */
} Obj;

extern void FUN_00108aec();
extern void FUN_002b5df8();

void FUN_002b62c0(Obj *self)
{
  if (self->unk880 == 0) {
    FUN_002b5df8();
  }
  FUN_00108aec(self);
}
