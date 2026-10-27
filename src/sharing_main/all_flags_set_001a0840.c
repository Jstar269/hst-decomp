/* HSTMATCH module=hstp_trans_main.prx start=0x001a0840 end=0x001a0920 symbol=FUN_001a0840 lang=c99 data=0x00388c04 */
/* Clone of src/eboot/all_flags_set_00194030.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388c04-0x00388c1c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern char DAT_003b7ebc[];
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern undefined4 FUN_0019fcd8();
extern undefined4 FUN_0019ff80();
extern undefined4 FUN_001a00e8();
extern undefined4 FUN_001a0238();
extern undefined4 FUN_001a039c();
extern undefined4 FUN_001a0650();

undefined4 FUN_001a0840(int param_1)
{
  int cVar1;
  int cVar2;
  int cVar3;
  int cVar4;
  int cVar5;
  int cVar6;

  if (param_1 != 0) {
    FUN_0001c5f4(DAT_003b7ebc,"menu/challenge_match.xb");
  }
  cVar1 = (uchar)FUN_0019ff80();
  cVar2 = (uchar)FUN_001a00e8();
  cVar3 = (uchar)FUN_001a0650();
  cVar4 = (uchar)FUN_001a0238();
  cVar5 = (uchar)FUN_001a039c();
  if (param_1 != 0) {
    FUN_0001c73c(DAT_003b7ebc);
  }
  cVar6 = (uchar)FUN_0019fcd8();
  if (cVar1 != '\0' && cVar2 != '\0' && cVar3 != '\0' && cVar4 != '\0' && cVar5 != '\0' && cVar6 != '\0') {
    return 1;
  }
  return 0;
}
