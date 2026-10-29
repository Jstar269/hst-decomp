/* HSTMATCH module=EBOOT.BIN start=0x001cb204 end=0x001cb334 symbol=FUN_001cb204 lang=c++ */
struct Vec4_001cb204 { float x, y, z, w; } __attribute__((aligned(16)));
struct Tag_001cb204 {};
struct Empty_001cb204 {};
struct Entry_001cb204 { int id; char pad[44]; Vec4_001cb204 posB; Vec4_001cb204 posA; };
struct Vec_001cb204 { Entry_001cb204 *data; int size; unsigned capacity; Vec_001cb204() : data(0), size(0), capacity(0) {} };
struct Mgr_001cb204 { char pad[0xaf8]; Vec_001cb204 entries; };
extern Mgr_001cb204 *DAT_0033b574;
extern "C" void FUN_001ce440(Vec_001cb204 *, Entry_001cb204 *, Entry_001cb204 *, Tag_001cb204);
extern "C" void FUN_001474d0(Vec_001cb204 *, int);
extern "C" void FUN_00022418(Vec4_001cb204 *, Vec4_001cb204 *, Vec4_001cb204 *);
static inline void Build(Vec_001cb204 *v, Entry_001cb204 *f, Entry_001cb204 *l, Tag_001cb204 t, Tag_001cb204 u0) { FUN_001ce440(v, f, l, t); }
extern "C" int FUN_001cb204(void *unused, int id, Vec4_001cb204 &outPos, Vec4_001cb204 &outSum)
{
    Vec_001cb204 snapshot;
    Tag_001cb204 tag;
    Vec4_001cb204 sum;
    Mgr_001cb204 *m = DAT_0033b574;
    Build(&snapshot, m->entries.data, m->entries.data + m->entries.size, tag, Tag_001cb204());
    for (Entry_001cb204 *p = snapshot.data, *end = snapshot.data + snapshot.size; (p == end) ^ 1; ++p) {
        if (p->id == id) {
            outPos = p->posA;
            FUN_00022418(&sum, &outPos, &p->posB);
            Vec4_001cb204 t = sum;
            outSum = t;
            FUN_001474d0(&snapshot, 0);
            return 1;
        }
    }
    FUN_001474d0(&snapshot, 0);
    return 0;
}
// NEAR (lane sx1): 76/76 words, 1 differs: `lb a3,48(sp)` here, retail `lb a3,44(sp)` (the forwarded tag sits one slot lower; slots 32-51 are
// five never-written 4-byte tag homes in retail, the passed one second from the top). Frame 64, snapshot at 52, sum at 16 all match.
// Levers found: (1) `void *unused` first parameter (an empty by-value struct param put sum at 32 and the 16-byte home below it);
// (2) the +16 frame = inline helper `Build(..., Tag t, Tag u0)` with an unused second by-value tag (more unused tags add nothing);
// (3) loop guard `(p == end) ^ 1` gives xor/sltiu/xori + beqzl/bnezl; (4) `Vec4 t = sum; outSum = t;` batches the four loads like retail.
// Ruled out for the tag slot: declaration permutations of snapshot/tag/sum, two named tags (tag0 passed as the unused param: frame changes),
// Vec ctor taking a Tag, Build with the forwarded tag first/second, Tag() temp as the forwarded arg (gives `andi;seb`, not `lb`).
// improved by lane sx1 (unreviewed): 49 -> 1 differing words
