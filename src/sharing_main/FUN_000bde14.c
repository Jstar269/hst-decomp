/* HSTMATCH module=hstp_trans_main.prx start=0x000bde14 end=0x000bde38 symbol=FUN_000bde14 lang=c99 */
/* Clone of src/eboot/FUN_000baaa4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_002c7c78();

bool FUN_000bde14(void)
{
  int iVar1;
  
  iVar1 = FUN_002c7c78();
  return iVar1 == 1;
}
