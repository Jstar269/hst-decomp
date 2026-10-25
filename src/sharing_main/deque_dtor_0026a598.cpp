/* HSTMATCH module=hstp_trans_main.prx start=0x0026a598 end=0x0026a770 symbol=FUN_0026a598 lang=c++ */
/* Clone of src/eboot/deque_dtor_0025a0e8.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Deque;
struct MapIt {
    int **p;
    int a, b, c;
    MapIt() {}
    MapIt Plus(unsigned n) const;
};
struct Iter {
    int x[6];
    Iter() {}
};
extern "C" {
MapIt FUN_0026a8c0(Deque *d);
MapIt FUN_0026a860(Deque *d);
MapIt FUN_0026a79c(const MapIt *m, unsigned n);
int FUN_0026a810(Deque *d);
Iter FUN_0026a828(const MapIt *m, int *cur, int *last);
void FUN_0026ab28(Deque *d, const Iter &first, const Iter &last);
void *FUN_0026a858(Deque *d);
void FUN_0026a820(void *a, int *blk, int n);
void FUN_0026a770(MapIt *m);
void FUN_0026a904(Deque *d, int flag);
void FUN_00000a00(void *p);
}

inline MapIt MapIt::Plus(unsigned n) const { return FUN_0026a79c(this, n); }

struct Deque {
    int pad[4];
    unsigned start;
    unsigned size;
    MapIt MapBegin() { return FUN_0026a8c0(this); }
    Iter begin() { return IterAt(0); }
    Iter end() { return IterAt(size); }
    void FreeBlocks()
    {
        if (!FUN_0026a810(this)) {
            void *a = FUN_0026a858(this);
            MapIt e = FUN_0026a860(this);
            for (MapIt i = FUN_0026a8c0(this); i.p != e.p; FUN_0026a770(&i)) {
                if (*i.p != 0)
                    FUN_0026a820(a, *i.p, 0x80);
            }
        }
    }
    Iter IterAt(unsigned pos)
    {
        pos += start;
        MapIt m = MapBegin().Plus(pos / 128);
        int *blk = FUN_0026a810(this) ? 0 : *m.p;
        return FUN_0026a828(&m, blk + pos % 128, blk + 128);
    }
};

extern "C" Deque *FUN_0026a598(Deque *d, short flag)
{
    if (d != 0) {
        FUN_0026ab28(d, d->begin(), d->end());
        if (d != 0) {
            d->FreeBlocks();
            if (d != 0 && d != 0 && d != 0 && d != 0)
                FUN_0026a904(d, 0);
        }
        if (flag > 0)
            FUN_00000a00(d);
    }
    return d;
}
