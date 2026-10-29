/* HSTMATCH module=EBOOT.BIN start=0x0015c2c8 end=0x0015c4e0 symbol=FUN_0015c2c8 lang=c++ data=0x002de420 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002de420-0x002de47e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/loadmes_obj.h"

extern "C" {
extern u8 DAT_0030ebf4;
extern u8 DAT_0034179c;
extern int FUN_00000bcc(...);
extern void FUN_000143b0(...);
extern int FUN_00014934(...);
extern void FUN_000149a8(...);
extern void FUN_0001cad0(void *, int, void *);
extern void FUN_0001cb88(void *);
extern LoadMesRes * FUN_00050fc0(...);
extern void FUN_000511c4(...);
extern void FUN_00051398(LoadMesRes *, float);
extern void FUN_0015a62c(...);
extern void FUN_001b3378(void *, int);
}

/* Rebuild the background resource from the name in buf when it is missing or the cache says the name changed. */
static inline void Reload(LoadMesRes **slot, char *cache, char *buf, Float4 *v)
{
  LoadMesRes *res;

  if (*slot != 0) {
    if (FUN_00014934(cache,buf) == 0) return;
  }
  if (*slot != 0) {
    delete *slot;
    *slot = 0;
  }
  res = (LoadMesRes *)FUN_00000bcc(0x48);
  if (res != 0) {
    res = FUN_00050fc0(res);
  }
  *slot = res;
  FUN_000511c4(res,buf,0);
  FUN_00051398(*slot,3000.0f);
  FUN_000149a8(cache,buf);
  v->x = 0;
  v->y = 0;
  v->z = 0;
  v->w = 1.0f;
}

/* Show special message n: log the message file, reload the background resource from the name "S_d%02d" (n == 0) or
   "S_u%02d" (n - 1) and optionally notify the DAT_0034179c object. */
extern "C" void FUN_0015c2c8(LoadMesObj *self,int n,int notify)
{
  FUN_000143b0(self->nameBuf,"menu/loadmes/special/loadmes_s%02d.xb",n);
  FUN_0001cad0(&DAT_0030ebf4,1,self->nameBuf);
  if (n == 0) {
    FUN_000143b0(self->nameBuf,"data/menu/loadmes/S_d%02d",n);
    Reload(&self->bg,self->bgCache,self->nameBuf,&self->bgParam);
  }
  else {
    FUN_000143b0(self->nameBuf,"data/menu/loadmes/S_u%02d",n + -1);
    Reload(&self->bg,self->bgCache,self->nameBuf,&self->bgParam);
  }
  FUN_0015a62c(self);
  if (notify != 0) {
    FUN_001b3378(&DAT_0034179c,0);
  }
  FUN_0001cb88(&DAT_0030ebf4);
}
