/* HSTMATCH module=hstp_trans_main.prx start=0x00199274 end=0x00199308 symbol=FUN_00199274 lang=c++ */
/* Clone of src/eboot/text_table_init_0018ca94.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00199308();
extern "C" void FUN_001022b8();
extern "C" void *FUN_00000a90(int size);
extern "C" void *FUN_000008d8(void *a0, void *a1, void *a2, int a3, int a4);
extern "C" void FUN_00110be0(void *dst, const char *src);
extern char *DAT_003ea8f0;
extern const char *DAT_00388838[];

extern "C" void FUN_00199274(void)
{
  DAT_003ea8f0 = (char *)FUN_000008d8(FUN_00000a90(0x160), (void *)FUN_00199308, (void *)FUN_001022b8, 0x10, 0x15);
  for (unsigned int n = 0; n < 0x15; n++) {
    FUN_00110be0(DAT_003ea8f0 + n * 0x10, DAT_00388838[n]);
  }
}
