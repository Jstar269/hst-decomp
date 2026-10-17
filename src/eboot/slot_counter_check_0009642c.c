/* HSTMATCH module=EBOOT.BIN start=0x0009642c end=0x00096588 symbol=FUN_0009642c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: for/guard loop shapes with the 4-or-2 count as if (flag != 0) 2 else 4, ints for the char temporaries, gate flag as int ((byte != 0) ^ 1) with the player pointer loaded first, sums written iVar6 + FUN(...) with the call inside the expression, the compared byte read into a temporary first; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int undefined4;

extern char * DAT_003386b0;
extern uchar DAT_003386b8;
extern undefined4 DAT_00338af0;
extern char * DAT_00338b44;
extern int FUN_000c4ba0();
extern void FUN_000c50c4();

undefined4 FUN_0009642c(int param_1,int param_2)
{
  int cVar1;
  int ok;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uchar *pl;
  int t;
  
  iVar3 = FUN_000c4ba0(DAT_00338af0,*(int *)(param_1 + 0x148));
  iVar6 = param_2 * 4;
  iVar5 = *(int *)(param_1 + 0x148);
  cVar1 = *(char *)(iVar5 + (iVar6 + iVar3) + 0xc);
  if (*(uchar *)(DAT_00338b44 + 0x45) != 0) {
    iVar3 = 2;
  }
  else {
    iVar3 = 4;
  }
  for (iVar7 = 0; iVar7 < iVar3; iVar7++) {
    if (iVar7 != iVar5) {
      iVar4 = iVar6 + FUN_000c4ba0(DAT_00338af0,iVar7);
      iVar5 = *(int *)(param_1 + 0x148);
      t = *(char *)(iVar4 + iVar5 + 0xc);
      if (t != cVar1) {
        FUN_000c50c4(DAT_00338af0);
        return 0;
      }
    }
  }
  iVar5 = 0;
  if (iVar3 > 0) {
    iVar7 = 0;
    do {
      pl = *(uchar **)(DAT_003386b0 + iVar7 + 0x70);
      ok = DAT_003386b8 != 0;
      if (ok) {
        ok = (pl[0x1b4] != 0) ^ 1;
      }
      if (ok) {
        iVar4 = iVar6 + FUN_000c4ba0(DAT_00338af0,iVar5);
        iVar4 += *(int *)(param_1 + 0x148);
        *(char *)(iVar4 + 0xc) = *(char *)(iVar4 + 0xc) + 1;
      }
      iVar5++;
      iVar7 += 4;
    } while (iVar5 < iVar3);
  }
  return 1;
}
