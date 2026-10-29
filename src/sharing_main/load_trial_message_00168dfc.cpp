/* HSTMATCH module=hstp_trans_main.prx start=0x00168dfc end=0x0016916c symbol=FUN_00168dfc lang=c++ data=0x00385ad0 */
/* Hand-written reconstruction (port of src/eboot/load_trial_message_0015c854.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/loadmes_obj.h"

extern "C" {
extern char DAT_00385bd0[];
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001c684(void *a, int b, char *c);
void FUN_0001c73c(void *a);
void FUN_00166aa0(LoadMesObj *o, int n);
void FUN_00166c04(LoadMesObj *o);
void FUN_001c16b4(void *p, int n);
int FUN_00014934(char *cache, char *name);
void *FUN_00000bcc(unsigned n);
LoadMesRes *FUN_000518d4(void *p);
void FUN_00051ad8(LoadMesRes *r, char *name, int n);
void FUN_00051d38(float f, LoadMesRes *r);
void FUN_000149a8(char *cache, char *name);
extern char DAT_003b7ebc[];
extern char DAT_003eaad8[];
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
            r = FUN_000518d4(r);
        *slot = r;
        FUN_00051ad8(r, buf, 0);
        FUN_00051d38(3000.0f, *slot);
        FUN_000149a8(cache, buf);
        v->x = 0;
        v->y = 0;
        v->z = 0;
        v->w = 1.0f;
    }
}

/* Show trial message n: log the message file, (re)load the background for the tutorial and sale messages and
   the message resource for all of them. */
extern "C" void FUN_00168dfc(LoadMesObj *self, int n)
{
    const char *dir = "data/menu/";
    const char *names[TRIAL_MESSAGE_COUNT] = {
        "trial/trial_tutorial/usage", "trial/trial_loadmes/A04", "trial/trial_loadmes/A03",
        "trial/trial_loadmes/A00", "trial/trial_loadmes/A01", "trial/trial_loadmes/A02",
        "trial/trial_loadmes/A05", "trial/trial_sale/sale00", "trial/trial_loadmes/A06"};
    if (n != TRIAL_TUTORIAL && n != TRIAL_SALE)
        FUN_00166aa0(self, 0);
    FUN_000143b0(self->nameBuf, "menu/loadmes/trial/loadmes_t%02d.xb", n);
    FUN_0001c684(DAT_003b7ebc, 1, self->nameBuf);
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
        FUN_00166c04(self);
        FUN_001c16b4(DAT_003eaad8, 0);
    }
    FUN_0001c73c(DAT_003b7ebc);
}
