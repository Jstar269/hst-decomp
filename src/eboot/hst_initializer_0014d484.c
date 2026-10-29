/* HSTMATCH module=EBOOT.BIN start=0x0014d484 end=0x0014d53c symbol=FUN_0014d484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop counter is an unsigned local declared before the byte-offset local (counter s1, offset s0, sltiu); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

/* Number of value slots in a ValuesNode. */
#define VALUES_NODE_MAX 8

/* Node with a 16-bit selector, a count and up to eight 32-bit values read from the stream. */
typedef struct ValuesNode {
  ScriptNode base;                /* 0x00 */
  u32 selector;                   /* 0x08 */
  u32 count;                      /* 0x0c, values actually present */
  u32 values[VALUES_NODE_MAX];    /* 0x10, unused slots are zero */
} ValuesNode;

extern u8 DAT_00308360;
extern u8 DAT_0030840c;
extern u32 FUN_0014f028();
extern u32 FUN_0014f03c();
extern u16 FUN_0014f050();

#pragma opt_strength_reduction off

ValuesNode * FUN_0014d484(ValuesNode *self,StreamCursor *stream)
{
  u32 value;
  int selector;
  u32 i;
  int off;
  
  self->base.vtable = &DAT_0030840c;
  self->base.unk04 = 0;
  self->base.vtable = &DAT_00308360;
  selector = FUN_0014f050(stream);
  self->selector = selector & 0xffff;
  value = FUN_0014f03c(stream);
  self->count = value;
  i = 0;
  off = 0;
  do {
    if (i < (u32)self->count) {
      value = FUN_0014f028(stream);
      *(u32 *)((int)self + off + 0x10) = value;
    }
    else {
      *(u32 *)((int)self + off + 0x10) = 0;
    }
    i = i + 1;
    off = off + 4;
  } while (i < VALUES_NODE_MAX);
  return self;
}
