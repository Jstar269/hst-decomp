/* HSTMATCH module=hstp_trans_main.prx start=0x0010c7ec end=0x0010c7fc symbol=FUN_0010c7ec lang=c99 */
/* Clone of src/eboot/FUN_00106c08.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002d13b0;
extern void FUN_00105fe4();

void FUN_0010c7ec(int param_1,uint *param_2,undefined4 param_3)
{
  FUN_00105fe4(param_1,param_2,(uint *)&DAT_002d13b0,param_3);
  return;
}
