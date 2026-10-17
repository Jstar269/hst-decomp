/* HSTMATCH module=EBOOT.BIN start=0x0011a078 end=0x0011a16c symbol=FUN_0011a078 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected helper prototypes and argument order, index arithmetic, and switch layout; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00338c20;
extern undefined1 FUN_00057b58(int, float, int, int);
extern void FUN_00058ddc(int, int, int);
extern void FUN_00058ec4(int, float, int);
extern void FUN_00058f38(int, float, int);
extern void FUN_00059084(int, int);
extern void FUN_000fb544();

void FUN_0011a078(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_2 * 4;
  iVar1 += param_1;
  puVar2 = (undefined4 *)(iVar1 + 0x48);
  FUN_00057b58(*puVar2,0.0f,0,0);
  FUN_00058f38(*puVar2,0.0f,0xffffffff);
  FUN_00058ec4(*puVar2,1.0f,0xffffffff);
  FUN_00058ddc(*puVar2,0,0xffffffff);
  FUN_00059084(*puVar2,0xffffffff);
  *(undefined1 *)(param_2 + param_1 + 0xb4) = 1;
  switch (param_2) {
  case 9:
  case 1:
  case 5:
  case 0x11:
  case 0xb:
    *(undefined1 *)(param_1 + 0x44) = 1;
    FUN_000fb544(DAT_00338c20);
    break;
  default:
    break;
  }
  return;
}
