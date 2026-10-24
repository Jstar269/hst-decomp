/* HSTMATCH module=EBOOT.BIN start=0x0012a254 end=0x0012a5cc rodata=0x002c14a4 symbol=FUN_0012a254 lang=c99 */
typedef unsigned int undefined4;

extern int DAT_0033b4f0[];
extern int DAT_0033b518[];
extern int DAT_0033b528[];
extern int DAT_0033b550[];
extern int DAT_0033b554[];
extern int DAT_0033b558[];
extern int DAT_0033b55c[];
extern int DAT_0033b560[];
extern int DAT_0033b4bc[];
extern int DAT_0033b4b8[];

extern void FUN_00057b58();
extern void FUN_0012b2b0();
extern int FUN_0012b72c();
extern void FUN_0012ad54();
extern void FUN_0012b360();
extern void FUN_0012b3d4();

void FUN_0012a254(int param_1, int param_2, int param_3, int param_4)
{
  int iVar1;

  if ((*(int *)(param_1 + 400) != param_2) || (param_4 != 0)) {
    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 400);
    *(int *)(param_1 + 400) = param_2;
    *(undefined4 *)(param_1 + 0x250) = 0;
    switch (param_2) {
    case 0:
      if ((param_4 != 0) && (*(int *)(param_1 + 0x58) != 0)) {
        FUN_00057b58(0, *(int *)(param_1 + 0x58), 0, 0xffffffff);
      }
      FUN_0012b2b0(0xbf800000, param_1, 1, param_3 == 0);
      break;
    case 1:
      iVar1 = FUN_0012b72c(param_1, *(undefined4 *)(param_1 + 0x35c), param_2);
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b4f0 + *(int *)(param_1 + 0x358) * 3 + iVar1,
                   1, 0, 1, 1);
      break;
    case 2:
      iVar1 = FUN_0012b72c(param_1, *(undefined4 *)(param_1 + 0x35c), param_2);
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b518 + iVar1, 1, 0, 1, 1);
      break;
    case 3:
      iVar1 = FUN_0012b72c(param_1, *(undefined4 *)(param_1 + 0x35c), param_2);
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b528 + iVar1, 1, 0, 1, 1);
      break;
    case 4:
      FUN_0012b360(param_1, 1);
      break;
    case 5:
      FUN_0012b3d4(param_1, 1);
      break;
    case 6:
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b550 + param_3, 5 < param_3, 0, 1, 1);
      break;
    case 7:
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b554 + param_3, param_3 == 4, 0, 1, 1);
      break;
    case 8:
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b558 + param_3, param_3 != 1, 0, 1, 1);
      break;
    case 9:
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b55c + param_3, 3 < param_3, 0, 1, 1);
      break;
    case 10:
      FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b560 + param_3, param_3 < 2, 0, 1, 1);
      break;
    case 0xb:
      FUN_0012b3d4(param_1, 1);
      break;
    case 0xc:
      FUN_0012b3d4(param_1, 1);
      break;
    case 0xd:
      iVar1 = FUN_0012b72c(param_1, *(undefined4 *)(param_1 + 0x35c), 0);
      if ((iVar1 == 3) && (*(int *)(param_1 + 0x354) == 1)) {
        FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b4bc, 1, 0, 1, 1);
      }
      else {
        FUN_0012ad54(0xbf800000, param_1, (int)DAT_0033b4b8, 1, 0, 1, 1);
      }
    }
  }
  return;
}
// near miss from lane fm10 (unreviewed)
