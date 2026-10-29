/* HSTMATCH module=hstp_trans_main.prx start=0x00138d08 end=0x00138d68 symbol=FUN_00138d08 lang=c99 data=0x00381ef4 */
/* Clone of src/eboot/FUN_0012d7a8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00381ef4-0x00381f21) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/lobby_stage.h"

extern void FUN_000143b0();
extern char * FUN_000661a8();

/* Write the path of the stage's SE data file into dest. */
void FUN_00138d08(LobbyStage *self,char *dest)
{
  char *folder;
  
  folder = FUN_000661a8(self->names,self->lobby,0);
  FUN_000143b0(dest,"data/lobby/%s/setting/l%02d_r%02d_sedata.dat",folder,
               self->lobby + 1,self->room + 1);
}
