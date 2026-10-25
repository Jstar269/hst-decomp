/* HSTMATCH module=EBOOT.BIN start=0x0025a0e8 end=0x0025a2c0 symbol=FUN_0025a0e8 lang=c++ */
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
MapIt FUN_0025a410(Deque *d);
MapIt FUN_0025a3b0(Deque *d);
MapIt FUN_0025a2ec(const MapIt *m, unsigned n);
int FUN_0025a360(Deque *d);
Iter FUN_0025a378(const MapIt *m, int *cur, int *last);
void FUN_0025a678(Deque *d, const Iter &first, const Iter &last);
void *FUN_0025a3a8(Deque *d);
void FUN_0025a370(void *a, int *blk, int n);
void FUN_0025a2c0(MapIt *m);
void FUN_0025a454(Deque *d, int flag);
void FUN_00000a00(void *p);
}

inline MapIt MapIt::Plus(unsigned n) const { return FUN_0025a2ec(this, n); }

struct Deque {
    int pad[4];
    unsigned start;
    unsigned size;
    MapIt MapBegin() { return FUN_0025a410(this); }
    Iter begin() { return IterAt(0); }
    Iter end() { return IterAt(size); }
    void FreeBlocks()
    {
        if (!FUN_0025a360(this)) {
            void *a = FUN_0025a3a8(this);
            MapIt e = FUN_0025a3b0(this);
            for (MapIt i = FUN_0025a410(this); i.p != e.p; FUN_0025a2c0(&i)) {
                if (*i.p != 0)
                    FUN_0025a370(a, *i.p, 0x80);
            }
        }
    }
    Iter IterAt(unsigned pos)
    {
        pos += start;
        MapIt m = MapBegin().Plus(pos / 128);
        int *blk = FUN_0025a360(this) ? 0 : *m.p;
        return FUN_0025a378(&m, blk + pos % 128, blk + 128);
    }
};

extern "C" Deque *FUN_0025a0e8(Deque *d, short flag)
{
    if (d != 0) {
        FUN_0025a678(d, d->begin(), d->end());
        if (d != 0) {
            d->FreeBlocks();
            if (d != 0 && d != 0 && d != 0 && d != 0)
                FUN_0025a454(d, 0);
        }
        if (flag > 0)
            FUN_00000a00(d);
    }
    return d;
}
