/* HSTMATCH module=EBOOT.BIN start=0x002ada5c end=0x002ada80 symbol=FUN_002ada5c lang=c99 */
/* Prize score table: data/prize/score.csv; see docs/DATA-TABLES.md */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern undefined DAT_00302c6c;
extern undefined DAT_0034b5a0;
extern char DAT_00302c54[];
extern undefined4 FUN_000651b8();

void FUN_002ada5c(void)
{
  FUN_000651b8((int *)&DAT_0034b5a0,DAT_00302c54,1,0,&DAT_00302c6c);
  return;
}
