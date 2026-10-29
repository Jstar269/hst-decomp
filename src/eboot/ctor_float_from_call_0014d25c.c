/* HSTMATCH module=EBOOT.BIN start=0x0014d25c end=0x0014d2d0 symbol=FUN_0014d25c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: prototyped extern with unsigned result so the (float)unsigned conversion matches; readability pass; exact match verified; names and types await human review. */
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

extern char DAT_0030840c;
extern char DAT_00308394;
extern unsigned FUN_0014f050(StreamCursor *stream);

/* Reads the float as an unsigned 16-bit value from the stream. */
FloatNode *FUN_0014d25c(FloatNode *self, StreamCursor *stream)
{
    unsigned v;
    self->base.vtable = &DAT_0030840c;
    self->base.unk04 = 0;
    self->base.vtable = &DAT_00308394;
    v = FUN_0014f050(stream);
    self->value = (float)v;
    return self;
}
