/* HSTMATCH module=EBOOT.BIN start=0x0023e844 end=0x0023e930 symbol=FUN_0023e844 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Base {};
struct Tag : Base {};

struct Elem { float v[3]; };

extern "C" void FUN_00003ed4(void *, int);
extern "C" void FUN_00003370(void *, int, int, int, int, Tag);

extern "C" void FUN_0023e844(char *c, char *first, char *last) {
    char *dst = *(char **)c + *(int *)(c + 0x10) * 12;
    while (first < last) {
        dst -= 12;
        last -= 12;
        if (dst != 0) {
            if ((*(unsigned *)last & 1) == 0) {
                *(Elem *)dst = *(Elem *)last;
            } else {
                *(int *)dst = 0;
                *(int *)(dst + 4) = 0;
                *(int *)(dst + 8) = 0;
                FUN_00003ed4(dst, *(int *)(last + 4));
                FUN_00003370(dst, 0, 0, *(int *)(last + 8), *(int *)(last + 8) + *(int *)(last + 4), Tag());
            }
        }
        *(int *)(c + 0x10) = *(int *)(c + 0x10) - 1;
        *(int *)(c + 4) = *(int *)(c + 4) + 1;
    }
}
