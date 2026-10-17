/* HSTMATCH module=EBOOT.BIN start=0x00192fd0 end=0x00193024 symbol=FUN_00192fd0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Item { char b[0x9c]; } Item;
typedef struct Tbl { unsigned count; Item *items; } Tbl;
extern Tbl *DAT_00341730;

Item *FUN_00192fd0(int i)
{
  Tbl *t = DAT_00341730;
  if (t != 0 && i >= 0 && i < t->count)
    return &t->items[i];
  return 0;
}
