/* HSTMATCH module=hstp_trans_main.prx start=0x0019791c end=0x00197a08 symbol=FUN_0019791c lang=c++ data=0x00388220 */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: typed the object and config structs (signed 2-bit mode bitfield), swapped the Ghidra if/else arms to the retail layout, passed the two string/data addresses by address; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388220-0x0038822e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern Cfg *DAT_003751d4;
extern int DAT_003f344c;
extern char DAT_003eaad8[];
extern int FUN_001d511c(int);
extern void FUN_001c0984(char *, char *);
extern void FUN_000114c0(void *, int, int);
extern void FUN_00197158(Obj *, int);

void FUN_0019791c(Obj *o)
{
    if (o->f60 > 0) {
        o->f60 = o->f60 - 1;
    } else {
        if (DAT_003751d4->mode == 0 || (o->f6d != 0 && o->f70 != 0) || FUN_001d511c(DAT_003f344c) != 0) {
            FUN_001c0984(DAT_003eaad8, "lobby_textout");
            if (o->f6c != 0) {
                FUN_00197158(o, 3);
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
