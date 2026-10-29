/* HSTMATCH module=EBOOT.BIN start=0x00150d6c end=0x00150ed0 symbol=FUN_00150d6c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/script_cmd.h"

#define ITEM_ID_MAX 0x11    /* item ids at or above this are rejected */
#define ITEM_ID_SPECIAL 6   /* item id that also triggers the extra call with 10 */

extern "C" {
extern int DAT_0034a114;
extern unsigned char DAT_003402f0; /* script trace flag */
extern char DAT_002dc440[];
extern char DAT_002dc490[];
extern char DAT_002dc47c[];
extern void FUN_00000bcc(int size);
extern void FUN_0014d044(void *owner);
extern void FUN_0014fd94(char *fmt, int a, int b, char *banner);
extern void FUN_001c6bec(int ctx, int a, int b, int c, int d, int e);
extern void FUN_0022bf94(int a, int b);
}

struct Owner;

struct Base {
  Base() {}
  virtual ~Base();
};

struct Item : Base {
  Item() {}
  virtual int Init(float dist, Owner *owner);
};

/* Script command that creates an item: arg0 is the item id, arg1 its option, unk10 selects the alternate path. */
extern "C" Item *FUN_00150d6c(ScriptCmd *cmd, float dist, Owner *owner)
{
  Item *item;
  char *banner;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(owner);
    banner = (cmd->unk10 != 0) ? DAT_002dc490 : DAT_002dc440;
    FUN_0014fd94(DAT_002dc47c, cmd->arg0, cmd->arg1, banner);
  }
  if (cmd->arg0 < 0 || cmd->arg0 >= ITEM_ID_MAX) {
    return 0;
  }
  {
    if (cmd->unk10 != 0) {
      FUN_0022bf94(cmd->arg0, cmd->arg1);
    }
    else {
      FUN_001c6bec(DAT_0034a114, cmd->arg0, cmd->arg1, -1, 0, 0);
    }
    if (cmd->arg0 == ITEM_ID_SPECIAL) {
      FUN_0022bf94(10, cmd->arg1);
    }
    item = new Item();
    if (item->Init(dist, owner) != 0) {
      if (item != 0) {
        delete item;
      }
      return 0;
    }
  }
  return item;
}
