#include "cstring.h"

size_t Strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

int Strcmp(const char* first, const char* second) {
    while (*first == *second && *first != '\0' && *second != '\0') {
        ++first;
        ++second;
    }
    return *first - *second;
}

int Strncmp(const char* first, const char* second, size_t count) {
    while (*first != '\0' && *second != '\0' && *first == *second && count > 0) {
        ++first;
        ++second;
        --count;
    }
    if (count == 0) {
        return 0;
    } else {
        return *first - *second;
    }
}

char* Strcpy(char* dest, const char* src) {
    char* copy = dest;
    size_t length_src = Strlen(src) + 1;
    for (size_t i = 0; i < length_src; ++i) {
        *(dest + i) = *(src + i);
    }
    return copy;
}

char* Strncpy(char* dest, const char* src, size_t count) {
    char* copy = dest;
    while (*src != '\0' && count > 0) {
        *dest = *src;
        ++dest;
        ++src;
        --count;
    }
    while (count > 0) {
        *dest = '\0';
        --count;
    }
    return copy;
}

char* Strcat(char* dest, const char* src) {
    char* contain = dest;
    while (*dest != '\0') {
        ++dest;
    }
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
    return contain;
}

char* Strncat(char* dest, const char* src, size_t count) {
    char* contain = dest;
    while (*dest != '\0') {
        ++dest;
    }
    while (*src != '\0' && count > 0) {
        *dest = *src;
        ++dest;
        ++src;
        --count;
    }
    *dest = '\0';
    return contain;
}

const char* Strchr(const char* str, char symbol) {
    size_t length_str = Strlen(str) + 1;
    for (size_t i = 0; i < length_str; ++i) {
        if (*(str + i) == symbol) {
            return (str + i);
        }
    }
    return nullptr;
}
const char* Strrchr(const char* str, char symbol) {
    const char* result = nullptr;
    size_t length_str = Strlen(str) + 1;
    for (size_t i = 0; i < length_str; ++i) {
        if (*(str + i) == symbol) {
            result = str + i;
        }
    }
    return result;
}
size_t Strspn(const char* dest, const char* src) {
    size_t count = 0;
    size_t length_dest = Strlen(dest);
    for (size_t i = 0; i < length_dest; ++i) {
        if (Strchr(src, *(dest + i)) == nullptr) {
            return count;
        } else {
            ++count;
        }
    }
    return count;
}
size_t Strcspn(const char* dest, const char* src) {
    size_t count = 0;
    size_t length_dest = Strlen(dest);
    for (size_t i = 0; i < length_dest; ++i) {
        if (Strchr(src, *(dest + i)) == nullptr) {
            ++count;
        } else {
            return count;
        }
    }
    return count;
}
const char* Strpbrk(const char* dest, const char* breakset) {
    const char* result = nullptr;
    while (*dest != '\0' && *breakset != '\0') {
        if (*dest == *breakset) {
            result = dest;
            break;
        }
        ++dest;
        ++breakset;
    }
    return result;
}
const char* Strstr(const char* str, const char* pattern) {
    if (*pattern == '\0') {
        return str;
    }
    while (*str != '\0') {
        if (*str == *pattern) {
            const char* str_copy = str;
            const char* pattern_copy = pattern;
            while (*str_copy != '\0' && *pattern_copy != '\0' && *str_copy == *pattern_copy) {
                ++str_copy;
                ++pattern_copy;
            }
            if (*pattern_copy == '\0') {
                return str;
            }
        }
        ++str;
    }
    return nullptr;
}