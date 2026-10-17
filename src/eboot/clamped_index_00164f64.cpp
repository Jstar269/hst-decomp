/* HSTMATCH module=EBOOT.BIN start=0x00164f64 end=0x00165004 symbol=FUN_00164f64 lang=c++ */
/* Clone of src/eboot/clamped_index_00164c60.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x341510
   (count at +4) and clamp it to [global minimum 0x2e03c0, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_00164ac4(void);
struct Table_00164f64 { void *data; unsigned count; };
extern "C" Table_00164f64 *DAT_00341510;
extern "C" int DAT_002e03c0;
inline unsigned Clamp_00164f64(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00164f64(void)
{
    float t = 1.0f - FUN_00164ac4();
    unsigned n = DAT_00341510->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00164f64(idx, DAT_002e03c0, n - 2);
}
