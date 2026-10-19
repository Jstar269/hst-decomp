/* HSTMATCH module=EBOOT.BIN start=0x00190cc8 end=0x00190e5c symbol=FUN_00190cc8 lang=c++ */
/* Hand-written reconstruction from the disassembly (sibling of deque_clear_0011c8f0.cpp, deque_clear_0011cca0.cpp, and deque_pop_front_0019095c.cpp); exact match verified; names and types await human review. */
typedef void *Elem;
typedef Elem *Block;

typedef struct MapIt {
    Block *ptr;
    Block *beg;
    Block *first;
    Block *end;
} MapIt;

typedef struct DequeIt {
    MapIt map_it;
    Elem *cur;
    Elem *end;
} DequeIt;

typedef struct Map {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block *data_;
} Map;

struct Deque {
    Map map_;
    unsigned start_;
    unsigned size_;
};

extern "C" {
void *FUN_00000a00(void *);
void FUN_00190e5c(MapIt *out, const MapIt *self, int n);
void FUN_00190ed0(DequeIt *out, const MapIt *map_it, void *cur, void *end);
void FUN_00190fd0(Map *m);
void FUN_00191000(Deque *d, const DequeIt *first, const DequeIt *last);
void FUN_00190cc8(Deque *self);
}

extern "C" void FUN_00190cc8(Deque *self)
{
    DequeIt it2;
    DequeIt it1;
    MapIt adv2;
    MapIt m2;
    MapIt adv1;
    MapIt m1;

    unsigned pos = self->size_;
    pos += self->start_;

    m1.ptr = self->map_.data_ + self->map_.start_;
    m1.first = self->map_.data_ + self->map_.start_;
    m1.beg = self->map_.data_;
    m1.end = self->map_.data_ + self->map_.cap_;

    FUN_00190e5c(&adv1, &m1, pos >> 7);
    Elem *block1;
    if (self->map_.size_ == 0) {
        block1 = 0;
    } else {
        block1 = *adv1.ptr;
    }
    FUN_00190ed0(&it1, &adv1, (char *)block1 + (pos & 0x7f) * 4, (char *)block1 + 512);

    DequeIt *p1 = &it1;

    unsigned pos2 = 0;
    pos2 += self->start_;

    m2.ptr = self->map_.data_ + self->map_.start_;
    m2.first = self->map_.data_ + self->map_.start_;
    m2.beg = self->map_.data_;
    m2.end = self->map_.data_ + self->map_.cap_;

    FUN_00190e5c(&adv2, &m2, pos2 >> 7);
    Elem *block2;
    if (self->map_.size_ == 0) {
        block2 = 0;
    } else {
        block2 = *adv2.ptr;
    }
    FUN_00190ed0(&it2, &adv2, (char *)block2 + (pos2 & 0x7f) * 4, (char *)block2 + 512);

    FUN_00191000(self, &it2, p1);

    self->size_ = 0;
    if (self->map_.size_ > 1) {
        while (self->map_.size_ > 2) {
            FUN_00000a00(self->map_.data_[self->map_.start_]);
            FUN_00190fd0(&self->map_);
        }
        self->start_ = 64;
    } else {
        self->start_ = 0;
    }
}
