/* HSTMATCH module=EBOOT.BIN start=0x00190f00 end=0x00190f50 symbol=replace__10S_00190880FUiUiRC10S_00190880 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct SLong { unsigned int cap; unsigned int size; unsigned short *data; };
struct SShort { unsigned char is_long : 1; unsigned char size : 7; unsigned short buf[7]; };
union SRep { SLong l; SShort s; };
class S_00190880 {
public:
    SRep r;
    bool is_long() const { return r.l.cap & 1; }
    S_00190880 &replace(unsigned int pos, unsigned int n, const S_00190880 &o);
    S_00190880 &operator=(const S_00190880 &o);
};
extern "C" S_00190880 *FUN_00045af4(S_00190880 *, unsigned int, unsigned int,
                                   const unsigned short *, const unsigned short *, fwd_tag);
S_00190880 &S_00190880::replace(unsigned int pos, unsigned int n, const S_00190880 &o)
{
    const unsigned short *p;
    unsigned int size;
    if (!o.is_long()) {
        p = o.r.s.buf;
        size = o.r.s.size;
    } else {
        p = o.r.l.data;
        size = o.r.l.size;
    }
    return *(S_00190880 *)FUN_00045af4(this, pos, n, p, p + size, fwd_tag());

}
