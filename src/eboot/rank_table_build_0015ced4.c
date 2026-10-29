/* HSTMATCH module=EBOOT.BIN start=0x0015ced4 end=0x0015d0f0 symbol=FUN_0015ced4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: each of the three loops has its own block-scope counter (a shared counter changes the register colouring of the last loop). */
extern unsigned char DAT_0034110c;
extern int DAT_0034040c[256];
extern int DAT_0034080c[256];
extern int DAT_00340c0c[256];
extern char *FUN_0015cce8();

void FUN_0015ced4(int param_1)
{
  if (DAT_0034110c == 0) {
    DAT_0034110c = 1;
    for (int k = 0; k < 256; k++) {
      char *p;
      p = FUN_0015cce8(param_1, k);
      if (p != 0 && *p >= 0) {
        DAT_0034040c[k] = k;
        DAT_00340c0c[k] = *(int *)(p + 0x24);
      } else {
        DAT_0034040c[k] = 0x101;
        DAT_00340c0c[k] = 9999;
      }
      DAT_0034080c[k] = 0;
    }
    for (int i = 0; i < 256; i++) {
      for (int j = i + 1; j < 256; j++) {
        if (DAT_00340c0c[i] > DAT_00340c0c[j]) {
          int t = DAT_00340c0c[i];
          DAT_00340c0c[i] = DAT_00340c0c[j];
          DAT_00340c0c[j] = t;
          t = DAT_0034040c[i];
          DAT_0034040c[i] = DAT_0034040c[j];
          DAT_0034040c[j] = t;
        }
      }
    }
    for (int m = 0; m < 256; m++) {
      DAT_0034080c[DAT_0034040c[m]] = m + 1;
    }
  }
}
