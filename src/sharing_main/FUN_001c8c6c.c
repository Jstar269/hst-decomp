/* HSTMATCH module=hstp_trans_main.prx start=0x001c8c6c end=0x001c8c88 symbol=FUN_001c8c6c lang=c99 */
/* Clone of src/eboot/FUN_001baf24.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


undefined1 FUN_001c8c6c(int param_1,int param_2)
{
  return *(undefined1 *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x75);
}
