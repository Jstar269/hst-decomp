/* HSTMATCH module=EBOOT.BIN start=0x00130304 end=0x00130654 symbol=FUN_00130304 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen mechanical draft) corrected by hand: flipped the strcmp-equality chain to the positive if/else-if form, an accumulator per digit field, and the loop increment order; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern undefined DAT_002db130;
extern undefined DAT_002db134;
extern char DAT_002db01c[];
extern char DAT_002db100[];
extern char DAT_002db10c[];
extern char DAT_002db118[];
extern char DAT_002db124[];
extern char DAT_002db13c[];
extern char DAT_002db144[];
extern char DAT_002db150[];
extern char DAT_002db158[];
extern char DAT_002db164[];
extern char DAT_002db174[];
extern char DAT_002db180[];
extern char *FUN_00014d64();

undefined4 FUN_00130304(undefined4 param_1, int param_2, unsigned int *param_3)
{
  char *iVar1;
  char *pcVar2;
  int n;
  undefined4 uVar3;

  uVar3 = 0;
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    if (FUN_00014d64(param_2, DAT_002db100) != 0) {
      uVar3 = 1;
    }
    else if (FUN_00014d64(param_2, DAT_002db10c) != 0) {
      uVar3 = 2;
    }
    else if (FUN_00014d64(param_2, DAT_002db118) != 0) {
      uVar3 = 3;
    }
    else if (FUN_00014d64(param_2, DAT_002db124) != 0) {
      uVar3 = 4;
      pcVar2 = FUN_00014d64(param_2, DAT_002db124) + 10;
      while (1) {
        n = 0;
        n += (*pcVar2 - 0x30) * 10;
        n += pcVar2[1] - 0x30;
        *param_3 = *param_3 | 1 << n;
        pcVar2++;
        iVar1 = FUN_00014d64(pcVar2, &DAT_002db130);
        if (iVar1 == 0) break;
        pcVar2 = iVar1 + 1;
      }
    }
    else if (FUN_00014d64(param_2, &DAT_002db134) != 0) {
      uVar3 = 5;
      iVar1 = FUN_00014d64(param_2, &DAT_002db134);
      n = 0;
      n += (iVar1[4] - 0x30) * 10;
      n += iVar1[5] - 0x30;
      *param_3 = n;
    }
    else if (FUN_00014d64(param_2, DAT_002db13c) != 0) {
      uVar3 = 6;
      iVar1 = FUN_00014d64(param_2, DAT_002db13c);
      n = 0;
      n += (iVar1[6] - 0x30) * 10;
      n += iVar1[7] - 0x30;
      *param_3 = n;
    }
    else if (FUN_00014d64(param_2, DAT_002db144) != 0) {
      uVar3 = 7;
    }
    else if (FUN_00014d64(param_2, DAT_002db150) != 0) {
      uVar3 = 8;
    }
    else if (FUN_00014d64(param_2, DAT_002db158) != 0) {
      uVar3 = 9;
    }
    else if (FUN_00014d64(param_2, DAT_002db01c) != 0) {
      uVar3 = 10;
      iVar1 = FUN_00014d64(param_2, DAT_002db01c);
      n = 0;
      n += (iVar1[10] - 0x30) * 100;
      n += (iVar1[0xb] - 0x30) * 10;
      n += iVar1[0xc] - 0x30;
      *param_3 = n;
    }
    else if (FUN_00014d64(param_2, DAT_002db164) != 0) {
      uVar3 = 0xc;
    }
    else if (FUN_00014d64(param_2, DAT_002db174) != 0) {
      uVar3 = 0xd;
    }
    else if (FUN_00014d64(param_2, DAT_002db180) != 0) {
      uVar3 = 0xe;
      iVar1 = FUN_00014d64(param_2, DAT_002db180);
      n = 0;
      n += (iVar1[0xb] - 0x30) * 100;
      n += (iVar1[0xc] - 0x30) * 10;
      n += iVar1[0xd] - 0x30;
      *param_3 = n;
    }
  }
  return uVar3;
}
