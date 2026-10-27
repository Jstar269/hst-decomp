/* HSTMATCH module=hstp_trans_main.prx start=0x002ad284 end=0x002ad2dc symbol=FUN_002ad284 lang=c99 helpers=FUN_002a9808@0x002a9808-0x002a9834 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/FUN_0029e108.c: addresses substituted, the same-file static log stub FUN_002a9808 defined in front of it and placed at its own retail address by helpers=); returns the second status (a void function differs by 5 words: the result stays live in v0 across the stub); exact match verified; names and types await human review. */
/* Unloads the ad hoc and the common net utility modules and logs a failure of either call: the two
   messages name sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC / _NET_COMMON), so FUN_002c7a60
   (an 8-byte import stub) is that call and 0x101 / 0x100 are the module ids. */
extern char DAT_002db588[];
extern char DAT_002db5dc[];

static void FUN_002a9808(...)
{
}

extern int FUN_002c7a60(int module);

int FUN_002ad284(void)
{
  int ret;

  ret = FUN_002c7a60(0x101);
  if (ret < 0) {
    FUN_002a9808(DAT_002db5dc, ret);
  }
  ret = FUN_002c7a60(0x100);
  if (ret < 0) {
    FUN_002a9808(DAT_002db588, ret);
  }
  return ret;
}
