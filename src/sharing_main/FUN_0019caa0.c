/* HSTMATCH module=hstp_trans_main.prx start=0x0019caa0 end=0x0019cae0 symbol=FUN_0019caa0 lang=c99 */
/* Clone of src/eboot/FUN_00190290.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_00003e04();
extern uint * FUN_0019d090();

int FUN_0019caa0(int param_1,int param_2)
{
  FUN_00003e04();
  FUN_0019d090(param_1 + 0xc,param_2 + 0xc);
  return param_1;
}
