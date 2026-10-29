/* HSTMATCH module=EBOOT.BIN start=0x0016bdc4 end=0x0016bee8 symbol=FUN_0016bdc4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: C++ with prototyped float parameters (65535.0f/-1.0f in f12/f13), the byte flag is unsigned char (lbu), and the two zeroed 16-byte argument temporaries are `Zero4()` objects (user ctor) with aligned(16), which leaves retail 8-byte hole above them; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ctl_obj.h"

struct Cam { char pad[0xc]; float f0c; };
struct Zero4 { int x, y, z, w; Zero4() : x(0), y(0), z(0), w(0) {} } __attribute__((aligned(16)));
extern "C" {
extern Cam *DAT_00331b84;
extern CtlObj *DAT_0034a820;
extern int DAT_0034a678;
void FUN_00063830(float, float, Cam *, const Zero4 &, const Zero4 &, int, int, int);
void FUN_001ff5f0(unsigned char *, int *);
void FUN_00292e40(CtlObj *, int);
void FUN_002930c8(float, CtlObj *, int);
}

/* For scene id 0x24 or 0x27 (and a matching current scene), reads a pending value; if one is ready, applies it to the control object and restarts it. Then issues the fixed call with two zero vectors. */
extern "C" void FUN_0016bdc4(int scene)
{
    unsigned char ready = 0;
    int value = 0;
    if (scene == 0x24) {
        if (DAT_0034a678 - 0x25U < 2 && DAT_0034a820 != 0)
            FUN_001ff5f0(&ready, &value);
    } else if (scene == 0x27 && DAT_0034a678 == 0x27 && DAT_0034a820 != 0) {
        FUN_001ff5f0(&ready, &value);
    }
    if (ready != 0) {
        FUN_00292e40(DAT_0034a820, value);
        FUN_002930c8(65535.0f, DAT_0034a820, 1);
    }
    FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Zero4(), Zero4(), 10, 0, 0);
}
