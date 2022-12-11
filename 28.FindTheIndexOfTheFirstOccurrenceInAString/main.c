#include "stdio.h"
#include "string.h"

int strStr(char* haystack, char* needle) {
  const int needleLen = strlen(needle), haystackLen = strlen(haystack),
            accisLen = 256;
  int shiftTable[accisLen];

  for (int i = 0; i < accisLen; i++) {
    shiftTable[i] = needleLen;
  }

  for (int i = needleLen - 2, shift = 1; i >= 0; i--) {
    if (shiftTable[(int) needle[i]] == needleLen) {
      shiftTable[(int) needle[i]] = shift++;
    }
  }

  for (int tailIndex = needleLen - 1; tailIndex <= haystackLen;) {
    int backIndex = 0;
    for (; (backIndex <= needleLen - 1)
         && (haystack[tailIndex - backIndex] == needle[needleLen - 1 - backIndex]);
         backIndex++) {
    }
    if (backIndex == needleLen) {
      return tailIndex - needleLen + 1;
    }
    else {
      tailIndex += shiftTable[(int) haystack[tailIndex]];
    }
  }
  return -1;
}