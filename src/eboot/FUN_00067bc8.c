/* HSTMATCH module=EBOOT.BIN start=0x00067bc8 end=0x00067bec symbol=FUN_00067bc8 lang=c99 */
/* Clone of src/sharing_main/FUN_0006901c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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


float FUN_00067bc8(float param_1,float param_2,float param_3)
{
  return param_1 + (param_2 - param_1) * (1.0f - (1.0f - param_3) * (1.0f - param_3));
}
