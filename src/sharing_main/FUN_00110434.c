/* HSTMATCH module=hstp_trans_main.prx start=0x00110434 end=0x00110444 symbol=FUN_00110434 lang=c99 */
/* Clone of src/eboot/FUN_0010a674.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


bool FUN_00110434(int param_1)
{
  return *(int *)(param_1 + 0x240) == 1;
}
