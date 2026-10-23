/* HSTMATCH module=EBOOT.BIN start=0x000ca9c8 end=0x000cabe0 symbol=FUN_000ca9c8 lang=c99 rodata=0x002c0400 */
extern int DAT_003386b0;

void FUN_000ca9c8(int p, int i)
{
    int v;

    v = *(int *)(DAT_003386b0 + i * 4 + 0x70);
    if (v == 0)
        return;
    if (*(int *)(v + 0x3c) == 3) {
        *(int *)(i * 0x10 + p + 0x84) = 0;
        *(int *)(i * 0x10 + p + 0x88) = 1;
    } else {
        *(int *)(i * 0x10 + p + 0x84) = *(int *)(v + 0x4e4);
        *(int *)(i * 0x10 + p + 0x88) = *(int *)(v + 0x4e8);
    }
    switch (*(int *)(i * 0x10 + p + 0x88)) {
    case 0:
        if (*(int *)(i * 0x10 + p + 0x84) == 2) {
            *(int *)(i * 0x10 + p + 0x8c) = 2;
            *(int *)(i * 0x10 + p + 0x90) = 0xc;
        } else if (*(int *)(i * 0x10 + p + 0x84) == 1) {
            *(int *)(i * 0x10 + p + 0x8c) = 1;
            *(int *)(i * 0x10 + p + 0x90) = 0xb;
        } else if (*(int *)(i * 0x10 + p + 0x84) == 0) {
            if (*(unsigned char *)(v + 0x4d8) == 0) {
                *(int *)(i * 0x10 + p + 0x8c) = 8;
                *(int *)(i * 0x10 + p + 0x90) = 0x12;
            } else {
                *(int *)(i * 0x10 + p + 0x8c) = 6;
                *(int *)(i * 0x10 + p + 0x90) = 0x10;
            }
        }
        break;
    case 1:
        *(int *)(i * 0x10 + p + 0x8c) = 5;
        *(int *)(i * 0x10 + p + 0x90) = 0xf;
        break;
    case 2:
        *(int *)(i * 0x10 + p + 0x8c) = 4;
        *(int *)(i * 0x10 + p + 0x90) = 0xe;
        break;
    case 3:
        *(int *)(i * 0x10 + p + 0x8c) = 0;
        *(int *)(i * 0x10 + p + 0x90) = 10;
        break;
    case 4:
        *(int *)(i * 0x10 + p + 0x8c) = 9;
        *(int *)(i * 0x10 + p + 0x90) = 0x13;
        break;
    case 5:
        *(int *)(i * 0x10 + p + 0x8c) = 9;
        *(int *)(i * 0x10 + p + 0x90) = 0x2e;
        break;
    case 6:
        *(int *)(i * 0x10 + p + 0x8c) = 1;
        *(int *)(i * 0x10 + p + 0x90) = 0x2f;
        break;
    case 7:
        *(int *)(i * 0x10 + p + 0x8c) = 3;
        *(int *)(i * 0x10 + p + 0x90) = 0xd;
        break;
    case 8:
    case 9:
    case 10:
        *(int *)(i * 0x10 + p + 0x8c) = 7;
        if (*(int *)(i * 0x10 + p + 0x84) == 0)
            *(int *)(i * 0x10 + p + 0x90) = 0x11;
        else
            *(int *)(i * 0x10 + p + 0x90) = 0x2d;
        break;
    case 11:
        *(int *)(i * 0x10 + p + 0x8c) = 3;
        *(int *)(i * 0x10 + p + 0x90) = 0xd;
        break;
    case 12:
        *(int *)(i * 0x10 + p + 0x8c) = 3;
        *(int *)(i * 0x10 + p + 0x90) = 0x30;
        break;
    }
}

// 134/134 words. Only the temp registers differ: base is a1 here, t1 there; the two
// derived pointers are (t0,a1) here and (a2,t0) in retail - the same three addiu/sw
// sequence in the same order. Writing `int base = i*0x10 + p;` once (draft 1) makes
// MWCC hoist the base and shrink the function to 114 words; every case body must
// recompute `i * 0x10 + p + off` itself (Ghidra's literal form) to get 134.
// near miss from lane fm8 (unreviewed)
