/* HSTMATCH module=hstp_trans_main.prx start=0x0015a760 end=0x0015a7e0 symbol=FUN_0015a760 lang=c99 */
/* Clone of src/eboot/ctor_read8_bytes_0014e7d0.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor: writes the vtable (0x3b16d8, then the base vtable 0x3b154c), clears the byte at +0x04,
   calls FUN_0015b050 on the argument and then reads eight bytes with FUN_0015b000 into the bytes at
   +0x08..+0x0f; returns the object pointer.
   Matching idioms: the vtable addresses have to be written as the ADDRESS of a global
   ("extern char DAT_003b16d8[];" plus "self->vtable = DAT_003b16d8;") so that mwccpsp emits the
   lui/addiu pair; the eight byte reads have to be a do/while with an unsigned counter (a plain
   for loop over the constant 8 is unrolled). */
typedef struct {
  void *vtable;
  unsigned char f4;
  char pad05[3];
  unsigned char f8[8];
} Obj;

extern char DAT_003b16d8[];
extern char DAT_003b154c[];
extern void FUN_0015b050(void *p);
extern int FUN_0015b000(void *p);

Obj *FUN_0015a760(Obj *self, void *arg)
{
  unsigned i;

  self->vtable = DAT_003b16d8;
  self->f4 = 0;
  self->vtable = DAT_003b154c;
  FUN_0015b050(arg);
  i = 0;
  do {
    self->f8[i] = FUN_0015b000(arg);
  } while (++i < 8);
  return self;
}
