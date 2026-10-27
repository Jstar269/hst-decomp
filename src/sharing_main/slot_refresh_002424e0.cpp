/* HSTMATCH module=hstp_trans_main.prx start=0x002424e0 end=0x00242658 symbol=FUN_002424e0 lang=c++ */
/* Clone of src/eboot/slot_refresh_002323e0.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the i == count-1 test goes through an int-returning inline helper (int->bool conversion gives retail's extra sltu); a direct bool comparison folds it. */
/* Per-slot state refresh over ten slots: four int[10] tables at +0x200/+0x228/+0x250/+0x278; the slot
   flag bytes live in the game record at DAT_003ea8e8 + 0x3500 + 0x8d00 (same bytes the predicates
   FUN_0023c3cc (bit 0), FUN_0023c5e0 (bit 1), FUN_0023c4c8 (bit 2) test). Names provisional. */
struct Save { char pad[0x8d00]; unsigned char flags[10]; };
struct Game { char pad[0x3500]; Save save; };
extern Game *DAT_003ea8e8;
extern int DAT_0039bf2c;
extern "C" int FUN_0023c4c8(int);
extern "C" int FUN_0023c5e0(int);
extern "C" int FUN_0023c3cc(int);
extern "C" int FUN_0023bca8(int);

struct Slots {
    char pad[0x200];
    int f200[10];
    int f228[10];
    int f250[10];
    int f278[10];
};

static inline int IsLast(int i) { return i == DAT_0039bf2c - 1; }

extern "C" void FUN_002424e0(Slots *self) {
    Save *save = &DAT_003ea8e8->save;
    for (int i = 0; i < 10; i++) {
        self->f228[i] = 0;
        bool skip = IsLast(i);
        bool flag = i == 8 && FUN_0023c4c8(7) && !FUN_0023c5e0(8);
        skip |= flag;
        if (!FUN_0023c3cc(i) || skip) {
            self->f200[i] = 0;
        } else if (!FUN_0023bca8(i)) {
            self->f200[i] = 1;
        } else if (!FUN_0023c5e0(i)) {
            self->f200[i] = 2;
        } else if (self->f228[i] < 100) {
            self->f200[i] = 3;
        } else {
            self->f200[i] = 5;
        }
        bool clear = !(save->flags[i] & 0x80);
        if (i != 0 && self->f200[i] == 2 && clear) {
            self->f200[i] = 4;
        }
        self->f250[i] = 0;
        self->f278[i] = 0;
    }
}
