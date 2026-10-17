/* HSTMATCH module=hstp_trans_main.prx start=0x00171154 end=0x001711f4 symbol=FUN_00171154 lang=c++ */
/* Clone of src/eboot/clamped_index_00164c60.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map the normalised position from 0x1646a0 (inverted, 1 - t) onto an index of the table behind 0x3ea850
   (count at +4) and clamp it to [global minimum 0x38797c, count - 2]. The clamp must take lo/hi by const
   reference (inline): that gives retail's second, separate load of the minimum for the return value.
   Names provisional. */
extern "C" float FUN_00170db0(void);
struct Table_00171154 { void *data; unsigned count; };
extern "C" Table_00171154 *DAT_003ea850;
extern "C" int DAT_0038797c;
inline unsigned Clamp_00171154(int v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" unsigned FUN_00171154(void)
{
    float t = 1.0f - FUN_00170db0();
    unsigned n = DAT_003ea850->count;
    int idx = (int)(t * (float)(n - 1));
    return Clamp_00171154(idx, DAT_0038797c, n - 2);
}
