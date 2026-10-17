/* HSTMATCH module=EBOOT.BIN start=0x000b2144 end=0x000b21cc symbol=FUN_000b2144 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: shared check and failure labels preserve the mode branches and float-result join; exact match verified; names and types await human review. */
extern float DAT_003411e8;
extern unsigned char *DAT_003386b0;
extern unsigned char *DAT_00340284;
int FUN_000b2144(int self) {
  int mode = *(int *)(DAT_003386b0 + 0x3c);
  if (mode == 4) goto check;
  if (mode == 5) goto check;
  if (mode != 7) goto fail;
  if (*(unsigned char *)(*(int *)(DAT_00340284 + 0x80) + 0x78) != 0) goto fail;
check:
  {
    float limit = DAT_003411e8 * 0.7f;
    float value = *(float *)(self + 0x43c);
    if (!(value >= limit)) goto fail;
  }
  return 1;
fail:
  return 0;
}
