/* HSTMATCH module=EBOOT.BIN start=0x00145c5c end=0x00145cfc symbol=FUN_00145c5c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Feeds two kinds of targets to FUN_0005f1e8 depending on the global flag word DAT_002d5ab0:
   bit 0x10 together with the object's own byte flag at +0xd1c clears the object at +0x4,
   bit 0x8 clears every entry of the pointer array at +0x148 (+0x20 into each entry), the number of
   entries being the unsigned count at +0x14c.
   Matching idioms: #pragma opt_strength_reduction off keeps retail's per-iteration "sll idx,2" instead
   of a byte offset; the loop counter is INITIALISED BEFORE the "count != 0" test (that puts the
   "move s0,zero" into the delay slot of the count branch, as in retail - with the init inside the
   guarded block the compiler leaves a nop there); the count and the array pointer are re-read from the
   object on every pass because the call may change them. */
#pragma opt_strength_reduction off
typedef unsigned char u8;

typedef struct {
  char pad4[4];
  char *f4;
  char pad148[0x148 - 8];
  char **arr;
  unsigned count;
  char pad_d1c[0xd1c - 0x150];
  u8 flag;
} Obj;

extern unsigned int DAT_002d5ab0;
extern void FUN_0005f1e8(char *a0, int a1);

void FUN_00145c5c(Obj *self)
{
  if (self->flag != 0 && (DAT_002d5ab0 & 0x10) != 0) {
    FUN_0005f1e8(self->f4, 0);
  }
  if ((DAT_002d5ab0 & 8) != 0) {
    unsigned i = 0;
    if (self->count != 0) {
      do {
        FUN_0005f1e8(self->arr[i] + 0x20, 0);
        i++;
      } while (i < self->count);
    }
  }
}
