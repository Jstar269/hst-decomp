/* HSTMATCH module=EBOOT.BIN start=0x001ce054 end=0x001ce13c symbol=FUN_001ce054 lang=c++ */
/* Clone of src/sharing_main/remove_if_001dc09c.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the inlined find_if is called through a reference to `first`, and its return value is built by the out-of-line iterator copy 0x1d70c0 returned by value); names and types await human review. */
/* std::remove_if over a range of object pointers: `first = find_if(first, last, pred)` inlined (its loop calls
   the iterator operators !=, *, ++ out of line, one inline level below remove_if), then, unless first == last,
   remove_copy_if(++next, last, first, pred) (0x1dd048) with the 80-byte, 16-byte-aligned predicate functor
   (callee copy at the frame bottom, operator() at 0x1dc184). Iterators are one-pointer classes with constructors
   (so the result goes through sret and the copy out of `first` is a lw/sw pair). Names provisional. */
struct Obj;
struct Iter {
    Obj **p;
    Iter() {}
    Iter(Obj **q) : p(q) {}
    Iter &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
struct Pred {
    int state[20];
} __attribute__((aligned(16)));
extern "C" {
Obj *const &FUN_001c8bf8(Iter *it);                                 /* operator* */
Iter *FUN_001c8c00(Iter *it);                                       /* operator++ */
bool FUN_001c8c14(const Iter *a, const Iter *b);                    /* operator!= */
Iter FUN_001c8c2c(const Iter &o);                                   /* copy of an iterator, returned by value */
bool FUN_001ce13c(Pred *pred, Obj *const &x);                       /* pred(x) */
Iter FUN_001ceaf4(Iter first, Iter last, Iter result, Pred pred);   /* remove_copy_if */
}
template <class It, class P> inline It FindIf(It first, It last, P &pred)
{
    while (FUN_001c8c14(&first, &last) && !FUN_001ce13c(&pred, FUN_001c8bf8(&first)))
        FUN_001c8c00(&first);
    return FUN_001c8c2c(first);
}
extern "C" Iter FUN_001ce054(Iter first, Iter last, Pred pred)
{
    Iter &fr = first;
    first = FindIf(fr, last, pred);
    Iter next = first;
    return first == last ? first : FUN_001ceaf4(++next, last, first, pred);
}
