/* HSTMATCH module=EBOOT.BIN start=0x00000c7c end=0x00000e9c symbol=FUN_00000c7c lang=c99 */
int FUN_00000c7c(char *param_1, char *param_2, int *param_3)
{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;

  *param_3 = 0;
  if (param_2 == (char *)0x0) {
    return 1;
  }
  if (*param_2 == 'P') {
    pcVar1 = param_2 + 1;
    if (*pcVar1 == 'C') {
      pcVar1 = param_2 + 2;
      cVar5 = *pcVar1;
    } else {
      cVar5 = *pcVar1;
    }
    if (cVar5 == 'V') {
      cVar5 = pcVar1[1];
    } else {
      cVar5 = *pcVar1;
    }
    if (cVar5 == 'v') {
      if (*param_1 == 'P') {
        return 1;
      }
      if (*param_1 == '*') {
        return 1;
      }
    }
    cVar5 = *param_1;
  } else {
    cVar5 = *param_1;
  }
  if (cVar5 == '!') {
    cVar5 = *param_1;
  } else {
    if (cVar5 != '*') {
      cVar5 = *param_1;
      while (1) {
        if (cVar5 == 'P') {
          cVar2 = *param_2;
        } else {
          if (cVar5 != 'R') {
            cVar2 = *param_2;
            goto LAB_00000e64;
          }
          cVar2 = *param_2;
        }
        if (cVar5 != cVar2) {
          break;
        }
        pcVar3 = param_1 + 1;
        pcVar1 = param_2 + 1;
        if (param_2[1] == 'C') {
          if (*pcVar3 == 'C') {
            pcVar1 = param_2 + 2;
            pcVar3 = param_1 + 2;
          } else {
            pcVar1 = param_2 + 2;
          }
        }
        param_1 = pcVar3;
        param_2 = pcVar1;
        if (*param_1 == 'C') {
          return 0;
        }
        if (*param_2 == 'V') {
          if (*param_1 == 'V') {
            param_1 = param_1 + 1;
          }
          param_2 = param_2 + 1;
          cVar5 = *param_1;
        } else {
          cVar5 = *param_1;
        }
        if (cVar5 == 'V') {
          return 0;
        }
        cVar5 = *param_1;
      }
      cVar2 = *param_2;
LAB_00000e64:
      if (cVar5 != cVar2) {
        return 0;
      }
      do {
        if (cVar5 == '\0') {
          return 1;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        cVar5 = *param_1;
      } while (cVar5 == *param_2);
      return 0;
    }
    cVar5 = *param_1;
  }
  param_1 = param_1 + 1;
  pcVar1 = param_2 + 1;
  if (cVar5 != *param_2) {
    return 0;
  }
  while (1) {
    while (1) {
      cVar5 = *pcVar1;
      cVar2 = *param_1;
      pcVar1 = pcVar1 + 1;
      if (cVar2 != cVar5) {
        break;
      }
      param_1 = param_1 + 1;
      if (cVar2 == '!') {
        iVar4 = 0;
        cVar5 = *param_1;
        while (cVar5 != '!') {
          iVar4 = (int)cVar5 + iVar4 * 10 + -0x30;
          param_1 = param_1 + 1;
          cVar5 = *param_1;
        }
        *param_3 = iVar4;
        return 1;
      }
    }
    do {
      cVar5 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar5 != '!');
    do {
      cVar5 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar5 != '!');
    if (*param_1 == '\0') {
      break;
    }
    pcVar1 = param_2 + 1;
  }
  return 0;
}
// NEAR MISS: 143/136 words, 140 differ. Ghidra's control-flow rendering does not
// reproduce retail's block layout; retail is MWCC (signed char loads `lb`, branch-likely
// `bnel`/`beql`, no `seb`), so the GCC draft (136 words but 131 differ) is not the
// right toolchain either. Retail blocks (function base 0xc7c):
//   0xc7c  *out = 0; if (str != 0) goto 0xc90;  (delay: v0 = str)
//   0xc90  if (*str != 'P') goto 0xd0c            (the "PC"/"PCV"/"PCv" prefix check)
//   0xca0  p = str+1; if (p[0] != 'C') goto 0xcbc; else p = str+2
//   0xcbc  if (*p != 'V') goto 0xcd0; else p = str+3, c = p[0]
//   0xcd0  if (c != 'v') goto 0xd08; else if (*pat == 'P' || *pat == '*') return 1
//   0xd0c  if (*pat == '!') goto 0xd3c; if (*pat == '*') goto 0xd38; else the
//          'P'/'R'/'C'/'V' compare loop at 0xe40
//   0xd3c  the plain character compare loop; on '!' it parses the decimal number
//          between the two '!' into *out and returns 1
// Ruled out: the Ghidra pseudocode spelled verbatim (140 differ), the generated GCC
// draft under every gcc131/171 profile (-O1/-O2/-O3/-Os, 131-135 differ).
// near miss from lane om1 (unreviewed)
