/* HSTMATCH module=hstp_trans_main.prx start=0x000490c8 end=0x00049194 symbol=FUN_000490c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined4 DAT_00375e84;
extern undefined4 DAT_00375e8c;
extern char DAT_002cc014[];
extern char DAT_002cc020[];
extern char DAT_002cc02c[];
extern char DAT_002cc058[];
extern char DAT_002cc064[];
extern char DAT_002cc070[];
extern void FUN_00000a00();
extern void FUN_00048d18();
extern int FUN_002c7688();

int FUN_000490c8(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_002c7688(DAT_00375e8c);
    if (iVar1 != 0) {
      FUN_00048d18(DAT_002cc070,DAT_002cc064,
                   DAT_002cc058,0x49);
      do {
                    
      } while( true );
    }
    DAT_00375e8c = 0xffffffff;
    iVar1 = FUN_002c7688(DAT_00375e84);
    if (iVar1 != 0) {
      FUN_00048d18(DAT_002cc02c,DAT_002cc020,
                   DAT_002cc014,0x4d);
      do {
                    
      } while( true );
    }
    DAT_00375e84 = 0xffffffff;
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
