/* HSTMATCH module=EBOOT.BIN start=0x0015c854 end=0x0015cbc4 symbol=FUN_0015c854 lang=c++ data=0x002de514 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the nine message names are a local `const char *names[9]` initialiser (its strings and the pointer table are the anonymous .data placed with data=0x002de514), the directory string is a local pointer kept in s0 for the "%s%s" format, the reload helper is `static inline` with the merged-store form `r = alloc; if (r) r = ctor(r); *slot = r;`; names (from the message strings) and types await human review. */
#include "hst/loadmes_obj.h"

extern "C" {
extern char DAT_002de614[];
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001cad0(void *a, int b, char *c);
void FUN_0001cb88(void *a);
void FUN_0015a4c8(LoadMesObj *o, int n);
void FUN_0015a62c(LoadMesObj *o);
void FUN_001b3378(void *p, int n);
int FUN_00014934(char *cache, char *name);
void *FUN_00000bcc(unsigned n);
LoadMesRes *FUN_00050fc0(void *p);
void FUN_000511c4(LoadMesRes *r, char *name, int n);
void FUN_00051398(float f, LoadMesRes *r);
void FUN_000149a8(char *cache, char *name);
extern char DAT_0030ebf4[];
extern char DAT_0034179c[];
}

/* Number of trial messages (indices 0..8). */
enum { TRIAL_TUTORIAL = 0, TRIAL_SALE = 7, TRIAL_MESSAGE_COUNT = 9 };

/* Rebuild a resource from the name in buf when the slot is empty or the cache says the name changed. */
static inline void Reload(LoadMesRes **slot, char *cache, char *buf, Float4 *v)
{
    if (*slot == 0 || FUN_00014934(cache, buf) != 0) {
        if (*slot != 0) {
            delete *slot;
            *slot = 0;
        }
        LoadMesRes *r = (LoadMesRes *)FUN_00000bcc(0x48);
        if (r != 0)
            r = FUN_00050fc0(r);
        *slot = r;
        FUN_000511c4(r, buf, 0);
        FUN_00051398(3000.0f, *slot);
        FUN_000149a8(cache, buf);
        v->x = 0;
        v->y = 0;
        v->z = 0;
        v->w = 1.0f;
    }
}

/* Show trial message n: log the message file, (re)load the background for the tutorial and sale messages and
   the message resource for all of them. */
extern "C" void FUN_0015c854(LoadMesObj *self, int n)
{
    const char *dir = "data/menu/";
    const char *names[TRIAL_MESSAGE_COUNT] = {
        "trial/trial_tutorial/usage", "trial/trial_loadmes/A04", "trial/trial_loadmes/A03",
        "trial/trial_loadmes/A00", "trial/trial_loadmes/A01", "trial/trial_loadmes/A02",
        "trial/trial_loadmes/A05", "trial/trial_sale/sale00", "trial/trial_loadmes/A06"};
    if (n != TRIAL_TUTORIAL && n != TRIAL_SALE)
        FUN_0015a4c8(self, 0);
    FUN_000143b0(self->nameBuf, "menu/loadmes/trial/loadmes_t%02d.xb", n);
    FUN_0001cad0(DAT_0030ebf4, 1, self->nameBuf);
    if (n == TRIAL_TUTORIAL) {
        FUN_000143b0(self->nameBuf, "data/menu/trial/trial_tutorial/tutorial_bg");
        Reload(&self->bg, self->bgCache, self->nameBuf, &self->bgParam);
    } else if (n == TRIAL_SALE) {
        FUN_000143b0(self->nameBuf, "data/menu/trial/trial_sale/salebg");
        Reload(&self->bg, self->bgCache, self->nameBuf, &self->bgParam);
    }
    FUN_000143b0(self->nameBuf, "%s%s", dir, names[n]);
    Reload(&self->message, self->msgCache, self->nameBuf, &self->msgParam);
    if (n == TRIAL_SALE) {
        FUN_0015a62c(self);
        FUN_001b3378(DAT_0034179c, 0);
    }
    FUN_0001cb88(DAT_0030ebf4);
}
