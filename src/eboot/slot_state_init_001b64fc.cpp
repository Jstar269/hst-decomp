/* HSTMATCH module=EBOOT.BIN start=0x001b64fc end=0x001b66bc symbol=FUN_001b64fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the inline Clamp takes the value by const reference too (a by-value argument is loaded before the first lo load), and the switch cases are written 0x2a, 0x44, 0x35 (tests are emitted in reverse source order). */

#include "hst/state_obj.h"

extern "C" {
extern int DAT_0034a678;
extern int DAT_002e99cc;
extern int DAT_002e99d0;
extern char DAT_00341c50;
extern char DAT_00341c51;
extern unsigned char DAT_003386b8;
extern int DAT_003417c4;
extern int DAT_00341ccc;
extern char DAT_0034179c;
void FUN_001b38dc(void *p, int v);
void FUN_001b3bac(void *p, int a, int b);
void FUN_001b4dfc(int v);
unsigned char FUN_0022c860(void);
unsigned char FUN_0022c878(void);
}

inline int Clamp(const char &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

/* Resets the state object: sets the mode flags from the current mode id (0x2a, 0x44 or 0x35), pushes the
   mode and a count to the sound manager and marks every handle as unused. */
extern "C" void FUN_001b64fc(StateObj *self)
{
    int mode;
    int idx;
    int cnt;
    self->unk90 = 0;
    self->unk91 = 0;
    self->unk92 = 0;
    self->unk93 = 0;
    self->unk94 = 0;
    mode = 0;
    switch (DAT_0034a678) {
    case 0x2a:
        self->unk90 = 1;
        self->unk93 = FUN_0022c860();
        self->unk94 = FUN_0022c878();
        if (self->unk93 != 0) {
            mode = 2;
        } else if (self->unk94 != 0) {
            mode = 1;
        }
        break;
    case 0x44:
        self->unk91 = 1;
        mode = 3;
        break;
    case 0x35:
        self->unk92 = 1;
        break;
    }
    FUN_001b38dc(&DAT_0034179c, mode);
    idx = DAT_00341c50;
    cnt = (char)Clamp(DAT_00341c51, DAT_002e99cc, DAT_002e99d0);
    if (DAT_003386b8 != 0) {
        cnt = 0;
        FUN_001b4dfc(DAT_003417c4);
    } else {
        if (self->unk93 != 0 || self->unk94 != 0) {
            cnt = 1;
        } else if (*(char *)(idx + DAT_00341ccc + 0x104a) < 5) {
            cnt = 1;
        }
    }
    FUN_001b3bac(&DAT_0034179c, idx, cnt);
    self->handle4c = HANDLE_NONE;
    self->handle50 = HANDLE_NONE;
    self->handle54 = HANDLE_NONE;
    self->handle58 = HANDLE_NONE;
    self->handle64 = HANDLE_NONE;
    self->unk80 = 0;
}
