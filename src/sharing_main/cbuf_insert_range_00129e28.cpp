/* HSTMATCH module=hstp_trans_main.prx start=0x00129e28 end=0x00129eb0 symbol=FUN_00129e28 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_00129e28 {};
struct Tag_00129e28 : InTag_00129e28 {};
typedef void *Block_00129e28;
struct It_00129e28 {
    Block_00129e28 *p_;
    Block_00129e28 *first_;
    Block_00129e28 *beg_;
    Block_00129e28 *last_;
    It_00129e28(const It_00129e28 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_00129e28;
extern "C" void FUN_0012a7b4(Buf_00129e28 *self, It_00129e28 pos, It_00129e28 first, It_00129e28 last, Tag_00129e28);
extern "C" void FUN_00129e28(Buf_00129e28 *self, It_00129e28 pos, It_00129e28 first, It_00129e28 last)
{
    FUN_0012a7b4(self, pos, first, last, Tag_00129e28());
}
