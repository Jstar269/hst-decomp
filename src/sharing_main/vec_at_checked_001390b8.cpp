/* HSTMATCH module=hstp_trans_main.prx start=0x001390b8 end=0x0013911c symbol=FUN_001390b8 lang=c++ */
/* Clone of src/eboot/vec_at_checked_0012dbb8.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_00381f24[];
extern "C" int FUN_0000d530();
extern "C" void FUN_0000f3e8(int, char *);
struct Reent { int pad[3]; int err; };
extern "C" Reent *FUN_0000fe3c();

struct V { int *data; unsigned int size; };

extern "C" int *FUN_001390b8(V *v, unsigned int idx)
{
  if (idx >= v->size) {
    FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00381f24);
    FUN_0000d530();
  }
  return &v->data[idx];
}
