/* HSTMATCH module=EBOOT.BIN start=0x002904d4 end=0x002905bc symbol=FUN_002904d4 lang=c99 data=0x002ff550 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ff550-0x002ff56a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/psmf_player.h"

#define ERR_PIPE_FULL (-0x7ffdfe4d) /* send call result when the pipe has no room */

extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern u32 * FUN_000149a8();
extern u8 * FUN_00022d7c();
extern void FUN_0028fb44();
extern int FUN_002b7988();

/* Queues a start request (type, argument and file name) on the player's message pipe; returns 1 when it was sent. */
u32 FUN_002904d4(PsmfPlayer *player,u32 file_name,u32 arg)
{
  u32 ok;
  int result;
  int sent;
  
  if (player->ready == '\0') {
    FUN_0028fb44(DAT_002ff534);
    ok = 0;
  }
  else {
    player->msg.type = PSMF_MSG_START;
    FUN_000149a8(player->msg.data,file_name);
    player->msg.arg = arg;
    FUN_00022d7c(player->work_buf,0,PSMF_WORK_SIZE);
    result = FUN_002b7988(player->pipe,&player->msg,SERVICE_REQUEST_SIZE,0,&sent);
    if (result == ERR_PIPE_FULL) {
      FUN_0028fb44("Play(): request is full.\n");
    }
    else if ((result != 0) || (sent != SERVICE_REQUEST_SIZE)) {
      FUN_0028fb44(DAT_002ff56c,result,sent);
      return 0;
    }
    ok = 1;
    player->started = 1;
  }
  return ok;
}
