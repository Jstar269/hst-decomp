/* HSTMATCH module=EBOOT.BIN start=0x00164e24 end=0x00164ec4 symbol=FUN_00164e24 lang=c++ */
/* Clone of src/eboot/clamped_index_00164c60.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x341510
   (count at +4) and clamp it to [global minimum 0x2e03b8, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_001647ec(void);
struct Table_00164e24 { void *data; unsigned count; };
extern "C" Table_00164e24 *DAT_00341510;
extern "C" int DAT_002e03b8;
inline unsigned Clamp_00164e24(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00164e24(void)
{
    float t = 1.0f - FUN_001647ec();
    unsigned n = DAT_00341510->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00164e24(idx, DAT_002e03b8, n - 2);
}
