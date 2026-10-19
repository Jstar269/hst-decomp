/* HSTMATCH module=EBOOT.BIN start=0x001bcd70 end=0x001bce90 symbol=FUN_001bcd70 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

template <typename T>
static inline const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

extern unsigned long long DAT_002e9da8;

struct Elem {
    int val0;
    int val4;
    char pad[152];
};

struct Container {
    char pad0[8];
    int count1;
    int count2;
    char pad1[0xc0 - 16];
    Elem items[1];
};

extern "C" int FUN_001bcd70(Container* param_1) {
    unsigned long long sum = (unsigned int)(param_1->count1 + param_1->count2);
    int count = (int)min(sum, DAT_002e9da8);
    Elem* p = param_1->items;
    int total = 0;
    for (int i = 0; i < count; ++i, ++p) {
        total += p->val0;
    }
    return total;
}
