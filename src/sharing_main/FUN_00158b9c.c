/* HSTMATCH module=hstp_trans_main.prx start=0x00158b9c end=0x00158c34 symbol=FUN_00158b9c lang=c99 */
/* Clone of src/eboot/FUN_0014d0b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

/* Node holding a heap copy of a length-prefixed string read from a stream. */
typedef struct TextNode {
  ScriptNode base;   /* 0x00 */
  char *text;        /* 0x08, NUL-terminated copy */
} TextNode;

extern u8 DAT_003b167c;
extern u8 DAT_003b16d8;
extern int FUN_00000a90();
extern char * FUN_00014b74();
extern u16 FUN_0015b050();

TextNode * FUN_00158b9c(TextNode *self,StreamCursor *stream)
{
  u32 length;
  char *buf;

  self->base.vtable = &DAT_003b16d8;
  self->base.unk04 = 0;
  self->base.vtable = &DAT_003b167c;
  self->text = 0;
  length = FUN_0015b050(stream);
  length = length & 0xffff;
  buf = (char *)FUN_00000a90(length + 1);
  self->text = buf;
  FUN_00014b74(buf,stream->pos,length);
  self->text[length] = 0;
  stream->pos = stream->pos + length;
  return self;
}
