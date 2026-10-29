/* HSTMATCH module=EBOOT.BIN start=0x0010a5b0 end=0x0010a674 symbol=FUN_0010a5b0 lang=c99 */
extern int DAT_002d8e08;
extern int DAT_002d8e44;
extern int DAT_002d8e84;
extern void FUN_0010a684(int self, int a);
extern int FUN_002b7c98(void);
extern int FUN_002b7c60(void);
extern void FUN_0010a4a8(void *msg, int code);
void FUN_0010a5b0(int self, int *out, int a3)
{
  int r2;
  int v;
  FUN_0010a684(self, a3);
  int r = FUN_002b7c98();
  if (r < 0) {
    FUN_0010a4a8(&DAT_002d8e08, r);
    return;
  }
  if (r == 0) {
    v = *(int *)(self + 28);
    if (v != 0) {
      FUN_0010a4a8(&DAT_002d8e84, v);
      *out = -1;
    } else {
      *out = 1;
    }
  } else {
    if (r == 3) {
      r2 = FUN_002b7c60();
      if (r2 < 0) FUN_0010a4a8(&DAT_002d8e44, r2);
    }
  }
}
// near miss from lane dsn3 (unreviewed)
