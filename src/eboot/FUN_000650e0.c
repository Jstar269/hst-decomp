/* HSTMATCH module=EBOOT.BIN start=0x000650e0 end=0x000650e8 symbol=FUN_000650e0 lang=c99 */
/* CSV table reader: row count (this+8); see docs/DATA-TABLES.md */
/* Clone of src/eboot/FUN_0027edb4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_000650e0(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}
