/* HSTMATCH module=hstp_trans_main.prx start=0x001e1f70 end=0x001e1fa4 symbol=FUN_001e1f70 lang=c99 */
/* Clone of src/eboot/FUN_001d416c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


int FUN_001e1f70(float param_1,int param_2,int param_3)
{
  return (int)((1.0f - param_1) * (float)param_2 + param_1 * (float)param_3);
}
