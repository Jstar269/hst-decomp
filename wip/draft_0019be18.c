/* HSTMATCH module=EBOOT.BIN start=0x0019be18 end=0x0019c340 symbol=FUN_0019be18 lang=c99 rodata=0x002c1880 */
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

extern undefined4 DAT_0034a81c;
extern void FUN_00051490();
extern void FUN_0005185c();
extern void FUN_00051894();
extern void FUN_00059174();
extern void FUN_0005f0d8();
extern void FUN_0005f110(float, int);
extern void FUN_0005f1e8();
extern void FUN_001031e8();
extern void FUN_0019ab34();
extern void FUN_002917ac();

void FUN_0019be18(int param_1)
{
  int iVar1;
  int iVar2;
  
  switch(*(undefined4 *)(param_1 + 0x90)) {
  case 0:
  case 0x12:
  case 0x13:
    break;
  case 1:
  case 2:
    FUN_00051490(*(int *)(param_1 + 0x54),0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0,0x43f00000,0x43880000,0x43f00000,0x43880000,*(int *)(param_1 + 0x54),
                 0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54));
    FUN_00051490(*(int *)(param_1 + 0x54) + 0x48,0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0x43700000,0x43f00000,0x42000000,0x43f00000,0x43880000,
                 *(int *)(param_1 + 0x54) + 0x48,0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54) + 0x48);
    FUN_001031e8(param_1);
    return;
  case 3:
    iVar2 = *(int *)(param_1 + 0x8c);
    iVar1 = *(int *)(param_1 + 100);
    FUN_00059174(iVar2);
    FUN_0005f0d8(iVar2);
    FUN_0005f110((float)((float)iVar1),(int)(*(int *)(param_1 + 0x8c)));
    *(float *)(*(int *)(param_1 + 0x8c) + 0x80) = (float)iVar1;
    FUN_0005f1e8(*(int **)(param_1 + 0x8c),0);
    FUN_00051490(*(int *)(param_1 + 0x54),0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0,0x43f00000,0x43880000,0x43f00000,0x43880000,*(int *)(param_1 + 0x54),
                 0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54));
    FUN_00051490(*(int *)(param_1 + 0x54) + 0x48,0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0x43700000,0x43f00000,0x42000000,0x43f00000,0x43880000,
                 *(int *)(param_1 + 0x54) + 0x48,0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54) + 0x48);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x11:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
    iVar2 = *(int *)(param_1 + 0x8c);
    iVar1 = *(int *)(param_1 + 100);
    FUN_00059174(iVar2);
    FUN_0005f0d8(iVar2);
    FUN_0005f110((float)((float)iVar1),(int)(*(int *)(param_1 + 0x8c)));
    *(float *)(*(int *)(param_1 + 0x8c) + 0x80) = (float)iVar1;
    FUN_0005f1e8(*(int **)(param_1 + 0x8c),0);
    FUN_00051490(*(int *)(param_1 + 0x54),0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0,0x43f00000,0x43880000,0x43f00000,0x43880000,*(int *)(param_1 + 0x54),
                 0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54));
    FUN_00051490(*(int *)(param_1 + 0x54) + 0x48,0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0x43700000,0x43f00000,0x42000000,0x43f00000,0x43880000,
                 *(int *)(param_1 + 0x54) + 0x48,0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54) + 0x48);
    FUN_001031e8(param_1);
    break;
  case 0xf:
  case 0x10:
    if (DAT_0034a81c != 0) {
      FUN_002917ac(DAT_0034a81c);
    }
    break;
  default:
    FUN_0019ab34();
    break;
  case 0x16:
    iVar2 = *(int *)(param_1 + 0x8c);
    iVar1 = *(int *)(param_1 + 100);
    FUN_00059174(iVar2);
    FUN_0005f0d8(iVar2);
    FUN_0005f110((float)((float)iVar1),(int)(*(int *)(param_1 + 0x8c)));
    *(float *)(*(int *)(param_1 + 0x8c) + 0x80) = (float)iVar1;
    FUN_0005f1e8(*(int **)(param_1 + 0x8c),0);
    FUN_00051490(*(int *)(param_1 + 0x54),0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0,0x43f00000,0x43880000,0x43f00000,0x43880000,*(int *)(param_1 + 0x54),
                 0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54));
    FUN_00051490(*(int *)(param_1 + 0x54) + 0x48,0,0,0x1e0,0x110,0,(int *)0x0);
    FUN_00051894(0,0,0,0x43700000,0x43f00000,0x42000000,0x43f00000,0x43880000,
                 *(int *)(param_1 + 0x54) + 0x48,0x80808080);
    FUN_0005185c(*(int *)(param_1 + 0x54) + 0x48);
    FUN_001031e8(param_1);
  case 0x17:
    (**(code **)(*(int *)(param_1 + 0xa0) + 0x14))(param_1 + 0xa0);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
