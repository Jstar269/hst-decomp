/* HSTMATCH module=hstp_trans_main.prx start=0x00003a44 end=0x00003ab0 symbol=FUN_00003a44 lang=c99 */
/* Clone of src/eboot/ctor_vtable_00003a44.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a class whose vtable is at +0x3b020c: the member at +4 is built with the flag -1, the
   object is registered through FUN_000a3c and a positive flag deletes the object afterwards.
   Names provisional. */
extern void FUN_00002a14(void *, int);
extern void FUN_00000a3c(void *, int);
extern void FUN_00000a00(void *);
extern char DAT_003b020c[];

void *FUN_00003a44(void *self, short flag)
{
  if (self != 0) {
    *(void **)self = DAT_003b020c;
    FUN_00002a14((char *)self + 4, -1);
    FUN_00000a3c(self, 0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
