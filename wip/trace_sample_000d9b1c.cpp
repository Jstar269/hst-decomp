/* NEAR 74/76 words, 72 differ from +0x0 (the frame). Best source for 0x000d9b1c.
   The body, the 3-short scan and all three float stores match exactly; the guard must
   be a C++ bool (`bool all = x == 0x7fff && y == 0x7fff && z == 0x7fff; if (all) return 0;`),
   which produces retail's xori/sltiu/xori chain, while the plain `||` form gives
   li/bne and the == && chain gives a shorter body.
   Remaining: (a) MWCC spills the first lookup and reloads it after the second call
   where retail loads it once into s1 and keeps it across the call (frame 32 with two
   saves vs retail's 48 with three); (b) the 0x338bxx constants come out lui+ori
   where retail has lui+addiu; (c) the second guard is bnel+b here, beq+nop there.
   Ruled out: void* or int locals, int found[2] array, early-return vs nested-if guard,
   pointer-typed fields. */
/* HSTMATCH module=EBOOT.BIN start=0x000d9b1c end=0x000d9c4c symbol=FUN_000d9b1c lang=c++ */
extern "C" void FUN_000d9d84(int *, int, short *);
extern "C" void FUN_000d9c4c(int *, int, int);

extern "C" int FUN_000d9b1c(float *out, short id, int param_3)
{
    short key = id;
    int obj;
    int ent;
    short *p;
    short x;
    short y;
    short z;

    FUN_000d9d84(&obj, 0x338b34, &key);
    if (obj == 0x338b38)
        return 0;
    FUN_000d9c4c(&ent, 0x338b18, param_3);
    if (ent == 0x338b1c)
        return 0;
    p = (short *)(*(int *)((char *)obj + 0x10) + *(short *)((char *)ent + 0x18) * 6);
    x = p[0];
    y = p[1];
    z = p[2];
    bool all = x == 0x7fff && y == 0x7fff && z == 0x7fff;
    if (all)
        return 0;
    out[0] = (float)x * 0.1f;
    out[1] = (float)y * 0.1f;
    out[2] = (float)z * 0.1f;
    return 1;
}
// improved by lane fm6 (unreviewed): no comparable result -> 72 differing words
