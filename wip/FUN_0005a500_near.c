/* HSTMATCH module=EBOOT.BIN start=0x0005a500 end=0x0005a648 symbol=FUN_0005a500 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *FUN_00000a90(unsigned n);
extern void *FUN_000008d8(void *mem, void *ctor, void *dtor, int size, int n);
extern void FUN_0005a648(void);

typedef struct Part {
    unsigned color;
    char pad[24];
} Part;

typedef struct Self {
    char pad[80];
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    Part *arr[2];
} Self;

void FUN_0005a500(Self *self, int a1, int a2, int a3, int a4)
{
    int i;
    int j;

    self->f50 = a1 != 0 ? 2 : 1;
    self->f54 = 0;
    self->f58 = a2;
    self->f5c = 0;
    self->f60 = 0x1fc;
    for (i = 0; i < self->f50; i++) {
        int n = self->f58;
        Part *p = (Part *)FUN_00000a90(n * sizeof(Part) + 16);

        p = (Part *)FUN_000008d8(p, &FUN_0005a648, 0, sizeof(Part), n);
        self->arr[i] = p;
        if (a4 == 0) {
            unsigned char *pc;
            if (a3 != 0) {
                unsigned char grey[8];
                grey[0] = 128;
                grey[1] = 128;
                grey[2] = 128;
                grey[3] = 255;
                pc = grey;
            } else {
                unsigned char white[4];
                white[0] = 255;
                white[1] = 255;
                white[2] = 255;
                white[3] = 255;
                pc = white;
            }
            unsigned color = *(unsigned *)pc;
            for (j = 0; j < self->f58; j++)
                self->arr[i][j].color = color;
        }
    }
}
// PARKED 2026-10-28 (8 compiles): 82/82 words, 25 differ. Full structure recovered: sets
// +80/+84/+88/+92/+96 (mode = a1?2:1, 0, count, 0, 0x1fc), then for i < self->f50:
// p = new Part[self->f58] (28-byte Part, ctor 0x5a648 via FUN_00000a90/FUN_000008d8 = the
// new[] cookie+__construct_new_array pair), self->arr[i] = p, and unless a4, fills every
// element's first word with 0x80808 0ff or 0xffffffff built by 4 byte-stores in two
// block-scoped char[4] arrays.
// REMAINING GAPS (2): (a) retail's frame has a never-written 4-byte slot at 44..48, pushing
// the two arrays to 40/36; ours puts them at 44/40 and nothing reproduces the slot (tried:
// `new Part[n]` in C++ -> frame 64 with s6/s7, worse; an inline helper with an empty Tag
// by value -> tag optimised away). (b) retail loads the colour (`lw v1,0(pc)`) once, AFTER
// the loop-guard's count load; a statement before the loop puts it first, a declaration
// inside the loop body is not hoisted.  Branch layout also inverts (retail falls through the
// grey arm, we fall through white).
// Phase-3 pass 5 (2026-10-28): 25 -> 14 differ. (1) the arrays must be `unsigned char` - a signed `char` array
// makes MWCC emit `li v1,-1` / `li v1,-128` where retail has `li v1,255` / `li v1,128` (same bytes, different
// immediate). (2) the missing 4-byte slot at 44..47 is the tail of an 8-byte grey array: `unsigned char grey[8]`
// (only 0..3 written) puts grey at 40 and white at 36 exactly like retail, with 44..47 reserved and never stored.
// LEFT: retail hoists the colour word load to between the guard's count load and the `blez` (`lw a0,88(s5);
// lw v1,0(v1); blez a0`); ours keeps it inside the loop body. Try a `unsigned *src = (unsigned *)pc;` walking
// pointer, or a statement placed between the guard and the loop.
// Phase-3 pass 6 (2026-10-28): 14 -> 9 differ. Hoisting the colour word out of the loop (`unsigned color =
// *(unsigned *)pc;` before the for) is what retail does; leaving the deref in the body does not get hoisted.
// LEFT: retail seeds the guard as `lw a0,88(s5); lw v1,0(v1); blez a0` (count first, colour second, colour in
// v1); ours loads the colour first and ends with colour in a0 / count in v1 - a pure seed/register swap.
// Ruled out: deref inside the body (14), walking `unsigned *src` (14), `int n = self->f58` hoisted bound (91).
// near miss from lane dsn2 (unreviewed)
