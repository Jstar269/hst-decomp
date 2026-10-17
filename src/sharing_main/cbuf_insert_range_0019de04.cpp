/* HSTMATCH module=hstp_trans_main.prx start=0x0019de04 end=0x0019de8c symbol=FUN_0019de04 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0019de04 {};
struct Tag_0019de04 : InTag_0019de04 {};
typedef void *Block_0019de04;
struct It_0019de04 {
    Block_0019de04 *p_;
    Block_0019de04 *first_;
    Block_0019de04 *beg_;
    Block_0019de04 *last_;
    It_0019de04(const It_0019de04 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0019de04;
extern "C" void FUN_0019e104(Buf_0019de04 *self, It_0019de04 pos, It_0019de04 first, It_0019de04 last, Tag_0019de04);
extern "C" void FUN_0019de04(Buf_0019de04 *self, It_0019de04 pos, It_0019de04 first, It_0019de04 last)
{
    FUN_0019e104(self, pos, first, last, Tag_0019de04());
}
