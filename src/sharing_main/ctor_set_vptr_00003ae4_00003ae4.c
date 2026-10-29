/* HSTMATCH module=hstp_trans_main.prx start=0x00003ae4 end=0x00003b30 symbol=FUN_00003ae4 lang=c99 */
/* Clone of src/eboot/ctor_set_vptr_00003ae4.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (from the km1 near miss); exact match verified; names and types await human review. */
extern void FUN_00002ad4(void *);
extern void FUN_00002a64(void *, void *);
extern char DAT_003b020c[];

typedef struct {
  void *vptr;
} Head;

Head *FUN_00003ae4(Head *self, void *arg)
{
  FUN_00002ad4(self);
  self->vptr = DAT_003b020c;
  FUN_00002a64((char *)self + 4, arg);
  return self;
}
