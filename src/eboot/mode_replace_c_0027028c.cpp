/* HSTMATCH module=EBOOT.BIN start=0x0027028c end=0x002704c0 symbol=FUN_0027028c lang=c++ data=0x002fe2d4 */
/* Hand-written reconstruction from the disassembly (continued from lane fm8 near-miss wip/mode_replace_c_0027028c.cpp); exact match verified; matching idiom: `return;` ending the `cVar1 == 0` arm (puts MWCC's branch cleanup in retail's unthreaded mode) and `base + iVar2 + 0x14` addressing; names and types await human review. Data: its string literals (3 strings, 0x002fe2d4-0x002fe323) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/replace_screen.h"

#define FACE_KIND 2 /* record kind that gets the face animation set up */

extern "C" {
extern u8 DAT_002fe2ac;
extern u8 DAT_002fe2d0;
extern char DAT_002fe2b4[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_000143b0(char *, char *, ...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern u32 FUN_00279578(...);
extern void FUN_000573a0(void *, int, char *, int, int);
extern void FUN_00057b58(void *, float, int, int);
extern void FUN_00058ec4(void *, float, int);
extern void FUN_00058ddc(void *, int, int);
extern void FUN_00059084(void *, int);
}
/* Two views of the model for its virtual destructor (separate classes keep the two deletes apart). */
struct ModelA { virtual ~ModelA(); };
struct ModelB { virtual ~ModelB(); };

/* Model fields set while its animation is started. */
struct AnimModel {
  char pad00[0xc0];
  u8 unkc0;             /* 0xc0 */
  char padc1[3];
  float unkc4;          /* 0xc4 */
  char padc8[8];
  float unkd0;          /* 0xd0 */
};

/* Replace the screen's model with the one from record table 2; for FACE_KIND records also load and start the face animation. */
extern "C" void FUN_0027028c(ReplaceScreen *self)
{
  char motion_name[256];
  char motion_path[256];
  int loaded;
  int rec_off;
  int model;
  AnimModel *anim;
  int *old;

  rec_off = FUN_002791a4(self,2);
  model = FUN_00279578(self,2);
  rec_off = rec_off + model * 4;
  if (self->unk180 < 0) {
    return;
  }
  {
    rec_off = rec_off * REPLACE_REC_SIZE;
    {
      void *dup;

      dup = &DAT_002fe2ac;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(u32 *)((char *)self->recs2.data + rec_off + 8),&DAT_002fe2d0);
    }
    old = (int *)self->model;
    if (old != (int *)0x0) {
      delete ((ModelA *)(old));
      self->model = 0;
    }
    model = FUN_00000bcc(REPLACE_MODEL_SIZE);
    if (model != 0) {
      model = FUN_00094fa4(model);
    }
    self->model = (void *)model;
    loaded = FUN_00095104(model,2,*(u32 *)((char *)self->recs2.data + rec_off + 8),0,0);
    FUN_0001cb88(&DAT_0030ebf4);
    if (loaded == '\0') {
      old = (int *)self->model;
      if (old != (int *)0x0) {
        delete ((ModelB *)(old));
        self->model = 0;
      }
      return;
    }
    else if (*(int *)((char *)self->recs2.data + rec_off + 0x14) == FACE_KIND) {
      FUN_0001ca58(&DAT_0030ebf4,"menu/pc/face/anim%03d.xb",0);
      FUN_000143b0(motion_name,"chrm_pc%02d_00",0);
      FUN_000143b0(motion_path,"data/chara/menu_motion/%02d/%s.i3m",0,motion_name);
      FUN_000573a0(self->model,0,motion_path,0,0);
      FUN_00057b58(self->model,0.0f,0,0);
      anim = (AnimModel *)self->model;
      FUN_00058ec4(anim,1.0f,-1);
      anim->unkc4 = 1.0f;
      anim = (AnimModel *)self->model;
      FUN_00058ddc(anim,1,-1);
      anim->unkc0 = 1;
      anim = (AnimModel *)self->model;
      FUN_00059084(anim,-1);
      anim->unkd0 = anim->unkc4;
      FUN_0001cb88(&DAT_0030ebf4);
    }
  }
}
