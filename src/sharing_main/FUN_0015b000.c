/* HSTMATCH module=hstp_trans_main.prx start=0x0015b000 end=0x0015b014 symbol=FUN_0015b000 lang=c99 */
/* Clone of src/eboot/FUN_0014f000.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


int FUN_0015b000(undefined4 *param_1)
{
  char cVar1;
  
  cVar1 = *(char *)*param_1;
  *param_1 = (unsigned int)((char *)*param_1 + 1);
  return (int)cVar1;
}
