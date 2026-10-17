/* HSTMATCH module=hstp_trans_main.prx start=0x00229fa8 end=0x00229fe0 symbol=FUN_00229fa8 lang=c99 */
/* Clone of src/eboot/FUN_0021aa34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0022a030();
extern void FUN_0022a154();

undefined4 * FUN_00229fa8(undefined4 *param_1)
{
  *param_1 = 0;
  FUN_0022a030();
  FUN_0022a154(param_1,0xb);
  return param_1;
}
