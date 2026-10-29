/* HSTMATCH module=EBOOT.BIN start=0x0017de58 end=0x0017df2c symbol=FUN_0017de58 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed the float stack record and modeled the singleton member call; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_mgr.h"

extern "C" SlotSettings *FUN_0016bc7c();

/* Record looked up by id: a direction vector at 0x04. */
struct DirRec {
  char pad00[4];
  float x, y, z;
};

/* Character record looked up by id; byte 0x24 selects the mode. */
struct InfoRec {
  char pad00[0x24];
  u8 flag;
};

struct Receiver {
  void FUN_0018ba64(float,float,float,int *,int,int,int,float *);
};

extern "C" Receiver *FUN_0018b804();
extern "C" InfoRec *FUN_00193474(u32);
extern "C" DirRec *FUN_00204400(u32);

/* Hand slot `slot`'s sub-object, the id's direction and the settings position to the receiver. */
extern "C" void FUN_0017de58(SlotMgr *self,u32 id,int slot)
{
  SlotSettings *settings;
  DirRec *dir;
  InfoRec *info;
  u32 mode;
  float x;
  float z;
  float y;
  float pos[4];
  
  settings = FUN_0016bc7c();
  dir = FUN_00204400(id);
  info = FUN_00193474(id);
  if (info->flag == '\0') {
    mode = 4;
  }
  else {
    mode = 2;
  }
  x = settings->pos[0];
  z = settings->pos[2];
  y = settings->pos[1];
  pos[0] = x;
  pos[1] = y;
  pos[2] = z;
  pos[3] = 0.0f;
  FUN_0018b804()->FUN_0018ba64(dir->x,dir->y,dir->z,
                               self->entries[slot]->sub,id,slot,mode,
                               pos);
}
