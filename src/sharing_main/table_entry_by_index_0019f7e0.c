/* HSTMATCH module=hstp_trans_main.prx start=0x0019f7e0 end=0x0019f834 symbol=FUN_0019f7e0 lang=c99 */
/* Clone of src/eboot/table_entry_by_index_00192fd0.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Item { char b[0x9c]; } Item;
typedef struct Tbl { unsigned count; Item *items; } Tbl;
extern Tbl *DAT_003eaa70;

Item *FUN_0019f7e0(int i)
{
  Tbl *t = DAT_003eaa70;
  if (t != 0 && i >= 0 && i < t->count)
    return &t->items[i];
  return 0;
}
