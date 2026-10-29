/* HSTMATCH module=EBOOT.BIN start=0x002a165c end=0x002a1738 symbol=FUN_002a165c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restructured the flag-state ladder into an if/else chain and regrouped the sum as s + (n*4+0xf) and typed the callee float parameters; readability pass; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern "C" void FUN_002a1398(AnimHost *o, int a, int b);
extern "C" void FUN_00058ddc(AnimHost *o, int a, int b);
extern "C" void FUN_00058f38(float f, AnimHost *o, int a);
extern "C" void FUN_00058ec4(float f, AnimHost *o, int a);
extern "C" void FUN_00059084(AnimHost *o, int a);

/* Sets the mode and starts the animation for it; the variant follows the two flag bytes. */
extern "C" void FUN_002a165c(AnimHost *host, int mode)
{
    int variant;
    if (host->flag_a != 0 && host->flag_b != 0) {
        variant = 2;
    } else if (host->flag_a != 0) {
        variant = 3;
    } else if (host->flag_b != 0) {
        variant = 1;
    } else {
        variant = 0;
    }
    if (mode != 0) {
        if (variant == 1) {
            variant = 0;
        } else if (variant == 2) {
            variant = 3;
        }
    }
    host->mode = mode;
    FUN_002a1398(host, 0, variant + (mode * 4 + HOST_ANIM_BASE));
    FUN_00058ddc(host, 0, 0);
    FUN_00058f38(0.0f, host, 0);
    FUN_00058ec4(1.0f, host, 0);
    FUN_00059084(host, 0);
}
