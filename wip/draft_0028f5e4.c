/* HSTMATCH module=EBOOT.BIN start=0x0028f5e4 end=0x0028fb44 symbol=FUN_0028f5e4 lang=c99 */
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

extern undefined DAT_002ff030;
extern undefined DAT_0034a80c;
extern char DAT_002ff03c[];
extern char DAT_002ff060[];
extern char DAT_002ff090[];
extern char DAT_002ff0b0[];
extern char DAT_002ff0d8[];
extern char DAT_002ff100[];
extern char DAT_002ff120[];
extern char DAT_002ff14c[];
extern char DAT_002ff168[];
extern char DAT_002ff190[];
extern char DAT_002ff1bc[];
extern char DAT_002ff1e8[];
extern char DAT_002ff1f4[];
extern char DAT_002ff220[];
extern char DAT_002ff238[];
extern char DAT_002ff25c[];
extern char DAT_002ff27c[];
extern char DAT_002ff2a8[];
extern char DAT_002ff2d0[];
extern char DAT_002ff300[];
extern char DAT_002ff320[];
extern char DAT_002ff34c[];
extern char DAT_002ff36c[];
extern int FUN_00010184();
extern void FUN_000104e0();
extern uint * FUN_000114c0();
extern undefined4 FUN_000613ec();
extern undefined4 FUN_0006151c();
extern undefined4 FUN_0006165c();
extern void FUN_0028fb44();
extern undefined4 FUN_00290288();
extern bool FUN_002903cc();
extern undefined4 FUN_002918f0();
extern int FUN_002b78d0();
extern int FUN_002b7970();
extern int FUN_002b7990();
extern int FUN_002b7a00();
extern int FUN_002b7a08();
extern int FUN_002b7c18();
extern int FUN_002b7cc0();
extern int FUN_002b7d48();
extern int FUN_002b7d50();
extern int FUN_002b7e80();
extern int FUN_002b7e88();
extern int FUN_002b7e98();
extern int FUN_002b7ea0();
extern int FUN_002b7ec0();

