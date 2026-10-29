/* HSTMATCH module=EBOOT.BIN start=0x0025a0e8 end=0x0025a2c0 symbol=FUN_0025a0e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/block_deque.h"

struct Deque;
#define BLOCK_ELEMS 128   /* elements per block */

/* Cursor over the block map; same four words as the head of a deque position. */
struct MapIt {
    int **cur;
    int **begin;
    int **head;
    int **end;
    MapIt() {}
    MapIt Plus(unsigned count) const;
};
/* Deque position: map cursor, current element and block end. */
struct Iter {
    int x[6];
    Iter() {}
};
extern "C" {
MapIt FUN_0025a410(Deque *d);
MapIt FUN_0025a3b0(Deque *d);
MapIt FUN_0025a2ec(const MapIt *m, unsigned count);
int FUN_0025a360(Deque *d);
Iter FUN_0025a378(const MapIt *m, int *elem, int *block_end);
void FUN_0025a678(Deque *d, const Iter &first, const Iter &last);
void *FUN_0025a3a8(Deque *d);
void FUN_0025a370(void *alloc, int *block, int n);
void FUN_0025a2c0(MapIt *m);
void FUN_0025a454(Deque *d, int flags);
void FUN_00000a00(void *p);
}

inline MapIt MapIt::Plus(unsigned count) const { return FUN_0025a2ec(this, count); }

struct Deque {
    BlockMap map;
    unsigned first;   /* index of the first element inside the block run */
    unsigned length;  /* elements stored */
    MapIt MapBegin() { return FUN_0025a410(this); }
    Iter begin() { return IterAt(0); }
    Iter end() { return IterAt(length); }
    void FreeBlocks()
    {
        if (!FUN_0025a360(this)) {
            void *alloc = FUN_0025a3a8(this);
            MapIt map_end = FUN_0025a3b0(this);
            for (MapIt it = FUN_0025a410(this); it.cur != map_end.cur; FUN_0025a2c0(&it)) {
                if (*it.cur != 0)
                    FUN_0025a370(alloc, *it.cur, BLOCK_ELEMS);
            }
        }
    }
    Iter IterAt(unsigned pos)
    {
        pos += first;
        MapIt m = MapBegin().Plus(pos / BLOCK_ELEMS);
        int *block = FUN_0025a360(this) ? 0 : *m.cur;
        return FUN_0025a378(&m, block + pos % BLOCK_ELEMS, block + BLOCK_ELEMS);
    }
};

/* Deleting destructor of a block deque: destroy the elements, free the blocks and the map, free self when flags > 0. */
extern "C" Deque *FUN_0025a0e8(Deque *d, short flags)
{
    if (d != 0) {
        FUN_0025a678(d, d->begin(), d->end());
        if (d != 0) {
            d->FreeBlocks();
            if (d != 0 && d != 0 && d != 0 && d != 0)
                FUN_0025a454(d, 0);
        }
        if (flags > 0)
            FUN_00000a00(d);
    }
    return d;
}
