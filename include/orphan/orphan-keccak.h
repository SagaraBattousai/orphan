#ifndef __ORPHAN_KECCAK_H__
#define __ORPHAN_KECCAK_H__

#include <orphan/_orphanconfig.h>

#ifdef __cplusplus
#include <cstdint>

#include <orphan/orphan-hash.h>

namespace orphan
{
	ORPHAN_EXPORT_SYMBOL hash_output Keccak224(hash_input);

	ORPHAN_EXPORT_SYMBOL hash_output Keccak256(hash_input);

	ORPHAN_EXPORT_SYMBOL hash_output Keccak384(hash_input);

	ORPHAN_EXPORT_SYMBOL hash_output Keccak512(hash_input);
}
extern "C" {
#else
#include <stdint.h>
#endif

ORPHAN_EXPORT_SYMBOL void keccak224(const uint8_t *input, int byteCount, uint8_t *output);
	
ORPHAN_EXPORT_SYMBOL void keccak256(const uint8_t *input, int byteCount, uint8_t *output);
	
ORPHAN_EXPORT_SYMBOL void keccak384(const uint8_t *input, int byteCount, uint8_t *output);

ORPHAN_EXPORT_SYMBOL void keccak512(const uint8_t *input, int byteCount, uint8_t *output);

#ifdef __cplusplus
}
#endif


#endif // !__ORPHAN_KECCAK_H__
