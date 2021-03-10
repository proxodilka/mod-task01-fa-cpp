#include "fun.h"

#include <cctype>
#include <vector>

std::vector<std::pair<const char *, const char *>> split(const char *str,
                                                         char sep = ' ') {
  bool on_word = false;
  const char *c_start = nullptr;
  const char *c_end = nullptr;

  std::vector<std::pair<const char *, const char *>> result;
  int i = 0;
  for (; str[i] != '\0'; i++) {
    if (str[i] != sep && !on_word) {
      on_word = true;
      c_start = str + i;
    } else if (str[i] == sep && on_word) {
      on_word = false;
      c_end = str + i;
      result.emplace_back(c_start, str + i);
      c_start = c_end = nullptr;
    } else {
      continue;
    }
  }

  if (c_start != nullptr && c_end == nullptr) {
    result.emplace_back(c_start, str + i);
  }
  return result;
}

unsigned int faStr1(const char *str) {
  auto words = split(str);
  int result = 0;
  auto process_word = [&result](const char *begin, const char *end) {
    for (; begin != end; begin++) {
      if (std::isdigit(*begin)) {
        return;
      }
    }
    result++;
  };
  for (auto word : words) {
    process_word(word.first, word.second);
  }
  return result;
}

unsigned int faStr2(const char *str) {
  auto words = split(str);
  int result = 0;
  auto process_word = [&result](const char *begin, const char *end) {
    if (!std::isupper(*(begin++))) {
      return;
    }
    for (; begin != end; begin++) {
      if (!std::islower(*begin)) {
        return;
      }
    }
    result++;
  };
  for (auto word : words) {
    process_word(word.first, word.second);
  }
  return result;
}

unsigned int faStr3(const char *str) {
  auto words = split(str);
  int result = 0;
  auto process_word = [&result](const char *begin, const char *end) {
    result += end - begin;
  };
  for (auto word : words) {
    process_word(word.first, word.second);
  }
  return words.size() ? (result / (float)words.size() + 0.5) : 0;
}
