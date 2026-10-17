/* HSTMATCH module=hstp_trans_main.prx start=0x000b6770 end=0x000b67dc symbol=FUN_000b6770 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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


undefined4 FUN_000b6770(int param_1)
{
  int *owner = *(int **)(param_1 + 0x5bc);
  int *p = *(int **)((char *)owner + 0x58);
  int id = p != 0 ? *(int *)((char *)p + 0xf0) : -1;
  if (id < 0x44) goto special;
  if (id < 0x88) return 1;
special:
  switch (id) {
    case 0x98:
    case 0x9a:
    case 0x9c:
      return 1;
    default:
      return 0;
  }
}
