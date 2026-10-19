/* HSTMATCH module=EBOOT.BIN start=0x00098b64 end=0x00098c3c symbol=FUN_00098b64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r[4]; };

extern "C" void FUN_00091dd8(float, void *, int, int, int, int, float);
extern "C" void FUN_0009f0ec(Vec4 *, void *);
extern "C" void *FUN_00093818(void *);
extern "C" void FUN_0004d268(Mat4 *, void *);
extern "C" void FUN_00022548(Vec4 *, Mat4 *, Vec4 *);

extern "C" void FUN_00098b64(char *o) {
    Vec4 a;
    Mat4 ma;
    Vec4 b;
    Mat4 mb;

    FUN_00091dd8(11.0f, *(void **)(o + 0x5bc), 150, 0, 151, 0, 11.0f);
    FUN_0009f0ec(&a, o);
    FUN_0004d268(&ma, FUN_00093818(*(void **)(o + 0x5bc)));
    FUN_00022548((Vec4 *)(o + 2000), &ma, &a);
    *(int *)(o + 2000) = 0;
    *(int *)(o + 0x7d8) = 0;

    FUN_00091dd8(11.0f, *(void **)(o + 0x5bc), 136, 0, 137, 0, 11.0f);
    FUN_0009f0ec(&b, o);
    FUN_0004d268(&mb, FUN_00093818(*(void **)(o + 0x5bc)));
    FUN_00022548((Vec4 *)(o + 0x7e0), &mb, &b);
    *(int *)(o + 0x7e0) = 0;
    *(int *)(o + 0x7e8) = 0;
}
