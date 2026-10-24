/* HSTMATCH module=EBOOT.BIN start=0x001aa2a4 end=0x001aa450 symbol=FUN_001aa2a4 lang=c++ */

struct Obj {
    virtual void s0();
    virtual void s1(int);
    char pad[0xf8 - 4];
    int f_f8;
    char pad2[0x138 - 0xfc];
    int f_138;
};

struct Rec12 {
    int a;
    Obj *w;
    int c;
};

struct Block {
    char pad[0x330];
    void *f330;
    char pad2[0x390 - 0x334];
    void *f390;
};

struct Holder {
    void *w;
    int pad[4];
    void Set(int v);
};

extern "C" {
extern Block *FUN_0019d474();
extern void FUN_000ffb3c(void *, int);
extern void FUN_0010d4a8(void *);
extern int FUN_001fecb4(int);

inline void Holder::Set(int v) { FUN_000ffb3c(w, v); }

void FUN_001aa2a4(char *param_1) {
    Holder *item_ptr;
    Rec12 *rec;
    int count;
    int j;
    int valA;
    char *p2;
    int s1;
    int local_4;

    void *v390 = &FUN_0019d474()->f390;
    void *v330 = &FUN_0019d474()->f330;

    int i = 0;
    char *p_slot = param_1;
    char *p_item = param_1;
    do {
        (*(Obj **)(p_slot + 0x3d0))->s1(1);
        FUN_000ffb3c(*(void **)(p_item + 0xd4), 1);
        i++;
        p_slot += 12;
        p_item += 20;
    } while (i < 2);

    count = 0;
    local_4 = 0;
    p2 = param_1;
    s1 = 0;
    do {
        j = 0;
        do {
            int off_row = local_4 * 12;
            int off_col = j * 4;
            int *rowB = *(int **)((char *)*(void **)v330 + off_row);
            if (*(int *)((char *)rowB + off_col) != 0) {
                int *rowA = *(int **)((char *)*(void **)v390 + off_row);
                int off = s1 + 180;
                item_ptr = (Holder *)(param_1 + off + 32);
                valA = *(int *)((char *)rowA + off_col);
                rec = (Rec12 *)(p2 + 0x3cc);
                rec->w->s1(0);
                int res = FUN_001fecb4(valA);
                Obj *sub = rec->w;
                sub->f_f8 = res;
                sub->f_138 = 1;
                FUN_0010d4a8(sub);
                item_ptr->Set(0);
                count++;
                p2 += 12;
                if (count >= 2) break;
                s1 += 20;
            }
            j++;
        } while (j < 3);
        if (count >= 2) return;
        local_4++;
    } while (local_4 < 2);
}
}

// Near miss: 70 differing words out of 107.
// First 36 words (+0x00 to +0x90) match retail 100% (prologue and Loop 1).
// In Loop 2, retail recomputes local_4 * 12 via sll/addu/sll and j * 4 via sll each iteration,
// keeping local_4, v390, and v330 on the stack while allocating 8 callee-saved registers:
// s7 = item_ptr, s6 = rec, s5 = count, s4 = j, s3 = valA, s2 = p2, s1 = s1, s0 = off_row.
// In our compile, MWCC's strength reduction pass introduces induction variables for local_4 * 12
// and j * 4, shifting register coloring in Loop 2.
// Ruled out: #pragma opt_strength_reduction off (causes v390 to take s8 and shifts all registers),
// (unsigned) casts on indices, manual array/pointer indexing permutations.
// near miss from lane ag3 (unreviewed)
