/* HSTMATCH module=EBOOT.BIN start=0x00293bd4 end=0x00293c6c symbol=FUN_00293bd4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VirtualObject {
  virtual void setMode(int);
};

extern int *DAT_0034a84c;
extern char DAT_002ffbe4;
extern const char DAT_002ffbcc[];
extern "C" void *FUN_00000bcc(int);
extern "C" int *FUN_000649c0(void *);
extern "C" int FUN_00064bf4(int *, const char *, int, void *);

extern "C" void FUN_00293bd4(void)
{
  if (DAT_0034a84c == 0) {
    int *object = (int *)FUN_00000bcc(0x10);
    if (object != 0)
      object = FUN_000649c0(object);
    DAT_0034a84c = object;

    int result = FUN_00064bf4(object, DAT_002ffbcc, 1, &DAT_002ffbe4);
    if (result == 0 && DAT_0034a84c != 0) {
      if (DAT_0034a84c != 0)
        ((VirtualObject *)DAT_0034a84c)->setMode(1);
      DAT_0034a84c = 0;
    }
  }
}
