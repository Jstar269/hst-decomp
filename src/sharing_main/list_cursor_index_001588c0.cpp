/* HSTMATCH module=hstp_trans_main.prx start=0x001588c0 end=0x00158920 symbol=FUN_001588c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Index of the cursor (+0x14) in the node list behind the pointer at +4 (same object as cursor_value_00158838 and
   list_seek_00158920), 0 when the cursor is at the end: an MSL-style std::distance over a one-pointer list iterator.
   The by-value iterator copies (lwc1/swc1 through stack slots) and the 32-byte frame come from distance() passing its
   by-value iterators and an empty iterator-category tag on to __distance(). Names provisional. */
struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};

struct Node {
  Node *prev;
  Node *next;
};

struct Iter {
  typedef bidirectional_iterator_tag iterator_category;
  Node *node;
  Iter(Node *n) : node(n) {}
  Iter &operator++() { node = node->next; return *this; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.node == b.node; }
inline bool operator!=(const Iter &a, const Iter &b) { return a.node != b.node; }

struct List {
  int pad0;
  Node sentinel;
  Iter begin() { return Iter(sentinel.next); }
  Iter end() { return Iter(&sentinel); }
};

struct Obj {
  int pad0;
  List *list;
  int pad1[3];
  Iter cur;
};

template <class It> inline int __distance(It first, It last, input_iterator_tag)
{
  int n = 0;
  for (; first != last; ++first)
    ++n;
  return n;
}

template <class It> inline int distance(It first, It last)
{
  return __distance(first, last, typename It::iterator_category());
}

extern "C" int FUN_001588c0(Obj *self)
{
  if (self->cur == self->list->end())
    return 0;
  return distance(self->list->begin(), self->cur);
}
