/* HSTMATCH module=EBOOT.BIN start=0x00101798 end=0x001018d0 symbol=FUN_00101798 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" u8 DAT_002d8ad0;
extern "C" char DAT_002d8ab4[];
extern "C" void FUN_001006b0(char *);

struct FrameObj {
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

struct DrawOwner {
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
  FrameObj **frames; /* 0x4 frame objects, indexed by frame id */
  int count;       /* 0x8 */
};

/* Draw one part of a frame at (x, y) shifted by the part's own offset (or the frame's when part is negative). */
extern "C" void FUN_00101798(DrawOwner *self,int frameId,int part,int x,int y, int colorA,int colorB)
{
  short dx; /* offset added to x */
  short dy; /* offset added to y */
  FrameObj *frame;
  if (self->count == 0) {
    FUN_001006b0(DAT_002d8ab4);
  }
  frame = self->frames[frameId];
  if (part < 0) {
    dx = frame->x;
    dy = frame->y;
  }
  else {
    dx = frame->GetX(part);
    dy = frame->GetY(part);
  }
  self->Draw(frameId,part,x,y,(int)(short)((short)x + dx),
                (int)(short)((short)y + dy),colorA,colorB,0,0,&DAT_002d8ad0);
}
