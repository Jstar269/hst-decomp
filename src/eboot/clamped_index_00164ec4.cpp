/* HSTMATCH module=EBOOT.BIN start=0x00164ec4 end=0x00164f64 symbol=FUN_00164ec4 lang=c++ */
/* Clone of src/eboot/clamped_index_00164c60.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x341510
   (count at +4) and clamp it to [global minimum 0x2e03bc, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_00164958(void);
struct Table_00164ec4 { void *data; unsigned count; };
extern "C" Table_00164ec4 *DAT_00341510;
extern "C" int DAT_002e03bc;
inline unsigned Clamp_00164ec4(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00164ec4(void)
{
    float t = 1.0f - FUN_00164958();
    unsigned n = DAT_00341510->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00164ec4(idx, DAT_002e03bc, n - 2);
}
