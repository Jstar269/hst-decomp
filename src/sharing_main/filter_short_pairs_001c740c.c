/* HSTMATCH module=hstp_trans_main.prx start=0x001c740c end=0x001c744c symbol=FUN_001c740c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: rewrote the inverted short predicate as a guarded do-while; matching idiom: empty less-than arm; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


undefined4 * FUN_001c740c(undefined4 *first, undefined4 *last, undefined4 *out)
{
  if (first != last) {
    do {
      short *item = (short *)*first;
      if (item[0] < item[1]) {
      } else {
        *out++ = (unsigned int)item;
      }
      ++first;
    } while (first != last);
  }
  return out;
}
