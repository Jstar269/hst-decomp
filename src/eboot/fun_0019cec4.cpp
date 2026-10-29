/* HSTMATCH module=EBOOT.BIN start=0x0019cec4 end=0x0019cf80 symbol=FUN_0019cec4 lang=c++ */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); exact match verified; names and types await human review. */
#include "hst/types.h"

struct PtrVec { int *data; u32 size; u32 capacity; };
struct ListPair { char pad[4]; PtrVec first; PtrVec second; };
struct Entry { char pad[0x74]; u32 index; };
struct Tag {};

extern "C" void FUN_001073ac(PtrVec *, int *, Tag);

/* Record the entry's position in the first list, then append it to both lists. */
extern "C" void FUN_0019cec4(ListPair *lists,Entry *entry)
{
  int entryTmp [5];

  entryTmp[0] = (int)entry;
  entry->index = lists->first.size;
  if (lists->first.size < lists->first.capacity) {
    u32 count = ++lists->first.size;
    int offset = (count - 1) * 4;
    int *slot = (int *)((char *)lists->first.data + offset);
    *slot = entryTmp[0];
  }
  else {
    FUN_001073ac(&lists->first,&entryTmp[0],Tag());
  }
  if (lists->second.size < lists->second.capacity) {
    u32 count = ++lists->second.size;
    int offset = (count - 1) * 4;
    int *slot = (int *)((char *)lists->second.data + offset);
    *slot = entryTmp[0];
  }
  else {
    FUN_001073ac(&lists->second,&entryTmp[0],Tag());
  }
}
