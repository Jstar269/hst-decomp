/* HSTMATCH module=EBOOT.BIN start=0x00225d98 end=0x00225de4 symbol=FUN_00225d98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_parts.h"

struct GameOwner;
extern "C" void FUN_00103628(GameOwner *, int);

struct GameObject {
  virtual ~GameObject();
  virtual void Init(int);
};

struct GameOwner {
  char pad_00[0x5c];
  unsigned char flag; /* 0x5c */
  char pad_5d[0x1b];
  GameObject *child;  /* 0x78 */
};

/* Switch on the first part: set its flag and initialise its child object. */
extern "C" void FUN_00225d98(ModeObj *self)
{
  GameOwner *owner;
  unsigned char flag = 1;
  
  owner = (GameOwner *)self->parts->part00;
  FUN_00103628(owner,flag);
  owner->flag = flag;
  owner->child->Init(1);
}
