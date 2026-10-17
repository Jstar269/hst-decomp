/* HSTMATCH module=EBOOT.BIN start=0x00193474 end=0x001934c8 symbol=FUN_00193474 lang=c99 */
/* Clone of src/eboot/table_entry_by_index_00192fd0.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Item { char b[0x9c]; } Item;
typedef struct Tbl { unsigned count; Item *items; } Tbl;
extern Tbl *DAT_00341744;

Item *FUN_00193474(int i)
{
  Tbl *t = DAT_00341744;
  if (t != 0 && i >= 0 && i < t->count)
    return &t->items[i];
  return 0;
}
