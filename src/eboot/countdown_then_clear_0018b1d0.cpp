/* HSTMATCH module=EBOOT.BIN start=0x0018b1d0 end=0x0018b2bc symbol=FUN_0018b1d0 lang=c++ data=0x002e0ba0 */
/* Hand-written reconstruction (port of src/sharing_main/countdown_then_clear_0019791c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e0ba0-0x002e0bae) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Cfg { char pad[0x8b]; signed char lo : 2; signed char mode : 2; };
struct Obj {
    char pad0[0x54];
    int f54;
    char pad1[0x60 - 0x58];
    int f60;
    char pad2[0x6c - 0x64];
    unsigned char f6c;
    unsigned char f6d;
    char pad3[0x70 - 0x6e];
    unsigned char f70;
};

extern "C" {
extern Cfg *DAT_002cfc8c;
extern int DAT_0034a114;
extern char DAT_0034179c[];
extern int FUN_001c6cf4(int);
extern void FUN_001b28f0(char *, char *);
extern void FUN_000114c0(void *, int, int);
extern void FUN_0018aa0c(Obj *, int);

void FUN_0018b1d0(Obj *o)
{
    if (o->f60 > 0) {
        o->f60 = o->f60 - 1;
    } else {
        if (DAT_002cfc8c->mode == 0 || (o->f6d != 0 && o->f70 != 0) || FUN_001c6cf4(DAT_0034a114) != 0) {
            FUN_001b28f0(DAT_0034179c, "lobby_textout");
            if (o->f6c != 0) {
                FUN_0018aa0c(o, 3);
            } else {
                int i = 0;
                char *p = (char *)o;
                do {
                    FUN_000114c0(p + 0x9c, 0, 0x400);
                    i++;
                    p += 0x400;
                } while (i < 3);
                o->f54 = 1;
            }
        }
    }
}
}
