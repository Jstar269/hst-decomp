/* HSTMATCH module=hstp_trans_main.prx start=0x002108fc end=0x00210984 symbol=FUN_002108fc lang=c++ */
/* Clone of src/eboot/walk_virtual_records_0020212c.cpp (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void d0(); virtual void d1(); virtual void run(int); };
struct List { unsigned char active; char padding[3]; int count; };
extern "C" void FUN_002108fc(List *list, int value)
{
  int i;
  char *cursor;
  int current;
  if (list->active != 0) {
    i = 0;
    if (list->count > 0) {
      current = value;
      cursor = (char *)list;
      do {
        VC *item = *(VC **)(cursor + 8);
        if (item != 0) item->run(current);
        ++i;
        cursor += 4;
        current += 0x2c0;
      } while (i < list->count);
    }
  }
}
