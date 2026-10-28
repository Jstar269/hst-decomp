/* HSTMATCH module=hstp_trans_main.prx start=0x001aa400 end=0x001aa4bc symbol=FUN_001aa400 lang=c++ */
/* Clone of src/eboot/fun_0019cec4.cpp (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); exact match verified; names and types await human review. */
#include "hst/types.h"

struct Vec { int *data; u32 size; u32 capacity; };
struct Pair { char pad[4]; Vec first; Vec second; };
struct Entry { char pad[0x74]; u32 value; };
struct Tag {};

extern "C" void FUN_0010d16c(Vec *, int *, Tag);

extern "C" void FUN_001aa400(int param_1,int param_2)
{
  Pair *pair = (Pair *)param_1;
  Entry *entry = (Entry *)param_2;
  int local_14 [5];

  local_14[0] = param_2;
  entry->value = pair->first.size;
  if (pair->first.size < pair->first.capacity) {
    u32 next = ++pair->first.size;
    int offset = (next - 1) * 4;
    int *slot = (int *)((char *)pair->first.data + offset);
    *slot = local_14[0];
  }
  else {
    FUN_0010d16c(&pair->first,&local_14[0],Tag());
  }
  if (pair->second.size < pair->second.capacity) {
    u32 next = ++pair->second.size;
    int offset = (next - 1) * 4;
    int *slot = (int *)((char *)pair->second.data + offset);
    *slot = local_14[0];
  }
  else {
    FUN_0010d16c(&pair->second,&local_14[0],Tag());
  }
}
