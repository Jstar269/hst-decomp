/* HSTMATCH module=EBOOT.BIN start=0x00106c18 end=0x00106c64 symbol=FUN_00106c18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Row { short a; short b; short c; short d; };
struct List { int count; struct Row *rows; };
struct Owner { char pad[8]; unsigned short f8; char pad2[0x54 - 0xa]; struct List *f54; };

unsigned short FUN_00106c18(struct Owner *self, int idx)
{
  struct List *list;
  struct Row *row;
  int off;

  list = self->f54;
  if (list != 0) {
    if (list->count >= 2) {
      off = idx * 8;
      row = (struct Row *)(off + (int)list->rows);
      return (unsigned short)(row->c - row->a + 1);
    }
  }
  return self->f8;
}
