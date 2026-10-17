/* HSTMATCH module=EBOOT.BIN start=0x0011f2ac end=0x0011f334 symbol=FUN_0011f2ac lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0011f2ac {};
struct Tag_0011f2ac : InTag_0011f2ac {};
typedef void *Block_0011f2ac;
struct It_0011f2ac {
    Block_0011f2ac *p_;
    Block_0011f2ac *first_;
    Block_0011f2ac *beg_;
    Block_0011f2ac *last_;
    It_0011f2ac(const It_0011f2ac &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0011f2ac;
extern "C" void FUN_00120154(Buf_0011f2ac *self, It_0011f2ac pos, It_0011f2ac first, It_0011f2ac last, Tag_0011f2ac);
extern "C" void FUN_0011f2ac(Buf_0011f2ac *self, It_0011f2ac pos, It_0011f2ac first, It_0011f2ac last)
{
    FUN_00120154(self, pos, first, last, Tag_0011f2ac());
}
