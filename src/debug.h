/*
KVMGFX Client - A KVM Client for VGA Passthrough
Copyright (C) 2017-2019 Geoffrey McRae <geoff@hostfission.com>
https://looking-glass.hostfission.com

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C"
{
#endif

#define BOOL2STR(flag) (flag) ? "true" : "false"

#if defined(_WIN32) && !defined(__GNUC__)
#define DIRECTORY_SEPARATOR '\\'
#else
#define DIRECTORY_SEPARATOR '/'
#endif

#define STRIPPATH(s)                                                \
    (sizeof(s) > 2 && (s)[sizeof(s) - 3] == DIRECTORY_SEPARATOR     \
         ? (s) + sizeof(s) - 2                                      \
     : sizeof(s) > 3 && (s)[sizeof(s) - 4] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 3                                      \
     : sizeof(s) > 4 && (s)[sizeof(s) - 5] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 4                                      \
     : sizeof(s) > 5 && (s)[sizeof(s) - 6] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 5                                      \
     : sizeof(s) > 6 && (s)[sizeof(s) - 7] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 6                                      \
     : sizeof(s) > 7 && (s)[sizeof(s) - 8] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 7                                      \
     : sizeof(s) > 8 && (s)[sizeof(s) - 9] == DIRECTORY_SEPARATOR   \
         ? (s) + sizeof(s) - 8                                      \
     : sizeof(s) > 9 && (s)[sizeof(s) - 10] == DIRECTORY_SEPARATOR  \
         ? (s) + sizeof(s) - 9                                      \
     : sizeof(s) > 10 && (s)[sizeof(s) - 11] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 10                                     \
     : sizeof(s) > 11 && (s)[sizeof(s) - 12] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 11                                     \
     : sizeof(s) > 12 && (s)[sizeof(s) - 13] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 12                                     \
     : sizeof(s) > 13 && (s)[sizeof(s) - 14] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 13                                     \
     : sizeof(s) > 14 && (s)[sizeof(s) - 15] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 14                                     \
     : sizeof(s) > 15 && (s)[sizeof(s) - 16] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 15                                     \
     : sizeof(s) > 16 && (s)[sizeof(s) - 17] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 16                                     \
     : sizeof(s) > 17 && (s)[sizeof(s) - 18] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 17                                     \
     : sizeof(s) > 18 && (s)[sizeof(s) - 19] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 18                                     \
     : sizeof(s) > 19 && (s)[sizeof(s) - 20] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 19                                     \
     : sizeof(s) > 20 && (s)[sizeof(s) - 21] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 20                                     \
     : sizeof(s) > 21 && (s)[sizeof(s) - 22] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 21                                     \
     : sizeof(s) > 22 && (s)[sizeof(s) - 23] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 22                                     \
     : sizeof(s) > 23 && (s)[sizeof(s) - 24] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 23                                     \
     : sizeof(s) > 24 && (s)[sizeof(s) - 25] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 24                                     \
     : sizeof(s) > 25 && (s)[sizeof(s) - 26] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 25                                     \
     : sizeof(s) > 26 && (s)[sizeof(s) - 27] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 26                                     \
     : sizeof(s) > 27 && (s)[sizeof(s) - 28] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 27                                     \
     : sizeof(s) > 28 && (s)[sizeof(s) - 29] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 28                                     \
     : sizeof(s) > 29 && (s)[sizeof(s) - 30] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 29                                     \
     : sizeof(s) > 30 && (s)[sizeof(s) - 31] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 30                                     \
     : sizeof(s) > 31 && (s)[sizeof(s) - 32] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 31                                     \
     : sizeof(s) > 32 && (s)[sizeof(s) - 33] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 32                                     \
     : sizeof(s) > 33 && (s)[sizeof(s) - 34] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 33                                     \
     : sizeof(s) > 34 && (s)[sizeof(s) - 35] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 34                                     \
     : sizeof(s) > 35 && (s)[sizeof(s) - 36] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 35                                     \
     : sizeof(s) > 36 && (s)[sizeof(s) - 37] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 36                                     \
     : sizeof(s) > 37 && (s)[sizeof(s) - 38] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 37                                     \
     : sizeof(s) > 38 && (s)[sizeof(s) - 39] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 38                                     \
     : sizeof(s) > 39 && (s)[sizeof(s) - 40] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 39                                     \
     : sizeof(s) > 40 && (s)[sizeof(s) - 41] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 40                                     \
     : sizeof(s) > 41 && (s)[sizeof(s) - 42] == DIRECTORY_SEPARATOR \
         ? (s) + sizeof(s) - 41                                     \
         : (s))

#define DEBUG_PRINT(type, fmt, ...)                                                \
    do                                                                             \
    {                                                                              \
        fprintf(stdout, type "%20s:%-4u | %-15s | " fmt "\n", STRIPPATH(__FILE__), \
                __LINE__, __FUNCTION__, ##__VA_ARGS__);                            \
        fflush(stdout);                                                            \
    } while (0)

#define DEBUG_PRINT2(type, fmt, ...)                                               \
    do                                                                             \
    {                                                                              \
        fprintf(stdout, type "%25s:%-4u | %-25s | " fmt "\n", STRIPPATH(__FILE__), \
                __LINE__, __FUNCTION__, ##__VA_ARGS__);                            \
        fflush(stdout);                                                            \
    } while (0)

#define DEBUG_BREAK() DEBUG_PRINT("[B]", "================================================================================");
#define DEBUG_INFO(fmt, ...) DEBUG_PRINT("[I]", fmt, ##__VA_ARGS__)
#define DEBUG_WARN(fmt, ...) DEBUG_PRINT("[W]", fmt, ##__VA_ARGS__)
#define DEBUG_ERROR(fmt, ...) DEBUG_PRINT("[E]", fmt, ##__VA_ARGS__)
#define DEBUG_FIXME(fmt, ...) DEBUG_PRINT("[F]", fmt, ##__VA_ARGS__)

#define DEBUG_FRAME(fmt, ...) DEBUG_PRINT2("[F]", fmt, ##__VA_ARGS__)

//#if defined(DEBUG_SPICE) | defined(DEBUG_IVSHMEM)
#define DEBUG_PROTO(fmt, src, ...) DEBUG_PRINT("[P]", fmt, src, ##__VA_ARGS__)
    //#else
    //#define DEBUG_PROTO(fmt, ...) do{} while (0)
    //#endif

#define DEBUG_BYTES(buffer, nblen, fmt, ...)                          \
    do                                                                \
    {                                                                 \
        char tmp[1024];                                               \
        char *cur = tmp;                                              \
        const char *end = tmp + 1024;                                 \
        cur += snprintf(cur, end - cur, "%s|", tmp);                  \
        for (int z = 0; z < nblen; z++)                               \
        {                                                             \
            cur += snprintf(cur, end - cur, "0x%02X ", buffer[z]);    \
        }                                                             \
        DEBUG_ERROR(fmt " Bytes(%d): %s", ##__VA_ARGS__, nblen, tmp); \
    } while (0)

#define DEBUG_MOUSESHAPE(buffer, nblen, fmt, ...)                     \
    do                                                                \
    {                                                                 \
        char tmp[2048];                                               \
        char *cur = tmp;                                              \
        const char *end = tmp + 2048;                                 \
        cur += snprintf(cur, end - cur, "%s|", tmp);                  \
        for (int z = 0; z < nblen; z += 4)                            \
        {                                                             \
            cur += snprintf(cur, end - cur, "0x%02X ", buffer[z]);    \
        }                                                             \
        DEBUG_ERROR(fmt " Bytes(%d): %s", ##__VA_ARGS__, nblen, tmp); \
    } while (0)

#define DEBUG_U8_BITS(bytes, fmt, ...)                                 \
    do                                                                 \
    {                                                                  \
        char tmp[1024];                                                \
        char *cur = tmp;                                               \
        const char *end = tmp + 1024;                                  \
        cur += snprintf(cur, end - cur, "%s|", tmp);                   \
        int bits;                                                      \
        for (int b = 0; b < 8; b++)                                    \
        {                                                              \
            bits = (bytes >> b) & 0x01;                                \
            cur += snprintf(cur, end - cur, " %d", bits);              \
        }                                                              \
        DEBUG_ERROR(fmt " U8(0x%02x): %s", ##__VA_ARGS__, bytes, tmp); \
    } while (0)

#define DEBUG_MONO_MOUSE_BITMAP(bitmap, nb_bytes, fmt, ...)   \
    do                                                        \
    {                                                         \
        char tmp[1024];                                       \
        char *cur = tmp;                                      \
        const char *end = tmp + 1024;                         \
        cur += snprintf(cur, end - cur, "|");                 \
        for (int bytes = 0; bytes < nb_bytes; bytes++)        \
        {                                                     \
            int abyte = bitmap[bytes];                        \
            for (int b = 7; b >= 0; b--)                      \
            {                                                 \
                int bits = (abyte >> b) & 0x01;               \
                cur += snprintf(cur, end - cur, " %d", bits); \
            }                                                 \
        }                                                     \
        DEBUG_ERROR(fmt " %s", ##__VA_ARGS__, tmp);           \
    } while (0)

    extern void print_trace(void);

#ifdef __cplusplus
}
#endif
#endif /* V4L2_H */