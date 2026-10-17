/* HSTMATCH module=EBOOT.BIN start=0x00199398 end=0x0019953c symbol=FUN_00199398 lang=c++ */
/* Clone of src/sharing_main/state_countdown_update_001a5e8c.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
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
extern Cfg *DAT_002cfc8c;
extern char DAT_0034179c[];
extern void FUN_0001ebd4(void);
extern void FUN_001b2040(float, char *, int *);
extern int FUN_001b1c44(char *, int);
extern void FUN_00199754(Obj *, int);

void FUN_00199398(Obj *o)
{
    if (o->f1c != 5) FUN_0001ebd4();
    int state = o->f18;
    switch (state) {
    case 0:
    case 1:
        if ((DAT_002cfc8c->mode == 0 || DAT_002cfc8c->sel == 0) && o->f1c == 5) {
            FUN_001b2040(0.5f, DAT_0034179c, &o->f28);
            FUN_00199754(o, 2);
            break;
        }
        if (state == 0) {
            if (o->f1c == 5 && o->f20 == 5) o->f28 = FUN_001b1c44(DAT_0034179c, 0);
        }
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) FUN_00199754(o, o->f18 + 1);
        break;
    case 2:
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) {
            if (o->f1c == 0) o->f1c = 3;
            else o->f1c = o->f1c + 1;
            if (o->f1c == 6) o->f24 = 1;
            else FUN_00199754(o, 3);
        }
        break;
    case 3:
        o->f20 = o->f20 - 1;
        if (o->f20 == 0) FUN_00199754(o, 0);
        break;
    }
    FUN_0001ebd4();
}
}
