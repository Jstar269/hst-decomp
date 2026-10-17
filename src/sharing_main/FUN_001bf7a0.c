/* HSTMATCH module=hstp_trans_main.prx start=0x001bf7a0 end=0x001bf834 symbol=FUN_001bf7a0 lang=c99 */
/* Clone of src/eboot/FUN_001b177c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00391314;
extern undefined DAT_0039131c;
extern undefined DAT_00391320;
extern uint * FUN_00014788();
extern uint * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

void FUN_001bf7a0(undefined4 param_1)
{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  puVar1 = (undefined1 *)FUN_00014cfc(param_1,0x2e);
  if (puVar1 != (undefined1 *)0x0) {
    FUN_000149a8(auStack_10,puVar1);
    *puVar1 = 0;
    FUN_00014788(param_1,&DAT_00391314);
    FUN_00014788(param_1,auStack_10);
  }
  iVar2 = (int)(FUN_00014d64(param_1,&DAT_0039131c));
  if (iVar2 != 0) {
    FUN_00014b74(iVar2,&DAT_00391320,3);
  }
  return;
}
