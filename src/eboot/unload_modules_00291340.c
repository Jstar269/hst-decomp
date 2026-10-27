/* HSTMATCH module=EBOOT.BIN start=0x00291340 end=0x00291434 symbol=FUN_00291340 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (lane fm2 near miss wip/clear_handle_table_00291340.c) corrected by hand: stop/unload moved into an inline returning unsigned char, matching idiom: the flag is copied through a temporary (`t = ok; if (ok) t = StopUnload(*p); ok = t;`), which puts the else copy in retail's non-likely beqz slot; exact match verified; names and types await human review. */
extern unsigned char DAT_0034a7f8;
extern int DAT_0034a7fc;
extern char DAT_002ff4e4[]; /* "ERROR: sceKernelStopModule(): 0x%08x\n" */
extern char DAT_002ff50c[]; /* "ERROR: sceKernelUnloadModule(): 0x%08x\n" */
extern void FUN_0028fb44(const char *, int);
extern int FUN_002b7800(int);
extern int FUN_002b7808(int, int, int, int, int);

static inline unsigned char StopUnload(int id)
{
  int r = FUN_002b7808(id, 0, 0, 0, 0);
  if (r < 0) {
    FUN_0028fb44(DAT_002ff4e4, r);
    return 0;
  }
  r = FUN_002b7800(id);
  if (r < 0) {
    FUN_0028fb44(DAT_002ff50c, r);
    return 0;
  }
  return 1;
}

int FUN_00291340(void)
{
  int *p;
  int i;
  unsigned char ok;

  if (DAT_0034a7f8 == 0) return 1;
  ok = 1;
  i = 0;
  if (DAT_0034a7fc > 0) {
    p = &DAT_0034a7fc;
    do {
      unsigned char t = ok;
      if (ok)
        t = StopUnload(*p);
      ok = t;
      *p = 0;
      p++;
      i++;
    } while (i < *p);
  }
  DAT_0034a7f8 = 0;
  return ok;
}
