/* HSTMATCH module=hstp_trans_main.prx start=0x000b7868 end=0x000b7a00 symbol=FUN_000b7868 lang=c++ */
/* Clone of src/eboot/insertion_sort_records_000b4578.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Insertion sort of 80-byte records (16 floats + tag, aligned 16) by the float at +0x38, std-style guarded linear insert, same iterator/functor shape as insertion_sort_by_key_001076c8.cpp. Matching idioms: Record has the user copy constructor of swap_records_000b41b8.cpp (unrolled copy for val); the comparator takes the second element BY VALUE as the POD view Item (retail copies it with the 10-pair 80-byte block loop on the stack), reached by (Item *)&*--k; the trailing empty functor parameter gives the 16 extra bytes of frame. */
struct Item {
    float f[16];
    int tag;
} __attribute__((aligned(16)));

struct Record {
    float f[16];
    int tag;
    Record() {}
    Record(const Record &o)
    {
        f[0] = o.f[0];
        f[1] = o.f[1];
        f[2] = o.f[2];
        f[3] = o.f[3];
        f[4] = o.f[4];
        f[5] = o.f[5];
        f[6] = o.f[6];
        f[7] = o.f[7];
        f[8] = o.f[8];
        f[9] = o.f[9];
        f[10] = o.f[10];
        f[11] = o.f[11];
        f[12] = o.f[12];
        f[13] = o.f[13];
        f[14] = o.f[14];
        f[15] = o.f[15];
        tag = o.tag;
    }
} __attribute__((aligned(16)));

struct It {
    Record *p;
    It() {}
    It(Record *q) : p(q) {}
    Record &operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
    It &operator--() { --p; return *this; }
    It operator+(int n) const { return It(p + n); }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }
inline bool operator<(const It &a, const It &b) { return a.p < b.p; }

struct Less {
    bool operator()(const Record &a, Item b) const { return a.f[14] < b.f[14]; }
};

extern "C" void FUN_000b7868(It first, It last, Less comp)
{
    if (first != last) {
        for (It i = first + 1; i < last; ++i) {
            Record val = *i;
            It k = i;
            It j = i;
            for (; first < j && comp(val, *(Item *)&*--k); --j)
                *j = *k;
            *j = val;
        }
    }
}
