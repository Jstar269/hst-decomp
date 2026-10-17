/* HSTMATCH module=EBOOT.BIN start=0x001b9720 end=0x001b9760 symbol=FUN_001b9720 lang=c99 */
/* Clone of src/sharing_main/filter_short_pairs_001c740c.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 * FUN_001b9720(undefined4 *first, undefined4 *last, undefined4 *out)
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
