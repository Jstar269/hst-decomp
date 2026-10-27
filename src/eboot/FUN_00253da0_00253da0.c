/* HSTMATCH module=EBOOT.BIN start=0x00253da0 end=0x00253f38 symbol=FUN_00253da0 lang=c99 data=0x002fcc78 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: declared the loop index before the byte offset to match the retail saved-register allocation; exact match verified; names and types await human review. Data: its string literals (6 strings, 0x002fcc78-0x002fcd87) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined * DAT_0034a79c;
extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000143b0();
extern undefined4 FUN_00055eac();
extern void FUN_00055dd0();
extern void FUN_00055e48();

void FUN_00253da0(void)
{
  undefined4 uVar1;
  int iVar3;
  int iVar2;
  undefined1 auStack_100 [256];
  
  uVar1 = FUN_00000a90(0x230);
  DAT_0034a79c = (unsigned char *)(FUN_000008d8(uVar1,FUN_00055dd0,FUN_00055e48,0x10,0x22));
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (iVar3 < 0xf) {
      FUN_000143b0(auStack_100,"data/chara/menu_motion/%02d/chrm_pc%02d_00.i3m",iVar3,iVar3);
      FUN_00055eac(DAT_0034a79c + iVar2,auStack_100,0);
    }
    else if (iVar3 < 0x1e) {
      FUN_000143b0(auStack_100,"data/chara/menu_motion/%02d/chrm_pc%02d_01.i3m",iVar3 + -0xf,iVar3 + -0xf
                  );
      FUN_00055eac(DAT_0034a79c + iVar2,auStack_100,0);
    }
    else if (iVar3 == 0x1e) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_f_00.i3m",0);
    }
    else if (iVar3 == 0x1f) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_f_01.i3m",0);
    }
    else if (iVar3 == 0x20) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_m_00.i3m",0);
    }
    else if (iVar3 == 0x21) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_m_01.i3m",0);
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar3 < 0x22);
  return;
}

