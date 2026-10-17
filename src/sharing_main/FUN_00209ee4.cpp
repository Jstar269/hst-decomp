/* HSTMATCH module=hstp_trans_main.prx start=0x00209ee4 end=0x00209f3c symbol=FUN_00209ee4 */
/* Clone of src/eboot/FUN_001fb7cc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Vec_00209ee4 {
    void *data;
    int size;
    void shrink(const int &n) { size -= n; }
    void clear() { int n = size; shrink(n); }
};
struct S_00209ee4 {
    char pad0[0x28];
    Vec_00209ee4 list;
    char pad30[0x3c - 0x30];
    int a[20];
    int b[20];
    int c;
    int d;
};
extern "C" void FUN_00209ee4(S_00209ee4 *s)
{
    int i;
    s->c = 0;
    s->d = 0;
    for (i = 0; i < 20; i++) {
        s->a[i] = 0;
        s->b[i] = 0;
    }
    s->list.clear();
}
