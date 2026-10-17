/* HSTMATCH module=hstp_trans_main.prx start=0x00193a54 end=0x00193b70 symbol=FUN_00193a54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_00388048;
extern char DAT_00387f64[];
extern char DAT_00387f74[];
extern char DAT_00387f84[];
extern char DAT_0038801c[];
extern char DAT_0038804c[];
extern char DAT_00388078[];
extern void FUN_000143b0();
extern undefined4 FUN_00105070();
extern void FUN_00105224();

void FUN_00193a54(char *param_1)
{
  int iVar1;
  undefined1 auStack_100 [256];
  undefined1 auStack_180 [128];
  
  FUN_000143b0(auStack_100,DAT_0038801c,0);
  FUN_000143b0(auStack_180,DAT_00387f64,0);
  iVar1 = FUN_00105070(param_1 + 0x2928,auStack_100,1,&DAT_00388048);
  if (iVar1 != 0) {
    FUN_00105224(auStack_180,param_1 + 0x2928);
  }
  FUN_000143b0(auStack_100,DAT_0038804c,0);
  FUN_000143b0(auStack_180,DAT_00387f74,0);
  iVar1 = FUN_00105070(param_1 + 0x28b0,auStack_100,1,&DAT_00388048);
  if (iVar1 != 0) {
    FUN_00105224(auStack_180,param_1 + 0x28b0);
  }
  FUN_000143b0(auStack_100,DAT_00388078,0);
  FUN_000143b0(auStack_180,DAT_00387f84,0);
  iVar1 = FUN_00105070(param_1 + 0x29a0,auStack_100,1,&DAT_00388048);
  if (iVar1 != 0) {
    FUN_00105224(auStack_180,param_1 + 0x29a0);
  }
  return;
}
