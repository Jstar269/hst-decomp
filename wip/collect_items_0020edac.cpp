/* HSTMATCH module=EBOOT.BIN start=0x0020edac end=0x0020f048 symbol=FUN_0020edac lang=c++ */
#pragma opt_strength_reduction off

typedef unsigned int uint;

struct Item {
    short id;
    short mode;
    short reqs[4];
};

struct ItemVec {
    Item *data;
    uint count;
    uint cap;
};

struct ShortVec {
    short *data;
    uint count;
    uint cap;
};

struct SubObj {
    char pad[0x14];
    char f14;
};

struct Player {
    char pad[0x158];
    int f158;
};

typedef int (*Pred)(Player *, int);

extern "C" {
SubObj *FUN_000b3c68(Player *);
int FUN_0020b62c(Player *);
}

extern "C" int FUN_0020edac(Player *self, short **out, int mode, ItemVec *items, ShortVec *extra, ShortVec *exclude, Pred pred)
{
    int total = 0;
    int c = FUN_000b3c68(self)->f14 - 1;
    int val = FUN_0020b62c(self);
    uint idx = 0;

    if (items->count != 0) {
        int c_off = c * 2;

        do {
            Item *item = &items->data[idx];
            int id = item->id;

            int ok = 1;
            for (uint i = 0; i < exclude->count; ++i) {
                if (id == exclude->data[i]) {
                    ok = 0;
                    break;
                }
            }

            if (ok != 0) {
                if (item->mode == mode && pred(self, id) != 0) {
                    int count = 0;
                    if (self->f158 == 0) {
                        short req = *(short *)((char *)item->reqs + c_off);
                        if (val < req) {
                            count++;
                        }
                    }
                    for (uint i = 0; i < extra->count; ++i) {
                        if (id == extra->data[i]) {
                            count++;
                        }
                    }
                    for (int j = 0; j < count; ++j) {
                        out[total++] = (short *)item;
                    }
                }
            }
            ++idx;
        } while (idx < items->count);
    }

    return total;
}

// Differing words: 32 words left out of 167 (166/167 words compiled):
// 1. At 0x0020eec4: retail emits `slt v0, v0, v1; bnezl v0, 0x20eed8; addiu a0, a0, 1`
//    whereas ours emits `slt at, v0, v1; beqzl at, 0x20eed8; addiu a0, a0, 1`.
// 2. In the tail loop at 0x0020efe4: retail has 6 instructions with pointer stepping `addiu a1, a1, 4`
//    whereas ours recomputes `sll + addu` inside the tail loop (5 instructions).
// The 1-word length difference displaces branch targets in the second half of the function.
// Ruled out:
// - Default opt_strength_reduction (shrinks function to 162 words and strength-reduces outer loop)
// - Declaring explicit destination pointer `short **p` (adds an extra s-register s1 and spills a parameter)
// - Outer `if (items->count == 0) return 0;` vs `for` (emits duplicate branches)
// near miss from lane ag2 (unreviewed)
