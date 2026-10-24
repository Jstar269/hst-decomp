/* HSTMATCH module=EBOOT.BIN start=0x00124274 end=0x0012441c symbol=FUN_00124274 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern int FUN_000de208(int, int);
extern int FUN_001252fc(int, int);
extern int DAT_00338b44;
extern int DAT_0033b494;
extern int DAT_002da1a0;
extern int DAT_002da1a8;
extern char DAT_0033b5d4[];
extern int DAT_0033b5c4;

void FUN_00124274(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  iVar4 = FUN_000de208(DAT_00338b44, 0xffffffff);
  if (iVar4 == 0) {
    cVar1 = *(char *)(param_1 + 0x79);
  }
  else {
    *(undefined1 *)(param_1 + 0x79) = 0;
    cVar1 = *(char *)(param_1 + 0x79);
  }
  iVar4 = DAT_0033b494;
  iVar6 = DAT_002da1a0;
  if (cVar1 == '\0') {
    do {
      while (1) {
        do {
          iVar4 = iVar4 + 1;
          iVar2 = DAT_002da1a0;
          iVar5 = DAT_002da1a8;
          iVar3 = DAT_0033b494;
          if (0xe0 < iVar4) {
            goto LAB_001243f4;
          }
        } while (iVar4 < 0);
        if (iVar4 != 0xe0) {
          break;
        }
        iVar4 = -1;
      }
    } while ((((char *)DAT_0033b5d4)[iVar4 * 0x58] != '\x03') ||
             (*(int *)((char *)DAT_0033b5c4 + iVar4 * 0x58) < 1) ||
             ((iVar5 = FUN_001252fc(param_1, iVar4), iVar2 = DAT_002da1a0, iVar3 = iVar4, iVar5 < 0)));
  }
  else {
    iVar6 = DAT_002da1a0;
    do {
      while (1) {
        do {
          iVar6 = iVar6 + 1;
          iVar2 = DAT_002da1a0;
          iVar5 = DAT_002da1a8;
          iVar3 = DAT_0033b494;
          if (0xe0 < iVar6) {
            goto LAB_001243f4;
          }
        } while (iVar6 < 0);
        if (iVar6 != 0xe0) {
          break;
        }
        iVar6 = -1;
      }
    } while ((((char *)DAT_0033b5d4)[iVar6 * 0x58] != '\x02') ||
             (*(int *)((char *)DAT_0033b5c4 + iVar6 * 0x58) < 1) ||
             ((iVar5 = FUN_001252fc(param_1, iVar6), iVar2 = iVar6, iVar3 = DAT_0033b494, iVar5 < 0)));
  }
LAB_001243f4:
  DAT_0033b494 = iVar3;
  DAT_002da1a8 = iVar5;
  DAT_002da1a0 = iVar2;
  if (-1 < DAT_002da1a8) {
    *(int *)(param_1 + 0x58) = DAT_002da1a8;
  }
  return;
}
// NEAR (120/106). The two mirrored scan loops are transcribed literally from Ghidra; the delta is one
// extra saved register (s2) and the wrap `if (i != 0xe0) i = -1;` layout - the same "id-lookup
// family" blocker recorded for 0x001514dc / 0x0014fbd4 in PROGRESS.md: retail computes the element
// address (sll/addu chain for i*0x58) BEFORE the `iVar < 0` test, so the wrap test lands in the
// `bnel s0,0xe0` slot, while MWCC emits the value test first from any of the source spellings tried.
// Note `DAT_0033b5d4` / `DAT_0033b5c4` need casts (`((char *)DAT_0033b5d4)[i*0x58]`), an array symbol
// subscripted directly is a `char (*)[]` + int error in this C front end.
// near miss from lane fm8 (unreviewed)
