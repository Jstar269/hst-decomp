/* HSTMATCH module=EBOOT.BIN start=0x00026a34 end=0x00026a4c symbol=FUN_00026a34 lang=c99 */
/* Clone of src/sharing_main/FUN_00026a74.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_000266ac();
extern void FUN_0002751c();
extern void FUN_000291c4();

void FUN_00026a34(int *param_1,undefined1 (*param_2) [12],undefined4 param_3)
{
  FUN_000266ac(param_1,param_2,param_3,FUN_000291c4,FUN_0002751c,'\x01');
  return;
}
