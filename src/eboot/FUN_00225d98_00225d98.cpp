/* HSTMATCH module=EBOOT.BIN start=0x00225d98 end=0x00225de4 symbol=FUN_00225d98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct GameOwner;
extern "C" void FUN_00103628(GameOwner *, int);

struct GameObject {
  virtual ~GameObject();
  virtual void Init(int);
};

struct GameOwner {
  char pad_00[0x5c];
  unsigned char flag;
  char pad_5d[0x1b];
  GameObject *child;
};

extern "C" void FUN_00225d98(int param_1)
{
  GameOwner *iVar1;
  unsigned char flag = 1;
  
  iVar1 = (GameOwner *)**(int **)(param_1 + 0x3c);
  FUN_00103628(iVar1,flag);
  iVar1->flag = flag;
  iVar1->child->Init(1);
}
