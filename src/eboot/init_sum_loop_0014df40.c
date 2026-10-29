/* HSTMATCH module=EBOOT.BIN start=0x0014df40 end=0x0014e00c symbol=FUN_0014df40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: the loop end is a fresh variable (`end = pos + count`, which gives retail's `addu s2,v0,s2` operand order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

/* Node holding a list of child nodes, each created from the stream. */
typedef struct ListNode {
  ScriptNode base;  /* 0x00 */
  u32 children[3];  /* 0x08, list container; children[1] is the position the new child is inserted at */
} ListNode;

extern u8 DAT_003082d4;
extern u8 DAT_0030840c;
extern u32 * FUN_0014e4a8();
extern u16 FUN_0014f050();
extern u32 FUN_0014f5e0();
extern u32 * FUN_0014f6e4();

ListNode * FUN_0014df40(ListNode *self,StreamCursor *stream)
{
  u16 id;
  u32 byteCount;
  u32 pos;
  u32 end;
  u32 child;
  u8 insertResult [4];
  u32 *where;

  self->base.vtable = &DAT_0030840c;
  self->base.unk04 = 0;
  self->base.vtable = &DAT_003082d4;
  FUN_0014f6e4(self->children);
  byteCount = FUN_0014f050(stream);
  FUN_0014f050(stream);
  pos = (u32)stream->pos;
  end = pos + byteCount;
  while (pos < end) {
    id = FUN_0014f050(stream);
    child = (unsigned int)(FUN_0014e4a8(self,id,stream));
    where = &self->children[1];
    FUN_0014f5e0(insertResult,self->children,&where,&child);
    pos = (u32)stream->pos;
  }
  return self;
}
