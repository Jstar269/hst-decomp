/* HSTMATCH module=EBOOT.BIN start=0x0015ba80 end=0x0015bc5c symbol=FUN_0015ba80 lang=c++ data=0x002de29c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002de29c-0x002de2f5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/loadmes_obj.h"

extern "C" {
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, const char *, ...);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001cad0(char *, int, char *);
extern void FUN_0001cb88(char *);
extern LoadMesRes *FUN_00050fc0(void *);
extern void FUN_000511c4(LoadMesRes *, char *, int);
extern void FUN_00051398(float, LoadMesRes *);
}

/* Size of one resource object. */
#define LOADMES_RES_SIZE 0x48

/* Rebuild a resource from the name in buf when the slot is empty or the cache says the name changed;
   the parameter vector is reset to (0, y, 0, 1). */
static inline void Reload(LoadMesRes **slot, char *cache, char *buf, Float4 *v, float y)
{
    if (*slot == 0 || FUN_00014934(cache, buf) != 0) {
        if (*slot != 0) {
            delete *slot;
            *slot = 0;
        }
        LoadMesRes *r = (LoadMesRes *)FUN_00000bcc(LOADMES_RES_SIZE);
        if (r != 0)
            r = FUN_00050fc0(r);
        *slot = r;
        FUN_000511c4(r, buf, 0);
        FUN_00051398(3000.0f, *slot);
        FUN_000149a8(cache, buf);
        v->x = 0;
        v->y = y;
        v->z = 0;
        v->w = 1.0f;
    }
}

/* Loads the tutorial menu: the background, then page `page` of the tutorial as the message resource. */
extern "C" void FUN_0015ba80(LoadMesObj *self, int page) {
    FUN_000143b0(self->nameBuf, "menu/020_tutorial.xb");
    FUN_0001cad0(DAT_0030ebf4, 1, self->nameBuf);
    FUN_000143b0(self->nameBuf, "data/menu/tutorial/tutorial_bg");
    Reload(&self->bg, self->bgCache, self->nameBuf, &self->bgParam, 0.0f);

    FUN_000143b0(self->nameBuf, "data/menu/tutorial/tutorial_%03d", page + 1);
    Reload(&self->message, self->msgCache, self->nameBuf, &self->msgParam, 15.0f);

    FUN_0001cb88(DAT_0030ebf4);
}
