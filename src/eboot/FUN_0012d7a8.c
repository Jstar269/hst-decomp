/* HSTMATCH module=EBOOT.BIN start=0x0012d7a8 end=0x0012d808 symbol=FUN_0012d7a8 lang=c99 data=0x002dad54 */
/* LobbyStage_GetSeCsvPath: data/lobby/<name>/setting/lNN_rNN_se.csv; see docs/DATA-TABLES.md Data: its string literals (1 strings, 0x002dad54-0x002dad7d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lobby_stage.h"

extern void FUN_000143b0();
extern char * FUN_0006517c();

/* Write the path of the stage's SE csv into dest. */
void FUN_0012d7a8(LobbyStage *self,char *dest)
{
  char *folder;
  
  folder = FUN_0006517c(self->names,self->lobby,0);
  FUN_000143b0(dest,"data/lobby/%s/setting/l%02d_r%02d_se.csv",folder,
               self->lobby + 1,self->room + 1);
}
