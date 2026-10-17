/* HSTMATCH module=EBOOT.BIN start=0x0012dbb8 end=0x0012dc1c symbol=FUN_0012dbb8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002dadb0[];
extern "C" int FUN_0000d518();
extern "C" void FUN_0000f3e8(int, char *);
struct Reent { int pad[3]; int err; };
extern "C" Reent *FUN_0000fe3c();

struct V { int *data; unsigned int size; };

extern "C" int *FUN_0012dbb8(V *v, unsigned int idx)
{
  if (idx >= v->size) {
    FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dadb0);
    FUN_0000d518();
  }
  return &v->data[idx];
}
