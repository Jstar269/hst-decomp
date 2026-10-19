/* HSTMATCH module=hstp_trans_main.prx start=0x0009ada8 end=0x0009ae80 symbol=FUN_0009ada8 lang=c++ */
/* Clone of src/eboot/init_two_vectors_00098b64.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r[4]; };

extern "C" void FUN_00093a70(float, void *, int, int, int, int, float);
extern "C" void FUN_000a1698(Vec4 *, void *);
extern "C" void *FUN_0009573c(void *);
extern "C" void FUN_0004d5e0(Mat4 *, void *);
extern "C" void FUN_00022570(Vec4 *, Mat4 *, Vec4 *);

extern "C" void FUN_0009ada8(char *o) {
    Vec4 a;
    Mat4 ma;
    Vec4 b;
    Mat4 mb;

    FUN_00093a70(11.0f, *(void **)(o + 0x5bc), 150, 0, 151, 0, 11.0f);
    FUN_000a1698(&a, o);
    FUN_0004d5e0(&ma, FUN_0009573c(*(void **)(o + 0x5bc)));
    FUN_00022570((Vec4 *)(o + 2000), &ma, &a);
    *(int *)(o + 2000) = 0;
    *(int *)(o + 0x7d8) = 0;

    FUN_00093a70(11.0f, *(void **)(o + 0x5bc), 136, 0, 137, 0, 11.0f);
    FUN_000a1698(&b, o);
    FUN_0004d5e0(&mb, FUN_0009573c(*(void **)(o + 0x5bc)));
    FUN_00022570((Vec4 *)(o + 0x7e0), &mb, &b);
    *(int *)(o + 0x7e0) = 0;
    *(int *)(o + 0x7e8) = 0;
}
