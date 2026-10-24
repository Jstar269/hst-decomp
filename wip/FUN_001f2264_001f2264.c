/* HSTMATCH module=EBOOT.BIN start=0x001f2264 end=0x001f25a4 symbol=FUN_001f2264 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern char DAT_003418bc[];
extern char *DAT_003415ac;
extern char *DAT_00331b84;
extern int DAT_003415d4;

extern void FUN_001e7bc0();
extern void FUN_001fa35c();
extern void FUN_001faa10();
extern void FUN_001f3770();
extern void FUN_001ff668();
extern void FUN_001e1614();
extern void FUN_001905b8();
extern void FUN_001f4bbc();
extern void FUN_001e075c();
extern void FUN_00216de0();
extern void FUN_00063c14();
extern void FUN_001f41e8();
extern void FUN_001e09dc();
extern void FUN_001e2668();
extern void FUN_001e7c3c();
extern int FUN_00190724();
extern void FUN_00063b20();
extern void FUN_001f4bfc();
extern void FUN_001f483c();

void FUN_001f2264(int param_1)
{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;

  if (*(int *)(param_1 + 0x44) == 0) {
    FUN_001e7bc0(*(undefined4 *)(param_1 + 0x510));
    cVar1 = DAT_003418bc[*(int *)(param_1 + 0x3cc) * 0x120];
    if (cVar1 != '\0') {
      cVar2 = *(char *)(param_1 + 0x5a2);
    }
    else {
      FUN_001fa35c(param_1);
      FUN_001faa10(param_1);
      cVar2 = *(char *)(param_1 + 0x5a2);
    }
    if ((cVar2 != '\0') || (cVar1 != '\0')) {
      FUN_001f3770(param_1);
      *(undefined4 *)(param_1 + 0x819c) = 2;
      *(undefined4 *)(param_1 + 0x81a0) = 0;
    }
    else {
      FUN_001ff668();
      FUN_001e1614(*(undefined4 *)(param_1 + 0x510));
      FUN_001905b8(DAT_003415d4, 3);
      FUN_001ff668();
      iVar4 = (int)DAT_003415ac;
      *(undefined4 *)(**(int **)(iVar4 + 4) + 0x60) = 0x43700000;
      *(undefined4 *)(**(int **)(iVar4 + 4) + 100) = 0x43280000;
      *(undefined4 *)(param_1 + 0x819c) = 0;
      *(undefined4 *)(param_1 + 0x81a0) = 0;
    }
  }
  iVar4 = *(int *)(param_1 + 0x819c);
  if (iVar4 == 3) {
    *(int *)(param_1 + 0x81a0) = *(int *)(param_1 + 0x81a0) + 1;
    if ((*(float *)(DAT_00331b84 + 0xc) == 0.0f) && (6 < *(int *)(param_1 + 0x81a0))) {
      FUN_001f4bbc(param_1);
      FUN_001e075c(*(undefined4 *)(param_1 + 0x510));
      *(undefined1 *)(*(int *)(param_1 + 0x584) + 0x98) = 1;
      FUN_001f3770(param_1);
      FUN_00216de0(*(undefined4 *)(param_1 + 0x560));
      FUN_001ff668();
      *(undefined4 *)(param_1 + 0x819c) = 2;
      *(undefined4 *)(param_1 + 0x81a0) = 0;
      FUN_00063c14(0x477fff00, DAT_00331b84, 5);
      FUN_001f41e8(param_1);
      FUN_001e09dc(*(undefined4 *)(param_1 + 0x510), 2);
      FUN_001e2668(*(undefined4 *)(param_1 + 0x510));
      FUN_001e7c3c(*(undefined4 *)(param_1 + 0x510));
    }
  }
  else if (iVar4 != 2) {
    if (iVar4 == 1) {
      iVar3 = FUN_00190724(DAT_003415d4);
      iVar4 = (int)DAT_003415ac;
      if (iVar3 != 0) {
        if (DAT_003415ac == 0) {
          cVar1 = *(char *)(param_1 + 0x5a0);
        }
        else {
          *(undefined4 *)(iVar4 + 0x74) = 0x3f800000;
          *(undefined4 *)(iVar4 + 0x78) = 0x3f800000;
          iVar4 = (int)DAT_003415ac;
          *(undefined4 *)(**(int **)(iVar4 + 4) + 0x60) = 0x43700000;
          *(undefined4 *)(**(int **)(iVar4 + 4) + 100) = 0x43080000;
          cVar1 = *(char *)(param_1 + 0x5a0);
        }
        if ((cVar1 == '\0') && (*(char *)(param_1 + 0x5a1) == '\0')) {
          FUN_001f3770(param_1);
          *(undefined4 *)(param_1 + 0x819c) = 2;
          *(undefined4 *)(param_1 + 0x81a0) = 0;
        }
        else {
          FUN_00063b20(0x477fff00, DAT_00331b84, 5);
          *(undefined4 *)(param_1 + 0x819c) = 3;
          *(undefined4 *)(param_1 + 0x81a0) = 0;
        }
      }
    }
    else if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x819c) = 1;
      *(undefined4 *)(param_1 + 0x81a0) = 0;
    }
  }
  FUN_001f4bfc(param_1);
  FUN_001f483c(param_1);
  return;
}
// near miss from lane fm10 (unreviewed)
