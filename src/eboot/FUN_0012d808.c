/* HSTMATCH module=EBOOT.BIN start=0x0012d808 end=0x0012d868 symbol=FUN_0012d808 lang=c99 data=0x002dad80 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dad80-0x002dadad) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/lobby_stage.h"

extern void FUN_000143b0();
extern char * FUN_0006517c();

/* Write the path of the stage's SE data file into dest. */
void FUN_0012d808(LobbyStage *self,char *dest)
{
  char *folder;
  
  folder = FUN_0006517c(self->names,self->lobby,0);
  FUN_000143b0(dest,"data/lobby/%s/setting/l%02d_r%02d_sedata.dat",folder,
               self->lobby + 1,self->room + 1);
}
