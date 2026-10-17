/* HSTMATCH module=hstp_trans_main.prx start=0x00171014 end=0x001710b4 symbol=FUN_00171014 lang=c++ */
/* Clone of src/eboot/clamped_index_00164c60.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x3ea850
   (count at +4) and clamp it to [global minimum 0x387974, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_00170c70(void);
struct Table_00171014 { void *data; unsigned count; };
extern "C" Table_00171014 *DAT_003ea850;
extern "C" int DAT_00387974;
inline unsigned Clamp_00171014(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00171014(void)
{
    float t = 1.0f - FUN_00170c70();
    unsigned n = DAT_003ea850->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00171014(idx, DAT_00387974, n - 2);
}
