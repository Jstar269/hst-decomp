/* HSTMATCH module=EBOOT.BIN start=0x00150d6c end=0x00150ed0 symbol=FUN_00150d6c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_0034a114;
extern unsigned char DAT_003402f0;
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

struct ItemDef {
  unsigned char pad00[8];
  int f8;                     /* 0x08 */
  int fc;                     /* 0x0c */
  unsigned char f10;          /* 0x10 */
};

extern "C" Item *FUN_00150d6c(ItemDef *def, float dist, Owner *owner)
{
  Item *item;
  char *banner;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(owner);
    banner = (def->f10 != 0) ? DAT_002dc490 : DAT_002dc440;
    FUN_0014fd94(DAT_002dc47c, def->f8, def->fc, banner);
  }
  if (def->f8 < 0 || def->f8 >= 0x11) {
    return 0;
  }
  {
    if (def->f10 != 0) {
      FUN_0022bf94(def->f8, def->fc);
    }
    else {
      FUN_001c6bec(DAT_0034a114, def->f8, def->fc, -1, 0, 0);
    }
    if (def->f8 == 6) {
      FUN_0022bf94(10, def->fc);
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
