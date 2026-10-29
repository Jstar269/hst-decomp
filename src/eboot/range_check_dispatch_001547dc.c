/* HSTMATCH module=EBOOT.BIN start=0x001547dc end=0x00154854 symbol=FUN_001547dc lang=c99 data=0x002dc928 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed as a byte, range test as one || condition with >= 0x11 (the compare lands in v0), explicit int return; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc928-0x002dc93b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Number of shop items; item numbers at or above this are ignored. */
#define SHOP_ITEM_COUNT 0x11

extern unsigned char DAT_003402f0; /* script trace flag */
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_0022bfb0(int, int);

typedef struct ShopItemCmd {
  int pad0;
  int pad4;
  int item; /* 0x08 */
  int arg1; /* 0x0c */
} ShopItemCmd;

/* Script command "ShopItem": trace it and pass a valid item number on. */
int FUN_001547dc(ShopItemCmd *cmd, int ctx)
{
  int item;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("ShopItem [%d, %d]\n", cmd->item, cmd->arg1);
  }
  item = cmd->item;
  if (item < 0 || item >= SHOP_ITEM_COUNT) return 0;
  FUN_0022bfb0(item, cmd->arg1);
  return 0;
}
