/* HSTMATCH module=hstp_trans_main.prx start=0x00157ec0 end=0x00157eec symbol=FUN_00157ec0 lang=c99 */
/* Clone of src/eboot/FUN_0014c3ac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00239f98();

void FUN_00157ec0(undefined4 param_1,int param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00239f98(param_2 + 0xf0);
  *puVar1 = param_3;
  return;
}
