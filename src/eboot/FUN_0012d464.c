/* HSTMATCH module=EBOOT.BIN start=0x0012d464 end=0x0012d550 symbol=FUN_0012d464 lang=c99 data=0x002dac60 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002dac60-0x002dad54) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define PATH_BUF_SIZE 256

extern void FUN_000143b0();
extern void FUN_00141718();
extern void FUN_0014189c();
extern void FUN_00141c3c();
extern void FUN_00141e70();
extern void FUN_0014613c();

/* Load the five script files (event area, route, point, item, patrol) of one lobby area. */
void FUN_0012d464(u32 loader,int lobbyIndex,int areaIndex)
{
  u8 path [PATH_BUF_SIZE];
  
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/eventarea%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_00141718(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/route%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014613c(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/point%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_0014189c(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/item%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_00141c3c(loader,path);
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/patrol%02d.dat",lobbyIndex + 1,areaIndex + 1);
  FUN_00141e70(loader,path);
}
