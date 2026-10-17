/* HSTMATCH module=hstp_trans_main.prx start=0x001a57e4 end=0x001a57ec symbol=FUN_001a57e4 lang=c99 */
/* Clone of src/eboot/FUN_00198de0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_001a57e4(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc0) = param_2;
  return;
}
