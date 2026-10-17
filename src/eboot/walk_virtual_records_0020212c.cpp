/* HSTMATCH module=EBOOT.BIN start=0x0020212c end=0x002021b4 symbol=FUN_0020212c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void d0(); virtual void d1(); virtual void run(int); };
struct List { unsigned char active; char padding[3]; int count; };
extern "C" void FUN_0020212c(List *list, int value)
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
