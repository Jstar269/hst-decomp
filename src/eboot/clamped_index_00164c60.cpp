/* HSTMATCH module=EBOOT.BIN start=0x00164c60 end=0x00164d00 symbol=FUN_00164c60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x341510
   (count at +4) and clamp it to [global minimum 0x2e03b0, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_001646a0(void);
struct Table_00164c60 { void *data; unsigned count; };
extern "C" Table_00164c60 *DAT_00341510;
extern "C" int DAT_002e03b0;
inline unsigned Clamp_00164c60(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00164c60(void)
{
    float t = 1.0f - FUN_001646a0();
    unsigned n = DAT_00341510->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00164c60(idx, DAT_002e03b0, n - 2);
}
