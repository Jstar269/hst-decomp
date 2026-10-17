/* HSTMATCH module=hstp_trans_main.prx start=0x0026b500 end=0x0026b540 symbol=FUN_0026b500 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern int * FUN_0026b540();
extern undefined4 FUN_0026b674();

undefined4 FUN_0026b500(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0026b674(param_1);
  FUN_0026b540(param_1,param_3);
  return param_1;
}
