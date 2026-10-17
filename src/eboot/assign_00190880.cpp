/* HSTMATCH module=EBOOT.BIN start=0x00190880 end=0x001908f8 symbol=__as__10S_00190880FRC10S_00190880 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Long_00190880 { unsigned int cap; unsigned int size; char *data; };
struct Short_00190880 { unsigned char is_long : 1; unsigned char size : 7; char buf[11]; };
union Rep_00190880 { Long_00190880 l; Short_00190880 s; };
class S_00190880 {
public:
    Rep_00190880 r;
    bool is_long() const { return r.l.cap & 1; }
    unsigned int size() const { return is_long() ? r.l.size : r.s.size; }
    S_00190880 &replace(unsigned int pos, unsigned int n, const S_00190880 &o);
    S_00190880 &operator=(const S_00190880 &o);
};
S_00190880 &S_00190880::operator=(const S_00190880 &o)
{
    bool l = is_long();
    if (!l && !o.is_long()) {
        r = o.r;
        return *this;
    }
    return replace(0, l ? r.l.size : r.s.size, o);
}
