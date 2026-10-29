/* HSTMATCH module=hstp_trans_main.prx start=0x002a1c2c end=0x002a1d14 symbol=FUN_002a1c2c lang=c99 data=0x003a845c */
/* Clone of src/eboot/FUN_002904d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a845c-0x003a8476) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/psmf_player.h"

#define ERR_PIPE_FULL (-0x7ffdfe4d) /* send call result when the pipe has no room */

extern char DAT_003a8440[];
extern char DAT_003a8478[];
extern u32 * FUN_000149a8();
extern u8 * FUN_00022da4();
extern void FUN_002a130c();
extern int FUN_002c7728();

/* Queues a start request (type, argument and file name) on the player's message pipe; returns 1 when it was sent. */
u32 FUN_002a1c2c(PsmfPlayer *player,u32 file_name,u32 arg)
{
  u32 ok;
  int result;
  int sent;
  
  if (player->ready == '\0') {
    FUN_002a130c(DAT_003a8440);
    ok = 0;
  }
  else {
    player->msg.type = PSMF_MSG_START;
    FUN_000149a8(player->msg.data,file_name);
    player->msg.arg = arg;
    FUN_00022da4(player->work_buf,0,PSMF_WORK_SIZE);
    result = FUN_002c7728(player->pipe,&player->msg,SERVICE_REQUEST_SIZE,0,&sent);
    if (result == ERR_PIPE_FULL) {
      FUN_002a130c("Play(): request is full.\n");
    }
    else if ((result != 0) || (sent != SERVICE_REQUEST_SIZE)) {
      FUN_002a130c(DAT_003a8478,result,sent);
      return 0;
    }
    ok = 1;
    player->started = 1;
  }
  return ok;
}
