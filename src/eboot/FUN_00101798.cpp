/* HSTMATCH module=EBOOT.BIN start=0x00101798 end=0x001018d0 symbol=FUN_00101798 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" u8 DAT_002d8ad0;
extern "C" char DAT_002d8ab4[];
extern "C" void FUN_001006b0(char *);

struct Frame_00101798 {
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
  virtual void Slot3();
  virtual short GetX(int);
  virtual short GetY(int);
  unsigned char pad[4];
  short x;
  unsigned char pad2[2];
  short y;
};

struct Main_00101798 {
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
  virtual void Slot3();
  virtual void Slot4();
  virtual void Slot5();
  virtual void Slot6();
  virtual void Slot7();
  virtual void Slot8();
  virtual void Slot9();
  virtual void Slot10();
  virtual void Slot11();
  virtual void Slot12();
  virtual void Draw(int, int, int, int, int, int, int, int, int, int, void *);
  Frame_00101798 **frames;
  int count;
};

extern "C" void FUN_00101798(Main_00101798 *param_1,int param_2,int param_3,int param_4,int param_5, int param_6,int param_7)
{
  short dx;
  short dy;
  Frame_00101798 *frame;
  if (param_1->count == 0) {
    FUN_001006b0(DAT_002d8ab4);
  }
  frame = param_1->frames[param_2];
  if (param_3 < 0) {
    dx = frame->x;
    dy = frame->y;
  }
  else {
    dx = frame->GetX(param_3);
    dy = frame->GetY(param_3);
  }
  param_1->Draw(param_2,param_3,param_4,param_5,(int)(short)((short)param_4 + dx),
                (int)(short)((short)param_5 + dy),param_6,param_7,0,0,&DAT_002d8ad0);
}
