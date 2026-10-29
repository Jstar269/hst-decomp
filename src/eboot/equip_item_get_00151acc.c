/* HSTMATCH module=EBOOT.BIN start=0x00151acc end=0x00151b94 symbol=FUN_00151acc lang=c99 data=0x002dc584 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc584-0x002dc5a5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

enum { EQUIP_PART_COUNT = 3 };

/* One equipment part; only its item word is read. */
struct EquipPart { char pad[0x1b4]; int item; };
/* The global player object seen through its part pointers. */
struct EquipPlayer { char pad[0x54]; struct EquipPart *part[EQUIP_PART_COUNT]; };

extern unsigned char DAT_003402f0; /* script trace flag */
extern struct EquipPlayer *DAT_0034a118;
void FUN_0014d044(ScriptCtx *);
void FUN_0014fd94(char *, int, int);
int *FUN_0014c384(int, int); /* register slot of a script register bank */

/* Script command "GetEquipItem": store the item of the player's equipment part (-1 for an unknown part) into the
   command's register. */
int FUN_00151acc(ScriptCmd *cmd, ScriptCtx *ctx)
{
  int parts;
  int item;
  int regs;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("GetEquipItem [reg:%d, parts:%d]\n", cmd->arg0, cmd->arg1);
  }
  regs = ctx->regs;
  parts = cmd->arg1;
  item = -1;
  switch (parts) {
  case 0:
    item = DAT_0034a118->part[0]->item;
    break;
  case 1:
    item = DAT_0034a118->part[1]->item;
    break;
  case 2:
    item = DAT_0034a118->part[2]->item;
    break;
  }
  *FUN_0014c384(regs, cmd->arg0) = item;
  return 0;
}
