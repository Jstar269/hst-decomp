/* HSTMATCH module=EBOOT.BIN start=0x0017d910 end=0x0017dab8 symbol=FUN_0017d910 lang=c++ */
/* Hand-written reconstruction from the disassembly; near miss, names and types await human review. */
#pragma opt_strength_reduction off

inline void *operator new[](unsigned int, void *p) { return p; }

struct Sub { virtual void v0(); virtual void v1(); };
struct Item { char pad[0x10]; Sub sub; char pad1[0x54]; void *f68; };
struct Obj { char pad[8]; Item **f8; char pad1[0x2d8]; int f2e4; };

extern "C" {
int FUN_0016bb88(void);
int FUN_0016bc70(void);
int FUN_001fe984(void *param_1, int param_2, int param_3);
void FUN_000931ec(...);
float FUN_0017dab8(void *param_1, int param_2);
void FUN_00093484(void *param_1, float param_2);
void FUN_000575fc(...);
void FUN_0017d910(Obj *self, int param_2);
}

void FUN_0017d910(Obj *self, int param_2)
{
    int i;
    unsigned char flag = 0;
    int base = FUN_0016bb88();
    int c;
    if (param_2 >= 0 && param_2 < 15) {
        c = *(unsigned char *)(param_2 + base + 0x1025);
    } else {
        c = 1;
    }
    if (c == 2) {
        flag = 1;
    }

    i = 0;
    do {
        int ctx = FUN_0016bc70();
        int itemInfo = ((int (*)(int, int))(*(int *)(ctx + 0x3ec)))(param_2, i);
        unsigned char b1 = (*(unsigned char *)(itemInfo + 10) != 0);
        unsigned char b2 = (*(unsigned char *)(itemInfo + 9) != 0);

        if (FUN_001fe984(&self->f2e4, i, 0) == 0) {
            unsigned char flags[2];
            new (flags) unsigned char[2]();
            flags[0] = b2;
            flags[1] = b1;

            Item *item = self->f8[i];
            FUN_000931ec(&item->sub, 1, flags, flag);
            float f = FUN_0017dab8(self, i);
            FUN_00093484(&item->sub, f);
            item->sub.v1();
        }

        if (FUN_001fe984(&self->f2e4, i, 0) == 0) {
            Item *item = self->f8[i];
            void *sub68 = item->f68;
            if (sub68 != 0) {
                int k = 0;
                do {
                    FUN_000575fc(sub68, k, flag);
                    k++;
                } while (k < 6);
            }
        }
        i++;
    } while (i < 4);
}

// NEAR 106/106 words, 43 differ (sy3). Everything structural matches (c chain bltzl/slti/beqz, `new (flags) unsigned char[2]()` zero loop,
// Sub vtable slot 1 call via t9, loop shape). Left: retail normalises the flag IN PLACE with `andi s0,s0,0xff` after `if (c == 2) flag = 1;`
// (bnel slot + fallthrough, flag stays in s0, i = s1, self = s3, param_2 = s2); ours (unprototyped (...) callees, or bool/uchar/int flag) either
// emits no andi or puts the normalised copy in a fresh s5 so every other saved register shifts. Ruled out: int/bool/char/short/uint flag, bool params,
// `flag &= 0xff`, `flag = (unsigned char)flag`, `flag = (c==2)`, `(...)` prototypes.
// near miss from lane sy3 (unreviewed)
