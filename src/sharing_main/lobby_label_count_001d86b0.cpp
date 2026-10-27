/* HSTMATCH module=hstp_trans_main.prx start=0x001d86b0 end=0x001d8764 symbol=FUN_001d86b0 lang=c++ */
/* Hand-written reconstruction from the disassembly (lobby_script_manager.cpp per the assert strings); matching idiom: `b` declared before `a` for their stack slots and the item id read into a local before the Max() argument; exact match verified; names and types await human review. */
struct Item {
    char pad[0x10];
    unsigned short id;
};

struct Lobby {
    char pad[0xab44];
    int count;
};

extern "C" {
extern char DAT_00391f58[];
extern char DAT_003927ac[];
extern char DAT_00391fac[];
void FUN_001d0468(...);
int FUN_0023c320(void); /* LobbyHelper::GetMatchLabel() per the assert text */
Item *FUN_0019f928(int label);
int FUN_0023a868(unsigned short id);
Lobby *FUN_00239ea4(void);
void FUN_0023a7cc(unsigned short id, int n);
}

#define ASSERT(c, line) if (!(c)) { FUN_001d0468(DAT_00391f58, DAT_003927ac, DAT_00391fac, line); for (;;) {} }

static inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

extern "C" void FUN_001d86b0(void)
{
    ASSERT(FUN_0023c320(), 4794);
    Item *item = FUN_0019f928(FUN_0023c320());
    if (item != 0) {
        int b;
        int a;
        a = FUN_0023a868(item->id);
        b = FUN_00239ea4()->count + 1;
        unsigned short id = item->id;
        FUN_0023a7cc(id, Max(b, a));
    }
}
