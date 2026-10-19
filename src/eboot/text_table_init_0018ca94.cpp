/* HSTMATCH module=EBOOT.BIN start=0x0018ca94 end=0x0018cb28 symbol=FUN_0018ca94 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_0018cb28();
extern "C" void FUN_000fcb7c();
extern "C" void *FUN_00000a90(int size);
extern "C" void *FUN_000008d8(void *a0, void *a1, void *a2, int a3, int a4);
extern "C" void FUN_0010ae20(void *dst, const char *src);
extern char *DAT_003415b0;
extern const char *DAT_002e115c[];

extern "C" void FUN_0018ca94(void)
{
  DAT_003415b0 = (char *)FUN_000008d8(FUN_00000a90(0x160), (void *)FUN_0018cb28, (void *)FUN_000fcb7c, 0x10, 0x15);
  for (unsigned int n = 0; n < 0x15; n++) {
    FUN_0010ae20(DAT_003415b0 + n * 0x10, DAT_002e115c[n]);
  }
}
