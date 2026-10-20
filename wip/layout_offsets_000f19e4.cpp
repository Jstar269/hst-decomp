/* HSTMATCH module=EBOOT.BIN start=0x000f19e4 end=0x000f1ad4 symbol=FUN_000f19e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" float DAT_002d7800;

extern "C" void FUN_0010e5b8(int, int, int, int, int, int, int, int);

extern "C" void FUN_000f19e4(float f, char *o) {
    char *e;
    short old;
    short nv;
    float v = f * DAT_002d7800;
    *(float *)(o + 0x80) = v;
    FUN_0010e5b8(*(int *)(o + 0x6c), 0, 0, (int)(v + 51.0f), 13, 0, 0, 3);
    e = *(char **)(o + 0x58);
    old = *(short *)(e + 4);
    nv = (short)(int)(*(float *)(o + 0x70) + *(float *)(o + 0x80) / 3.0f);
    *(short *)(e + 4) = nv;
    *(short *)(e + 8) = (short)(*(short *)(e + 8) + (short)(nv - old));
    e = *(char **)(o + 0x5c);
    old = *(short *)(e + 4);
    nv = (short)(int)(*(float *)(o + 0x70) + (*(float *)(o + 0x80) / 3.0f) * 2.0f);
    *(short *)(e + 4) = nv;
    *(short *)(e + 8) = (short)(*(short *)(e + 8) + (short)(nv - old));
}
// near miss from lane ds7 (unreviewed)
