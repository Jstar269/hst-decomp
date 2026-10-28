/* HSTMATCH module=hstp_trans_main.prx start=0x0001ebdc end=0x0001ec44 symbol=FUN_0001ebdc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    u32 timeStamp;
    union {
        u32 buttons;
        u16 buttons_u16[2];
    };
    union {
        struct {
            u8 lx;
            u8 ly;
        };
        u16 analog;
    };
    u8 rsrv[6];
} SceCtrlData;

extern int FUN_002c7830(SceCtrlData *pad, int n);

int FUN_0001ebdc(u16 *param_1)
{
    SceCtrlData pad;
    if (FUN_002c7830(&pad, 1)) {
        if ((pad.buttons & 0x20000) != 0) {
            pad.lx = 128;
            pad.ly = 128;
        }
        param_1[0] = pad.buttons_u16[0];
        param_1[1] = pad.analog;
        return 1;
    }
    return 0;
}
