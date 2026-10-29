/* HSTMATCH module=EBOOT.BIN start=0x002637c8 end=0x002638d8 symbol=FUN_002637c8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual call, declaration order for saved registers, field zeroing in call slot; readability pass; exact match verified; names and types await human review. */

#include "hst/screen_manager.h"

extern "C" {
extern char DAT_002fdeac[];
extern char DAT_002fdec4[];
extern char DAT_00309ae0[];
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_00010184(int a, int b);
extern void FUN_000104e0(void *p);
extern void FUN_0001bfb4(void *a, void *b, int c);
extern void FUN_0001cad0(void *a, int b, void *c);
extern void FUN_0001cb88(void *a);
extern void *FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void *FUN_0001f06c(void *self);
extern void FUN_00253da0(void);
extern void FUN_00258294(void *p);
extern ScreenObj *FUN_002638d8(void *p, void *name);
}

struct Target_002637c8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

/* Manager constructor: temporarily switch to a 3 MB scratch region, build the screen object there, then restore and start it. */
extern "C" void *FUN_002637c8(ScreenManager *self)
{
    void *scratch;
    void *saved_base;
    ScreenObj *screen;
    int saved_size;

    FUN_0001f06c(self);
    self->vtable = &DAT_00309ae0;
    self->screen = 0;
    scratch = FUN_00010184(64, 0x300000);
    FUN_0001bfb4(&DAT_0030ab9c, scratch, 0x300000);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002fdeac);

    screen = (ScreenObj *)FUN_00000bcc(sizeof(ScreenObj));
    if (screen != 0) {
        screen = FUN_002638d8(screen, DAT_002fdec4);
    }
    self->screen = screen;

    FUN_00253da0();
    FUN_0001cb88(&DAT_0030ebf4);
    saved_base = FUN_0001cbfc();
    saved_size = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c, saved_base, saved_size);

    if (scratch != 0) {
        FUN_000104e0(scratch);
    }

    FUN_00258294(self->screen);
    ((struct Target_002637c8 *)self->screen)->v6();

    return self;
}
