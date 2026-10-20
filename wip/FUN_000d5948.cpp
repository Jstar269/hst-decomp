/* HSTMATCH module=EBOOT.BIN start=0x000d5948 end=0x000d5a84 symbol=FUN_000d5948 lang=c++ */
struct Tag_000d5948 {};
struct Vec_000d5948 { int *data; int size; int cap; };
struct Vec3 { float x, y, z; };
struct Buf {
    Vec3 p;
    Vec_000d5948 v;
};
extern "C" void FUN_00003ed4(Buf *, int);
extern "C" void FUN_00003370(Buf *, int, int, int, int, Tag_000d5948);
extern "C" void FUN_000c4450(Vec_000d5948 *, int, Tag_000d5948);
extern "C" void FUN_000111c0(int *, int *, int);

extern "C" Buf *FUN_000d5948(Buf *param_1, Buf *param_2)
{
    Tag_000d5948 tag;
    Buf *self = param_1;
    Vec_000d5948 &dst = self->v;
    if ((*(int *)&param_2->p.x & 1) == 0) {
        self->p = param_2->p;
    } else {
        self->p.x = 0.0f;
        self->p.y = 0.0f;
        self->p.z = 0.0f;
        FUN_00003ed4(self, *(int *)&param_2->p.y);
        FUN_00003370(self, 0, 0, *(int *)&param_2->p.z, *(int *)&param_2->p.z + *(int *)&param_2->p.y, tag);
    }
    dst.data = 0;
    dst.size = 0;
    dst.cap = 0;
    int *start = param_2->v.data;
    int *end = param_2->v.data + param_2->v.size;
    if (end - start != 0) {
        FUN_000c4450(&dst, end - start, tag);
        FUN_000111c0(dst.data + dst.size, start, (end - start) * 4);
        dst.size = dst.size + (end - start);
    }
    return self;
}
// near miss from lane bp1018ar1-0 (unreviewed); 68/79 words, first at +0x8.
// retail: frame=48, saved ra+s0..s4 (5 s-regs), tag@44(sp); keeps the vector
//   `end` pointer (s1) live across both calls (recomputes end-data twice) while
//   my source folds `end = data + size` and uses only 4 s-regs (frame=32).
//   Retail also batches the 3-float copy (lwc1 f2,f1,f0 then swc1 f2,f1,f0);
//   my source emits interleaved lwc1/swc1 through a single $f0 (unresolved).
// near miss from lane bp1018ar1-0 (unreviewed)