undefined4 FUN_0028f5e4(int param_1,undefined1 param_2)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_4;
  
  if (DAT_0034a80c != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x28) != '\0') {
    return 1;
  }
  FUN_0028fb44(DAT_002ff03c);
  *(undefined1 *)(param_1 + 0x1ec) = param_2;
  if (*(char *)(param_1 + 0x1ec) != '\0') {
    cVar1 = FUN_00290288();
    if (cVar1 == '\0') goto LAB_0028fb08;
    if (DAT_0034a80c != '\0') {
      FUN_0028fb44(DAT_002ff060);
      goto LAB_0028fb08;
    }
  }
  FUN_0006165c();
  iVar2 = FUN_000613ec();
  if (iVar2 == 0) {
    iVar2 = FUN_0006151c(0,0x800);
    if (iVar2 == 0) {
      iVar2 = FUN_002b7c18(0x303);
      if (iVar2 < 0) {
        FUN_0028fb44(DAT_002ff0d8,iVar2);
      }
      else {
        iVar2 = FUN_002b7d48();
        if (iVar2 == 0) {
          if (DAT_0034a80c == '\0') {
            *(undefined4 *)(param_1 + 8) = 0x300000;
            iVar2 = FUN_002b7990();
            *(int *)(param_1 + 0xc) = iVar2 + 2;
            iVar2 = FUN_002b7a00(0,&local_4,param_1 + 8);
            if (iVar2 < 0) {
              FUN_0028fb44(DAT_002ff120,iVar2);
            }
            else if (*(uint *)(param_1 + 8) < 0x300000) {
              FUN_0028fb44(DAT_002ff14c);
            }
            else {
              *(undefined4 *)(param_1 + 4) = local_4;
              iVar2 = FUN_002b7e88(param_1,param_1 + 4);
              if (iVar2 == 0) {
                if (*(int *)(param_1 + 0xe4) != 0) {
                  FUN_000104e0();
                  *(undefined4 *)(param_1 + 0xe4) = 0;
                }
                uVar3 = FUN_00010184(0x40,0x10000);
                *(undefined4 *)(param_1 + 0xe4) = uVar3;
                iVar2 = FUN_002b7e98(param_1,uVar3,0x10000);
                if (iVar2 < 0) {
                  FUN_0028fb44(DAT_002ff190,iVar2);
                }
                else {
                  uVar3 = FUN_002b7ea0(param_1);
                  *(undefined4 *)(param_1 + 0xdc) = uVar3;
                  uVar4 = 0;
                  iVar2 = param_1;
                  do {
                    if (*(int *)(iVar2 + 0xd4) == 0) {
                      uVar3 = *(undefined4 *)(param_1 + 0xdc);
                    }
                    else {
                      FUN_000104e0();
                      *(undefined4 *)(iVar2 + 0xd4) = 0;
                      uVar3 = *(undefined4 *)(param_1 + 0xdc);
                    }
                    uVar3 = FUN_00010184(0x40,uVar3);
                    *(undefined4 *)(iVar2 + 0xd4) = uVar3;
                    FUN_000114c0(uVar3,0,*(undefined4 *)(param_1 + 0xdc));
                    uVar4 = uVar4 + 1;
                    iVar2 = iVar2 + 4;
                  } while (uVar4 < 2);
                  iVar2 = FUN_002b7e80(param_1,0,1);
                  if (iVar2 == 0) {
                    iVar2 = FUN_002b7e80(param_1,1,3);
                    if (iVar2 == 0) {
                      iVar2 = FUN_002b7970(DAT_002ff1e8,2,0,0x100,0);
                      *(int *)(param_1 + 0x88) = iVar2;
                      if (iVar2 < 0) {
                        FUN_0028fb44(DAT_002ff1f4,0);
                      }
                      else {
                        iVar2 = FUN_002b7990();
                        cVar1 = FUN_002918f0(param_1 + 0x34,DAT_002ff220,
                                             param_1,&DAT_002ff030,iVar2 + 3,0x800,0);
                        if (cVar1 == '\0') {
                          FUN_0028fb44(DAT_002ff238);
                          uVar3 = *(undefined4 *)(param_1 + 0x88);
                        }
                        else {
                          if (*(int *)(param_1 + 0x2c) != 0) {
                            FUN_000104e0();
                            *(undefined4 *)(param_1 + 0x2c) = 0;
                          }
                          uVar3 = FUN_00010184(0x40,0x88000);
                          *(undefined4 *)(param_1 + 0x2c) = uVar3;
                          if (DAT_0034a80c == '\0') {
                            FUN_0028fb44(DAT_002ff25c);
                            *(undefined4 *)(param_1 + 0xe8) = 0;
                            *(undefined4 *)(param_1 + 0xe0) = 0;
                            *(undefined1 *)(param_1 + 0x29) = 0;
                            *(undefined1 *)(param_1 + 0x28) = 1;
                            *(undefined1 *)(param_1 + 0x2a) = 0;
                            return 1;
                          }
                          FUN_0028fb44(DAT_002ff060);
                          uVar3 = *(undefined4 *)(param_1 + 0x88);
                        }
                        iVar2 = FUN_002b78d0(uVar3);
                        if (iVar2 != 0) {
                          FUN_0028fb44(DAT_002ff27c,iVar2);
                        }
                      }
                    }
                    else {
                      FUN_0028fb44(DAT_002ff1bc,iVar2);
                    }
                  }
                  else {
                    FUN_0028fb44(DAT_002ff1bc,iVar2);
                  }
                  uVar4 = 0;
                  iVar2 = param_1;
                  do {
                    if (*(int *)(iVar2 + 0xd4) != 0) {
                      FUN_000104e0();
                      *(undefined4 *)(iVar2 + 0xd4) = 0;
                    }
                    uVar4 = uVar4 + 1;
                    iVar2 = iVar2 + 4;
                  } while (uVar4 < 2);
                  if (*(int *)(param_1 + 0xe4) != 0) {
                    FUN_000104e0();
                    *(undefined4 *)(param_1 + 0xe4) = 0;
                  }
                }
                iVar2 = FUN_002b7ec0(param_1);
                if (iVar2 != 0) {
                  FUN_0028fb44(DAT_002ff2a8,iVar2);
                }
              }
              else {
                FUN_0028fb44(DAT_002ff168,iVar2);
              }
              iVar2 = FUN_002b7a08(0);
              if (iVar2 < 0) {
                FUN_0028fb44(DAT_002ff2d0,iVar2);
              }
            }
            iVar2 = FUN_002b7d50();
            if (iVar2 != 0) {
              FUN_0028fb44(DAT_002ff300,iVar2);
            }
          }
          else {
            FUN_0028fb44(DAT_002ff060);
          }
        }
        else {
          FUN_0028fb44(DAT_002ff100,iVar2);
        }
        iVar2 = FUN_002b7cc0(0x303);
        if (iVar2 < 0) {
          FUN_0028fb44(DAT_002ff320,iVar2);
        }
      }
    }
    else {
      FUN_0028fb44(DAT_002ff0b0,iVar2);
    }
    iVar2 = FUN_0006165c();
    if (iVar2 != 0) {
      FUN_0028fb44(DAT_002ff34c,iVar2);
    }
    cVar1 = *(char *)(param_1 + 0x1ec);
  }
  else {
    FUN_0028fb44(DAT_002ff090,iVar2);
    cVar1 = *(char *)(param_1 + 0x1ec);
  }
  if (cVar1 != '\0') {
    FUN_002903cc();
  }
LAB_0028fb08:
  FUN_0028fb44(DAT_002ff36c);
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  return 0;
}
// near miss from lane fm11 (unreviewed)
