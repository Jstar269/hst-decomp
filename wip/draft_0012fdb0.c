/* HSTMATCH module=EBOOT.BIN start=0x0012fdb0 end=0x0012ffac symbol=FUN_0012fdb0 lang=c99 */
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

extern char DAT_002daf5c[];
extern char DAT_002daf68[];
extern char DAT_002daf74[];
extern char DAT_002daf84[];
extern char DAT_002daf90[];
extern char DAT_002daf9c[];
extern char DAT_002dafa8[];
extern char DAT_002dafb4[];
extern char DAT_002dafc0[];
extern char DAT_002dafd0[];
extern char DAT_002dafe0[];
extern char DAT_002dafe8[];
extern char DAT_002daff4[];
extern char DAT_002db004[];
extern char DAT_002db014[];
extern char DAT_002db01c[];
extern char * FUN_00014d64();

undefined4 FUN_0012fdb0(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf5c));
    if (iVar1 == 0) {
      iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf68));
      if (iVar1 == 0) {
        iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf74));
        if (iVar1 == 0) {
          iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf84));
          if (iVar1 == 0) {
            iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf90));
            if (iVar1 == 0) {
              iVar1 = (int)(FUN_00014d64(param_2,DAT_002daf9c));
              if (iVar1 == 0) {
                iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafa8));
                if (iVar1 == 0) {
                  iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafb4));
                  if (iVar1 == 0) {
                    iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafc0));
                    if (iVar1 == 0) {
                      iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafd0));
                      if (iVar1 == 0) {
                        iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafe0));
                        if (iVar1 == 0) {
                          iVar1 = (int)(FUN_00014d64(param_2,DAT_002dafe8));
                          if (iVar1 == 0) {
                            iVar1 = (int)(FUN_00014d64(param_2,DAT_002daff4));
                            if (iVar1 == 0) {
                              iVar1 = (int)(FUN_00014d64(param_2,DAT_002db004));
                              if (iVar1 == 0) {
                                iVar1 = (int)(FUN_00014d64(param_2,DAT_002db014));
                                if (iVar1 == 0) {
                                  iVar1 = (int)(FUN_00014d64(param_2,DAT_002db01c));
                                  if (iVar1 != 0) {
                                    uVar2 = 0xf;
                                  }
                                }
                                else {
                                  uVar2 = 0xe;
                                }
                              }
                              else {
                                uVar2 = 0xd;
                              }
                            }
                            else {
                              uVar2 = 0xc;
                            }
                          }
                          else {
                            uVar2 = 0xb;
                          }
                        }
                        else {
                          uVar2 = 10;
                        }
                      }
                      else {
                        uVar2 = 9;
                      }
                    }
                    else {
                      uVar2 = 8;
                    }
                  }
                  else {
                    uVar2 = 7;
                  }
                }
                else {
                  uVar2 = 6;
                }
              }
              else {
                uVar2 = 5;
              }
            }
            else {
              uVar2 = 4;
            }
          }
          else {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}
// near miss from lane fm9 (unreviewed)
