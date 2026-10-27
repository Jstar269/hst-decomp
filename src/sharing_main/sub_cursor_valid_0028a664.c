/* HSTMATCH module=hstp_trans_main.prx start=0x0028a664 end=0x0028a694 symbol=FUN_0028a664 lang=c99 */
/* Clone of src/eboot/sub_cursor_valid_00279380.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (the predicate inlined into 0x002793b0); exact match verified; names and types await human review. */
typedef struct Sub {
  char pad0[0xdc];
  int cursor;
} Sub;

typedef struct Obj {
  char pad0[0x474];
  Sub *sub;
} Obj;

int FUN_0028a664(Obj *o)
{
  int c = o->sub->cursor;
  if (c >= 0 && c < 4)
    return 1;
  return 0;
}
