/* HSTMATCH module=hstp_trans_main.prx start=0x0028e450 end=0x0028e490 symbol=FUN_0028e450 lang=c++ */
/* Clone of src/eboot/set_value_clamp_min_global_0027d0e0.cpp (hstclone.py tag c1707b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003a7454;
struct Obj {
    char pad[0x3c];
    float f3c;
    int i40;
    int i44;
    int i48;
};
inline const int &max_ref(const int &a, const int &b) { return (a < b) ? b : a; }
extern "C" void FUN_0028e450(Obj *o, float x, int n)
{
    o->f3c = x;
    int m = max_ref(n, DAT_003a7454);
    o->i48 = m;
    o->i44 = m;
}
