/* HSTMATCH module=EBOOT.BIN start=0x0005cfb4 end=0x0005d0e4 symbol=FUN_0005cfb4 lang=c++ */

extern "C" {
void *FUN_00000a90(unsigned int size);
}

struct Alloc {};
struct Container;

extern "C" {
unsigned int FUN_0005d0e4(Container *param_1, int **param_2);
void FUN_0005da00(void *vec, const unsigned int *item, Alloc a);
}

struct Vector {
    unsigned int *data;
    unsigned int size;
    unsigned int cap;
    void push_back(const unsigned int &x)
    {
        if (size < cap) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_0005da00(this, &x, Alloc());
        }
    }
};

struct Container {
    unsigned char flag;
    char pad0[3];
    unsigned int f4;
    Vector vec;
    int f14;
    int *f18;
    int *f1c;
    int *f20;
};

extern "C" void FUN_0005cfb4(Container *param_1, int *param_2)
{
    unsigned int local_4;
    int *local_10 = param_2;

    param_1->flag = 0;
    param_1->f4 = FUN_0005d0e4(param_1, &local_10);

    int count = *local_10++;
    param_1->f20 = (int *)FUN_00000a90(count << 2);

    for (int i = 0; i < count; i++) {
        local_4 = FUN_0005d0e4(param_1, &local_10);
        param_1->vec.push_back(local_4);
        param_1->f20[i] = -1;
    }

    param_1->f14 = *local_10++;
    param_1->f18 = local_10;
    local_10 += param_1->f14;
    param_1->f1c = local_10;
    local_10 += param_1->f14;
}

// Differing instructions (~2-3 logical words differ):
// 1. +0x74..+0x9c: In the inlined vector push_back, retail emits 'beqzl at, 0x5de18; move v0, zero'
//    and at 0x5de18 'seb a2, v0; addiu a0, s3, 8; jal 0x5e81c; addiu a1, sp, 44'.
//    Our compilation emits 'beqzl at, 0x9c; addiu a0, s3, 8' and moves 'addiu a1, sp, 44' before jal.
// Ruled out:
// - #pragma opt_strength_reduction off (destroys induction variable allocation in the loop).
// - Passing 0 directly as signed char / int instead of empty struct Alloc.
// - Manual pointer arithmetic on the vector data array vs push_back inline member function.
// near miss from lane u1r5-3 (unreviewed)
// EBOOT copy of the Sharing wip (0x0005dd7c): header/symbol re-addressed, calls retargeted
// FUN_0005deac -> FUN_0005d0e4, FUN_0005e81c -> FUN_0005da00. Result is identical to the twin: 76/76 words,
// 39 differ. Two groups: (a) 5 words of stack-slot offsets (ours `local_10` at 40(sp), retail 32(sp); the
// `local_4` temp is 44(sp) in both, so retail keeps 8 bytes between them - an extra empty-tag/temp slot ours lacks;
// declaring local_10 first (41 words) or dropping local_4 is worse/it is used); (b) ~34 words of loop register
// naming (ours a0/v1 vs retail v1/v0, `li a1,-1` vs `li a0,-1`).
// near miss from lane rt1 (unreviewed)
