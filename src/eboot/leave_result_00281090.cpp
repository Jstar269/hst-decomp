/* HSTMATCH module=EBOOT.BIN start=0x00281090 end=0x00281128 symbol=FUN_00281090 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };
extern "C" void FUN_000ba78c(GObj *p);
extern "C" void FUN_000ba504(GObj *p);
extern "C" void FUN_00103628(void *a, int b);
struct Tag {};
extern "C" void FUN_00116414(void *a, int b, Tag c);
extern GObj *DAT_00338ac4;
extern char *DAT_003415ac;

extern "C" void FUN_00281090(int param_1)
{
  *(char *)(param_1 + 0x2c00) = 0;
  if (DAT_00338ac4 != 0) {
    FUN_000ba78c(DAT_00338ac4);
    FUN_000ba504(DAT_00338ac4);
    if (DAT_00338ac4 != 0) {
      delete DAT_00338ac4;
      DAT_00338ac4 = 0;
    }
  }
  FUN_00103628(DAT_003415ac, 1);
  FUN_00116414(DAT_003415ac + 0x8c, *(int *)(DAT_003415ac + 0x90), Tag());
}
