/* HSTMATCH module=EBOOT.BIN start=0x00108ca8 end=0x00108dc0 symbol=FUN_00108ca8 lang=c++ */
struct Item { char pad[0x20]; float key; };
struct It { Item **p; int x; };
struct Out { Item **p; Out() {} Out(Item **q) : p(q) {} };
struct Greater { bool operator()(const Item *a, const Item *b) const { return a->key > b->key; } };

static inline Item **Copy(It first, It last, Item **result)
{
  for (; first.p != last.p; ++first.p) {
    *result = *first.p;
    ++result;
  }
  return result;
}

extern "C" Out FUN_00108ca8(It first1, It last1, It first2, It last2, Item **result, Greater comp)
{
  for (; first1.p != last1.p && first2.p != last2.p; ++result) {
    if (comp(*first2.p, *first1.p)) {
      *result = *first2.p;
      ++first2.p;
    } else {
      *result = *first1.p;
      ++first1.p;
    }
  }
  return Out(Copy(first2, last2, Copy(first1, last1, result)));
}
// NOT MATCHED (47 of 70 words differ; frame, iterator copies, comparator, tail loops and delay-slot layout are right).
// Retail = std::merge over two 8-byte iterators {Item **p, int} passed by value (copied to sp+16..44, so the extra empty
// comparator parameter `Greater comp` is needed to get the 48-byte frame), descending order on the float key at +0x20.
// What differs: in the main loop retail re-reads first1.p / first2.p from the stack at the start of each arm (lw a1,40(sp) in the
// bc1tl slot, lw a1,24(sp) in the other arm) and increments from that reload, never from the pointer loaded at the top of the
// body; ours CSEs the pointer (addiu a1,a3,4). The tail loops walk a register (lw a3,24(sp) once). Tried: while/for loops,
// member operator*/++ vs direct fields (every mix), casts to an identical struct for one of the two forms, inline Copy() helpers
// with by-value iterators, result as void**/volatile. None changed the CSE.
// near miss from lane sn4 (unreviewed)
