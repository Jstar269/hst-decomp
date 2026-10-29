/* HSTMATCH module=hstp_trans_main.prx start=0x0016947c end=0x00169698 symbol=FUN_0016947c lang=c99 */
/* Clone of src/eboot/rank_table_build_0015ced4.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: each of the three loops has its own block-scope counter (a shared counter changes the register colouring of the last loop). */
extern unsigned char DAT_003ea44c;
extern int DAT_003e974c[256];
extern int DAT_003e9b4c[256];
extern int DAT_003e9f4c[256];
extern char *FUN_00169290();

void FUN_0016947c(int param_1)
{
  if (DAT_003ea44c == 0) {
    DAT_003ea44c = 1;
    for (int k = 0; k < 256; k++) {
      char *p;
      p = FUN_00169290(param_1, k);
      if (p != 0 && *p >= 0) {
        DAT_003e974c[k] = k;
        DAT_003e9f4c[k] = *(int *)(p + 0x24);
      } else {
        DAT_003e974c[k] = 0x101;
        DAT_003e9f4c[k] = 9999;
      }
      DAT_003e9b4c[k] = 0;
    }
    for (int i = 0; i < 256; i++) {
      for (int j = i + 1; j < 256; j++) {
        if (DAT_003e9f4c[i] > DAT_003e9f4c[j]) {
          int t = DAT_003e9f4c[i];
          DAT_003e9f4c[i] = DAT_003e9f4c[j];
          DAT_003e9f4c[j] = t;
          t = DAT_003e974c[i];
          DAT_003e974c[i] = DAT_003e974c[j];
          DAT_003e974c[j] = t;
        }
      }
    }
    for (int m = 0; m < 256; m++) {
      DAT_003e9b4c[DAT_003e974c[m]] = m + 1;
    }
  }
}
