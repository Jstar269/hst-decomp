/* HSTMATCH module=hstp_trans_main.prx start=0x0019d090 end=0x0019d108 symbol=__as__10S_0019d090FRC10S_0019d090 */
/* Clone of src/eboot/assign_00190880.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Long_0019d090 { unsigned int cap; unsigned int size; char *data; };
struct Short_0019d090 { unsigned char is_long : 1; unsigned char size : 7; char buf[11]; };
union Rep_0019d090 { Long_0019d090 l; Short_0019d090 s; };
class S_0019d090 {
public:
    Rep_0019d090 r;
    bool is_long() const { return r.l.cap & 1; }
    unsigned int size() const { return is_long() ? r.l.size : r.s.size; }
    S_0019d090 &replace(unsigned int pos, unsigned int n, const S_0019d090 &o);
    S_0019d090 &operator=(const S_0019d090 &o);
};
S_0019d090 &S_0019d090::operator=(const S_0019d090 &o)
{
    bool l = is_long();
    if (!l && !o.is_long()) {
        r = o.r;
        return *this;
    }
    return replace(0, l ? r.l.size : r.s.size, o);
}
