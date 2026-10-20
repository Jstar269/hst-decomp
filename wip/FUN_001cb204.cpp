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
extern "C" int FUN_001cb204(Empty_001cb204 unused, int id, Vec4_001cb204 &outPos, Vec4_001cb204 &outSum)
{
    Vec_001cb204 snapshot;
    Tag_001cb204 tag;
    Vec4_001cb204 sum;
    Mgr_001cb204 *m = DAT_0033b574;
    FUN_001ce440(&snapshot, m->entries.data, m->entries.data + m->entries.size, tag);
    for (Entry_001cb204 *p = snapshot.data, *end = snapshot.data + snapshot.size; p != end; ++p) {
        if (p->id == id) {
            outPos = p->posA;
            FUN_00022418(&sum, &outPos, &p->posB);
            outSum = sum;
            FUN_001474d0(&snapshot, 0);
            return 1;
        }
    }
    FUN_001474d0(&snapshot, 0);
    return 0;
}
// near miss from lane bp1018ar1-0 (unreviewed); 49/76 words, first at +0x38.
// retail: frame=64, snapshot=52-63, tag=44 (lb a3,44(sp)), sum=16-31, never-
//   written 32-51; an empty by-value param reserves its 16-byte home at 16-31
//   and pushes `sum` to >=32, whereas retail puts sum at the bottom (16) and
//   the empty home above it. Frame=64 and snapshot placement already match.
//   Retail materializes the pointer compare (xor/sltiu/xori; beqzl/bnezl);
//   mine emits beql/bnel. `aligned(16)` Vec4, named empty local, derived tag,
//   and inline return-temp variants did NOT move the slots.
// near miss from lane bp1018ar1-0 (unreviewed)
