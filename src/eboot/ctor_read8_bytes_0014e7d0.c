/* HSTMATCH module=EBOOT.BIN start=0x0014e7d0 end=0x0014e850 symbol=FUN_0014e7d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor: writes the vtable (0x30840c, then the base vtable 0x308280), clears the byte at +0x04,
   calls FUN_0014f050 on the argument and then reads eight bytes with FUN_0014f000 into the bytes at
   +0x08..+0x0f; returns the object pointer.
   Matching idioms: the vtable addresses have to be written as the ADDRESS of a global
   ("extern char DAT_0030840c[];" plus "self->vtable = DAT_0030840c;") so that mwccpsp emits the
   lui/addiu pair; the eight byte reads have to be a do/while with an unsigned counter (a plain
   for loop over the constant 8 is unrolled). */
#include "hst/script_node.h"

/* Script node followed by eight payload bytes. */
typedef struct ByteNode {
  ScriptNode base;      /* 0x00 */
  unsigned char bytes[8]; /* 0x08 */
} ByteNode;

extern char DAT_0030840c[];
extern char DAT_00308280[];
extern void FUN_0014f050(void *stream);
extern int FUN_0014f000(void *stream);

ByteNode *FUN_0014e7d0(ByteNode *self, void *stream)
{
  unsigned i;

  self->base.vtable = DAT_0030840c;
  self->base.unk04 = 0;
  self->base.vtable = DAT_00308280;
  FUN_0014f050(stream);
  i = 0;
  do {
    self->bytes[i] = FUN_0014f000(stream);
  } while (++i < 8);
  return self;
}
