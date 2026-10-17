/* HSTMATCH module=EBOOT.BIN start=0x001fb7cc end=0x001fb824 symbol=FUN_001fb7cc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Vec_001fb7cc {
    void *data;
    int size;
    void shrink(const int &n) { size -= n; }
    void clear() { int n = size; shrink(n); }
};
struct S_001fb7cc {
    char pad0[0x28];
    Vec_001fb7cc list;
    char pad30[0x3c - 0x30];
    int a[20];
    int b[20];
    int c;
    int d;
};
extern "C" void FUN_001fb7cc(S_001fb7cc *s)
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
