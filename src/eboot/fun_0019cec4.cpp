/* HSTMATCH module=EBOOT.BIN start=0x0019cec4 end=0x0019cf80 symbol=FUN_0019cec4 lang=c++ */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct Vec { int *data; uint size; uint capacity; };
struct Pair { char pad[4]; Vec first; Vec second; };
struct Entry { char pad[0x74]; undefined4 value; };
struct Tag {};

extern "C" void FUN_001073ac(Vec *, int *, Tag);

extern "C" void FUN_0019cec4(int param_1,int param_2)
{
  Pair *pair = (Pair *)param_1;
  Entry *entry = (Entry *)param_2;
  int local_14 [5];

  local_14[0] = param_2;
  entry->value = pair->first.size;
  if (pair->first.size < pair->first.capacity) {
    uint next = ++pair->first.size;
    int offset = (next - 1) * 4;
    int *slot = (int *)((char *)pair->first.data + offset);
    *slot = local_14[0];
  }
  else {
    FUN_001073ac(&pair->first,&local_14[0],Tag());
  }
  if (pair->second.size < pair->second.capacity) {
    uint next = ++pair->second.size;
    int offset = (next - 1) * 4;
    int *slot = (int *)((char *)pair->second.data + offset);
    *slot = local_14[0];
  }
  else {
    FUN_001073ac(&pair->second,&local_14[0],Tag());
  }
  return;
}
