/* HSTMATCH module=EBOOT.BIN start=0x0001b880 end=0x0001b918 symbol=FUN_0001b880 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Poll loop: waits until FUN_002b7cf8() reports bit 0x20, logging DAT_002cfb08 through FUN_0001b918 once per
   pass, releasing the object held in DAT_00338ac4 through FUN_0000bb190 when its +40 field is 11, and sleeping
   1,000,000us per pass; the terminal sleep(100) is shared with the early-exit path (the li a0,100 in the
   bnezl delay slot). The doubled test (one at the top, one at the back edge) is the plain `while` form. */
extern "C" int FUN_002b7cf8();
extern "C" void FUN_0001b918(char *msg);
extern "C" int FUN_000464ec();
extern "C" void FUN_000bb190(void *obj);
extern "C" void FUN_002b7958(int us);
extern "C" char DAT_002cfb08[];
extern "C" void *DAT_00338ac4;

extern "C" void FUN_0001b880(void)
{
  while ((FUN_002b7cf8() & 0x20) == 0) {
    FUN_0001b918(DAT_002cfb08);
    if (FUN_000464ec() != 0) {
      void *p = DAT_00338ac4;
      if (p != 0 && *(int *)((char *)p + 40) == 11) {
        FUN_000bb190(p);
      }
    }
    FUN_002b7958(1000000);
  }
  FUN_002b7958(100);
}
