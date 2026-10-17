/* HSTMATCH module=EBOOT.BIN start=0x0001f004 end=0x0001f06c symbol=FUN_0001f004 lang=c99 */
/* Clone of src/sharing_main/read_ctrl_0001ebdc.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

typedef struct {
    uint timeStamp;
    union {
        uint buttons;
        ushort buttons_u16[2];
    };
    union {
        struct {
            uchar lx;
            uchar ly;
        };
        ushort analog;
    };
    uchar rsrv[6];
} SceCtrlData;

extern int FUN_002b7a90(SceCtrlData *pad, int n);

int FUN_0001f004(ushort *param_1)
{
    SceCtrlData pad;
    if (FUN_002b7a90(&pad, 1)) {
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
