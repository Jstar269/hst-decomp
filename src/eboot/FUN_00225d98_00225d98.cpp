/* HSTMATCH module=EBOOT.BIN start=0x00225d98 end=0x00225de4 symbol=FUN_00225d98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

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
  return;
}
