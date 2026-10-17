/* HSTMATCH module=EBOOT.BIN start=0x0027d0e0 end=0x0027d120 symbol=FUN_0027d0e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002fe6d4;
struct Obj {
    char pad[0x3c];
    float f3c;
    int i40;
    int i44;
    int i48;
};
inline const int &max_ref(const int &a, const int &b) { return (a < b) ? b : a; }
extern "C" void FUN_0027d0e0(Obj *o, float x, int n)
{
    o->f3c = x;
    int m = max_ref(n, DAT_002fe6d4);
    o->i48 = m;
    o->i44 = m;
}
