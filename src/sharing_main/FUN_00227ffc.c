/* HSTMATCH module=hstp_trans_main.prx start=0x00227ffc end=0x00228030 symbol=FUN_00227ffc lang=c99 */
/* Clone of src/eboot/FUN_00218ae4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00227ffc(int *param_1,int *param_2,int param_3)
{
  *param_1 = param_3 / 0xc;
  *param_2 = param_3 % 0xc;
  return;
}
