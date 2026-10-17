/* HSTMATCH module=hstp_trans_main.prx start=0x00138964 end=0x00138a50 symbol=FUN_00138964 lang=c99 */
/* Clone of src/eboot/FUN_0012d464.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_00381dd4[];
extern char DAT_00381e08[];
extern char DAT_00381e38[];
extern char DAT_00381e68[];
extern char DAT_00381e98[];
extern void FUN_000143b0();
extern void FUN_0014cd64();
extern void FUN_0014cee8();
extern void FUN_0014d288();
extern void FUN_0014d4bc();
extern void FUN_00151a24();

void FUN_00138964(undefined4 param_1,int param_2,int param_3)
{
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,DAT_00381dd4,param_2 + 1,param_3 + 1);
  FUN_0014cd64(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_00381e08,param_2 + 1,param_3 + 1);
  FUN_00151a24(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_00381e38,param_2 + 1,param_3 + 1);
  FUN_0014cee8(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_00381e68,param_2 + 1,param_3 + 1);
  FUN_0014d288(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_00381e98,param_2 + 1,param_3 + 1);
  FUN_0014d4bc(param_1,auStack_100);
  return;
}
