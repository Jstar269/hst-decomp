/* HSTMATCH module=EBOOT.BIN start=0x0005c854 end=0x0005c900 symbol=FUN_0005c854 lang=c++ */
typedef unsigned int uint;

struct V4 { float x, y, z, w; };

inline V4 Neg4(const V4 &v)
{
    V4 r;
    r.x = -v.x;
    r.y = -v.y;
    r.z = -v.z;
    r.w = -v.w;
    return r;
}

static inline uint MaxU(uint a, uint b) { return a < b ? b : a; }

extern "C" void FUN_0005c854(uint *p, uint idx, const float *a, const float *b)
{
    uint n = idx + 1;

    p[4] = MaxU(n, p[4]);
    *(V4 *)((char *)p + idx * 32 + 0x90) = Neg4(*(const V4 *)a);
    p[4] = MaxU(n, p[4]);
    *(V4 *)((char *)p + idx * 32 + 0xA0) = *(const V4 *)b;
}

// PARKED (dsn2). State: 34/43 words differ. What is right and proven:
//  (a) update #1 is `p[4] = MaxU(n, p[4]);` with an inline `uint MaxU(uint a,uint b){return a<b?b:a;}`
//      -- reproduces retail's lw/sltu/beqzl/move/sw word-for-word (verified in isolation too).
//  (b) the pos-block neg chain (lwc1 12(a2)/8(a2)/4(a2), neg f3/f2/f1, lwc1 0(a2), neg f0) comes from
//      a 4-float struct copy of a negated vector: `*(V4 *)(base + 0x90) = Neg4(*(const V4 *)a);` with an
//      inline Neg4 -- matches retail's register chain in isolation (scratch10); in context the two
//      later loads swap to y,z,w.
// Open: retail has a 16-byte frame with four dead `swc1` of the NEGATED values to 0..12(sp) and no
// reloads (reads forwarded). Not produced by: float tmp[4] (+chained assignment), if/else Reserve inline,
// by-ref/by-value inline setters, ctor-temp by-ref/by-value args, const V4& binding, pointer-reading
// inline copyOut, out-param inline (all fully promoted -- zero stores). Named V4 locals from inline
// return values give TWO 16-byte objects + reloads (32-byte frame). Also open: retail's update #2 is
// the split `beqz at,L; b E; sw v1; L: move v1,t0; sw v1` (both arms store) not the select form; and
// retail keeps dst in v1 (`addu v1,a1,a0`, a1 = idx<<5 in place) -- ours puts dst in a1.
// near miss from lane dsn2 (unreviewed)
