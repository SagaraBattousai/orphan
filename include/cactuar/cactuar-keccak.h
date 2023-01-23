#ifndef __CACTUAR_KECCAK_H__
#define __CACTUAR_KECCAK_H__

#include <cactuar/_cactuarconfig.h>

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif

CACTUAR_EXPORT_SYMBOL void keccak224(const uint8_t *input, int byteCount, uint8_t *output);
	
CACTUAR_EXPORT_SYMBOL void keccak256(const uint8_t *input, int byteCount, uint8_t *output);
	
CACTUAR_EXPORT_SYMBOL void keccak384(const uint8_t *input, int byteCount, uint8_t *output);

CACTUAR_EXPORT_SYMBOL void keccak512(const uint8_t *input, int byteCount, uint8_t *output);

#ifdef __cplusplus
}
#endif


#endif // !__CACTUAR_KECCAK_H__
