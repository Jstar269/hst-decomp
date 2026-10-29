/* HSTMATCH module=EBOOT.BIN start=0x001cb700 end=0x001cb7d0 symbol=FUN_001cb700 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/panel_data.h"

extern char DAT_00341d7c;
extern int DAT_00341d84;
extern int FUN_00014a40(char *);
extern char *FUN_000149a8(char *, char *);
extern void FUN_001cd88c(PanelData *, int, int);
extern void FUN_001c2498(PanelData *);

/* Stores a name string in the panel and queues the next panel step. */
void FUN_001cb700(PanelOwner *owner, char *name)
{
  int flag = owner->unkfc;
  PanelData *panel = owner->panel;
  int len;

  DAT_00341d7c = 0;
  panel->unk90 = 0;
  panel->unk94 = 2;
  len = FUN_00014a40(name);
  FUN_000149a8(panel->text98, name);
  *(char *)(len + (int)panel + 0x98) = 0;
  if (flag != 0)
    DAT_00341d84 = 16;
  else
    DAT_00341d84 = 0;
  FUN_001cd88c(panel, 3, 1);
  FUN_001c2498(panel);
  panel->unk61 = 1;
  if (panel->unk61 != 0)
    panel->unk62 = 1;
  owner->unkfc = 0;
}
