/* HSTMATCH module=EBOOT.BIN start=0x000f0e94 end=0x000f1090 symbol=FUN_000f0e94 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_002d74f8;
extern int DAT_002d7548;
extern undefined4 DAT_00338b44;
extern undefined4 FUN_000de2c8();
extern undefined4 FUN_000de3f0();
extern int FUN_000de51c();
extern int FUN_000dea20();
extern undefined4 FUN_000def0c();
extern void FUN_000ffb3c();

void FUN_000f0e94(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  register undefined4 *puVar3;
  int iVar4;
  register int iVar5;
  
  *(undefined4 *)(param_1 + 0x98) = param_2;
  *(undefined4 *)(param_1 + 0x9c) = param_3;
  puVar3 = (unsigned int *)(&DAT_002d74f8);
  iVar4 = param_1;
  iVar5 = 0;
  do {
    iVar1 = FUN_000def0c(DAT_00338b44);
    if (iVar1 != 0) {
      FUN_000ffb3c(*(undefined4 *)(iVar4 + 0x68),1);
      FUN_000ffb3c(*(undefined4 *)(iVar4 + 0x70),0);
      iVar1 = *(int *)(iVar4 + 0x70);
      iVar2 = *(int *)(iVar4 + 0x98) + puVar3[0xb];
      *(int *)(iVar1 + 0x24) = iVar2;
      *(int *)(iVar1 + 0x28) = iVar2;
    
    }
    else {
      FUN_000ffb3c(*(undefined4 *)(iVar4 + 0x70),1);
      FUN_000ffb3c(*(undefined4 *)(iVar4 + 0x68),0);
      iVar1 = *(int *)(iVar4 + 0x68);
      iVar2 = *(int *)(iVar4 + 0x98) + puVar3[5];
      *(int *)(iVar1 + 0x24) = iVar2;
      *(int *)(iVar1 + 0x28) = iVar2;
    
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 4;
    puVar3 = puVar3 + 3;
  } while (iVar5 < 2);
  FUN_000ffb3c(*(undefined4 *)(param_1 + 0x7c),0);
  *(undefined1 *)(param_1 + 0xa0) = 1;
  iVar4 = FUN_000dea20(DAT_00338b44,0xffffffff);
  if (iVar4 == 0) {
    iVar4 = FUN_000de51c(DAT_00338b44,0xffffffff);
    if (iVar4 == 0) {
      iVar4 = FUN_000de2c8(DAT_00338b44,0xffffffff);
      if ((iVar4 == 0) && (iVar4 = FUN_000de3f0(DAT_00338b44,0xffffffff), iVar4 == 0)) {
        iVar4 = FUN_000def0c(DAT_00338b44);
        if (iVar4 == 0) {
          FUN_000ffb3c(*(undefined4 *)(param_1 + 0x7c),1);
          *(undefined1 *)(param_1 + 0xa0) = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x7c);
          iVar5 = DAT_002d7548 + 3;
          *(int *)(iVar4 + 0x24) = iVar5;
          *(int *)(iVar4 + 0x28) = iVar5;
        }
      }
      else {
        iVar4 = DAT_002d7548;
        iVar5 = *(int *)(param_1 + 0x7c);
        *(int *)(iVar5 + 0x24) = DAT_002d7548;
        *(int *)(iVar5 + 0x28) = iVar4;
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0x7c);
      iVar5 = DAT_002d7548 + 1;
      *(int *)(iVar4 + 0x24) = iVar5;
      *(int *)(iVar4 + 0x28) = iVar5;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x7c);
    iVar5 = DAT_002d7548 + 2;
    *(int *)(iVar4 + 0x24) = iVar5;
    *(int *)(iVar4 + 0x28) = iVar5;
  }
  (**(code **)(**(int **)(param_1 + 0x5c) + 0xc))
            (*(int **)(param_1 + 0x5c),*(char *)(param_1 + 0xa0) == '\0');
  (**(code **)(**(int **)(param_1 + 0x60) + 0xc))(*(int **)(param_1 + 0x60),1);
  return;
}
// near miss from lane km4 (unreviewed)
