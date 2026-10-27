/* HSTMATCH module=hstp_trans_main.prx start=0x001b9500 end=0x001b99f0 symbol=FUN_001b9500 lang=c++ rodata=0x002d5f14 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls slot 1 with 1 on all ten widgets, then with 0 on the set chosen by the game mode byte (+0x11c, read through
   the sub-object pointer at +0xf4, which retail keeps in s1) and the flag byte +0x3a1, and runs the per-slot helpers
   FUN_001b93f4 / FUN_001b8b60 for the same mode. Both switches list every label 0..5 (jump tables, the second's
   placed first in .rodata, hence rodata= that one); the flag is an `int` local (an unsigned char local is re-masked
   at every test). Same source as the EBOOT twin src/eboot/select_mode_widgets_001abe98.cpp. */
struct VC {
    virtual void s0();
    virtual void m(int);
};

struct Info {
    char pad0[0x28];
    unsigned char mode;     /* +0x28 (game +0x11c) */
};

struct Game {
    char pad0[0xf4];
    Info info;              /* 0xf4 */
    char pad11d[0x3a1 - 0x11d];
    unsigned char flag3a1;  /* 0x3a1 */
};

struct Self {
    int pad0;
    VC *w[10];              /* 0x04..0x28 */
};

extern "C" Game *FUN_001aa91c(void);
extern "C" void FUN_001b8b60(Self *, int);
extern "C" void FUN_001b93f4(Self *, int);

extern "C" void FUN_001b9500(Self *self)
{
    Info *info = &FUN_001aa91c()->info;
    int c = FUN_001aa91c()->flag3a1;

    self->w[0]->m(1);
    self->w[1]->m(1);
    self->w[2]->m(1);
    self->w[3]->m(1);
    self->w[4]->m(1);
    self->w[5]->m(1);
    self->w[6]->m(1);
    self->w[7]->m(1);
    self->w[8]->m(1);
    self->w[9]->m(1);
    switch (info->mode) {
    case 0:
    case 4:
        if (c != 0) {
            self->w[6]->m(0);
            self->w[9]->m(0);
        } else {
            self->w[0]->m(0);
            self->w[1]->m(0);
        }
        break;
    case 1:
    case 5:
        if (c != 0) {
            self->w[6]->m(0);
            self->w[7]->m(0);
            self->w[8]->m(0);
            self->w[9]->m(0);
        } else {
            self->w[2]->m(0);
            self->w[3]->m(0);
            self->w[4]->m(0);
            self->w[5]->m(0);
        }
        break;
    case 2:
        if (c != 0) {
            self->w[6]->m(0);
            self->w[7]->m(0);
            self->w[8]->m(0);
        } else {
            self->w[2]->m(0);
            self->w[3]->m(0);
            self->w[4]->m(0);
        }
        break;
    case 3:
        if (c != 0) {
            self->w[6]->m(0);
            self->w[8]->m(0);
            self->w[9]->m(0);
        } else {
            self->w[2]->m(0);
            self->w[4]->m(0);
            self->w[5]->m(0);
        }
        break;
    }
    switch (info->mode) {
    case 0:
    case 4:
        if (c != 0) {
            FUN_001b93f4(self, 0);
            FUN_001b93f4(self, 2);
        } else {
            FUN_001b8b60(self, 0);
            FUN_001b8b60(self, 2);
        }
        break;
    case 1:
    case 5:
        if (c != 0) {
            FUN_001b93f4(self, 0);
            FUN_001b93f4(self, 1);
            FUN_001b93f4(self, 2);
            FUN_001b93f4(self, 3);
        } else {
            FUN_001b8b60(self, 0);
            FUN_001b8b60(self, 1);
            FUN_001b8b60(self, 2);
            FUN_001b8b60(self, 3);
        }
        break;
    case 2:
        if (c != 0) {
            FUN_001b93f4(self, 0);
            FUN_001b93f4(self, 1);
            FUN_001b93f4(self, 2);
        } else {
            FUN_001b8b60(self, 0);
            FUN_001b8b60(self, 1);
            FUN_001b8b60(self, 2);
        }
        break;
    case 3:
        if (c != 0) {
            FUN_001b93f4(self, 0);
            FUN_001b93f4(self, 2);
            FUN_001b93f4(self, 3);
        } else {
            FUN_001b8b60(self, 0);
            FUN_001b8b60(self, 2);
            FUN_001b8b60(self, 3);
        }
        break;
    }
}
