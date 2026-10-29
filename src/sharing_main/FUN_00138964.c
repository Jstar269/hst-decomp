/* HSTMATCH module=hstp_trans_main.prx start=0x00138964 end=0x00138a50 symbol=FUN_00138964 lang=c99 data=0x00381dd4 */
/* Clone of src/eboot/FUN_0012d464.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x00381dd4-0x00381ec8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define PATH_BUF_SIZE 256

extern void FUN_000143b0();
extern void FUN_0014cd64();
extern void FUN_0014cee8();
extern void FUN_0014d288();
extern void FUN_0014d4bc();
extern void FUN_00151a24();

/* Load the five script files (event area, route, point, item, patrol) of one lobby area. */
void FUN_00138964(u32 loader,int lobbyIndex,int areaIndex)
{
  u8 path [PATH_BUF_SIZE];
  
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/eventarea%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014cd64(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/route%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_00151a24(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/point%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014cee8(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/item%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014d288(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/patrol%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014d4bc(loader,path);
}
