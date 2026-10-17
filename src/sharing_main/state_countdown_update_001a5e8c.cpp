/* HSTMATCH module=hstp_trans_main.prx start=0x001a5e8c end=0x001a6030 symbol=FUN_001a5e8c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cfg { char pad[0x8b]; signed char lo : 2; signed char mode : 2; signed char sel : 2; };
struct Obj {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    unsigned char f24;
    char pad1[0x28 - 0x25];
    int f28;
};

extern "C" {
extern Cfg *DAT_003751d4;
extern char DAT_003eaad8[];
extern void FUN_0001e7ac(void);
extern void FUN_001c00d4(float, char *, int *);
extern int FUN_001bfc3c(char *, int);
extern void FUN_001a6248(Obj *, int);

void FUN_001a5e8c(Obj *o)
{
    if (o->f1c != 5) FUN_0001e7ac();
    int state = o->f18;
    switch (state) {
    case 0:
    case 1:
        if ((DAT_003751d4->mode == 0 || DAT_003751d4->sel == 0) && o->f1c == 5) {
            FUN_001c00d4(0.5f, DAT_003eaad8, &o->f28);
            FUN_001a6248(o, 2);
            break;
        }
        if (state == 0) {
            if (o->f1c == 5 && o->f20 == 5) o->f28 = FUN_001bfc3c(DAT_003eaad8, 0);
        }
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) FUN_001a6248(o, o->f18 + 1);
        break;
    case 2:
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) {
            if (o->f1c == 0) o->f1c = 3;
            else o->f1c = o->f1c + 1;
            if (o->f1c == 6) o->f24 = 1;
            else FUN_001a6248(o, 3);
        }
        break;
    case 3:
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) FUN_001a6248(o, 0);
        break;
    }
    FUN_0001e7ac();
}
}
