/* HSTMATCH module=EBOOT.BIN start=0x00187308 end=0x00187424 symbol=FUN_00187308 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512b) corrected by hand: the object parameter typed char * (pointer arithmetic, as struct member addresses compile); exact match verified; names and types await human review. */
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

extern undefined DAT_002e09c8;
extern char DAT_002e092c[];
extern char DAT_002e093c[];
extern char DAT_002e094c[];
extern char DAT_002e099c[];
extern char DAT_002e09cc[];
extern char DAT_002e09f8[];
extern void FUN_000143b0();
extern undefined4 FUN_000ff7d8();
extern void FUN_000ff98c();

void FUN_00187308(char *param_1)
{
  int iVar1;
  undefined1 auStack_100 [256];
  undefined1 auStack_180 [128];
  
  FUN_000143b0(auStack_100,DAT_002e099c,0);
  FUN_000143b0(auStack_180,DAT_002e092c,0);
  iVar1 = FUN_000ff7d8(param_1 + 0x2928,auStack_100,1,&DAT_002e09c8);
  if (iVar1 != 0) {
    FUN_000ff98c(auStack_180,param_1 + 0x2928);
  }
  FUN_000143b0(auStack_100,DAT_002e09cc,0);
  FUN_000143b0(auStack_180,DAT_002e093c,0);
  iVar1 = FUN_000ff7d8(param_1 + 0x28b0,auStack_100,1,&DAT_002e09c8);
  if (iVar1 != 0) {
    FUN_000ff98c(auStack_180,param_1 + 0x28b0);
  }
  FUN_000143b0(auStack_100,DAT_002e09f8,0);
  FUN_000143b0(auStack_180,DAT_002e094c,0);
  iVar1 = FUN_000ff7d8(param_1 + 0x29a0,auStack_100,1,&DAT_002e09c8);
  if (iVar1 != 0) {
    FUN_000ff98c(auStack_180,param_1 + 0x29a0);
  }
  return;
}
