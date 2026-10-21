/* HSTMATCH module=EBOOT.BIN start=0x001c184c end=0x001c19e4 symbol=FUN_001c184c lang=c++ */
struct Rec12 {
    unsigned short a, b, c, d;
    unsigned char e, f, g;
};

struct Hdr {
    char pad0;
    unsigned char idx;
    short s;
    float f;
    Rec12 recs[1];
};

struct Sub80 {
    char pad0[0x1025];
    unsigned char tbl[15];
};

struct Globals {
    char pad0[0x80];
    Sub80 sub;
    char pad1[0x10be - 0x80 - 0x1025 - 15];
    unsigned short id;
    char pad2[0x10d4 - 0x10c0];
    int v10d4;
};

struct Info {
    char pad[0x68];
    int f68;
};

extern Globals *DAT_003415a8;
extern int DAT_0034a77c;

extern "C" {
Info *FUN_00193474(unsigned);
int FUN_001fea10(int, int, unsigned);
int FUN_0016bb98(unsigned, void *);
int FUN_0024dd40(float, int);
void FUN_001c1c50(int, int, unsigned, unsigned short, unsigned short, unsigned short, unsigned short, short,
                  bool, bool, bool, int, int, int, unsigned, void *, unsigned char, int, int, int, int, int,
                  int, int, Info *);
}

extern "C" void FUN_001c184c(int param_1, Hdr *hdr, int param_3)
{
    unsigned id = DAT_003415a8->id;
    if (id != 0x7fff && id != 0x7ffe) {
        short s = hdr->s;
        Rec12 *r = &hdr->recs[hdr->idx];
        Info *info = FUN_00193474(id);
        int v10d4 = DAT_003415a8->v10d4;
        unsigned char flag;
        Sub80 *sub = &DAT_003415a8->sub;
        if ((int)id >= 0 && (int)id < 15) {
            flag = sub->tbl[id];
        } else {
            flag = 1;
        }
        int a = FUN_001fea10(12, 0, id);
        int b = FUN_0016bb98(id, &info->f68);
        int c = FUN_0024dd40(hdr->f, DAT_0034a77c);
        FUN_001c1c50(2, a, id, r->a, r->b, r->c, r->d, s, r->f != 0, r->g != 0, r->e != 0, param_3, v10d4, b, id,
                     (char *)info + 0x68, flag, 0, 0, c, 0, param_1, 0, 0, info);
    }
}
// Near miss (104 vs 102 words, sn5): the whole body and call sequence is right (25-argument call: 8 register args a0-a3,t0-t3 and 17 stack args,
// the flag table read through `Sub80 *sub = &G->sub` declared before the id range test so that `addiu v0,v0,128` sits in the bltz slot, signed
// range test `(int)id >= 0 && (int)id < 15` on an unsigned id, `&info->f68` for the first +0x68 so it is not CSE'd with the later `(char *)info + 0x68`).
// The only real difference is the spill choice: retail keeps the G->0x10d4 value in s8 (`lw s8,4308(v0)` straight after `lw v0,G`) and spills the result
// of FUN_001fea10 (`sw v0,140(sp)` / `lw a1,140(sp)`); ours spills the 0x10d4 value (sw v0,140(sp) right after the load) and keeps the call result in
// s8, one extra word, and G is held in v1 instead of v0. Statement-order permutations of the eight locals (S,R,I,V,F,A,B,C) did not change the choice.
// near miss from lane sn5 (unreviewed)
