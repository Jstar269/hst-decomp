/* HSTMATCH module=EBOOT.BIN start=0x001033e8 end=0x00103474 symbol=FUN_001033e8 lang=c99 data=0x002d8be8 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001033e8.c) corrected by hand: replaced the absolute address literal with DAT_0033a680; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8be8-0x002d8c22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_0033a6c8;
extern char DAT_0033a680[];
extern void FUN_00051398();
extern void FUN_000513fc();
extern void FUN_00051490();
extern void FUN_001006b0();

void FUN_001033e8(int param_1,undefined4 param_2)
{
  if (*(int *)(param_1 + 0x44) == 0) {
    FUN_001006b0("ERROR: SpriteNodeList::Draw(): m_tex_id_list.size() == 0\n");
  }
  FUN_00051398(DAT_0033a680);
  FUN_000513fc(DAT_0033a680,param_2);
  FUN_00051490(DAT_0033a680,0,0,0x1e0,0x110,*(undefined4 *)(param_1 + 0x44),
               *(undefined4 *)(param_1 + 0x40));
  DAT_0033a6c8 = 0xffffffff;
  return;
}
