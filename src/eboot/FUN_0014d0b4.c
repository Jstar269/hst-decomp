/* HSTMATCH module=EBOOT.BIN start=0x0014d0b4 end=0x0014d14c symbol=FUN_0014d0b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag t0) corrected by hand: readability pass (names, structs, constants), earlier refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_0014d0b4.c; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

/* Node holding a heap copy of a length-prefixed string read from a stream. */
typedef struct TextNode {
  ScriptNode base;   /* 0x00 */
  char *text;        /* 0x08, NUL-terminated copy */
} TextNode;

extern u8 DAT_003083b0;
extern u8 DAT_0030840c;
extern int FUN_00000a90();
extern char * FUN_00014b74();
extern u16 FUN_0014f050();

TextNode * FUN_0014d0b4(TextNode *self,StreamCursor *stream)
{
  u32 length;
  char *buf;

  self->base.vtable = &DAT_0030840c;
  self->base.unk04 = 0;
  self->base.vtable = &DAT_003083b0;
  self->text = 0;
  length = FUN_0014f050(stream);
  length = length & 0xffff;
  buf = (char *)FUN_00000a90(length + 1);
  self->text = buf;
  FUN_00014b74(buf,stream->pos,length);
  self->text[length] = 0;
  stream->pos = stream->pos + length;
  return self;
}
