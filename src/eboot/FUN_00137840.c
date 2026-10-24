/* HSTMATCH module=EBOOT.BIN start=0x00137840 end=0x0013788c symbol=FUN_00137840 lang=c99 */
/* CourtMgr_LoadAreaClip: data/court/<name>/setting/cNN_areaclip.csv; see docs/DATA-TABLES.md */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003402a4;
extern char DAT_002db990[];
extern void FUN_000143b0();
extern void FUN_001415e8();

void FUN_00137840(int param_1)
{
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,DAT_002db990,DAT_003402a4,
               *(undefined4 *)(param_1 + 0x1364));
  FUN_001415e8(param_1 + 0x40,0,auStack_100);
  return;
}
