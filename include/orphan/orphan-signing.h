#ifndef __ORPHAN_SIGNING_H__
#define __ORPHAN_SIGNING_H__

#include <cstddef>

//export module orphan:hash;

#include <vector> //import <vector>;
#include <span> //import <span>;

#include <orphan/orphan-crypto.h>

//export
namespace pulse
{
	class SigningFunction : CryptographicFunction
	{
	public:
		SigningFunction(ElipticalCurve);

		SigningFunction(ElipticalCurve, HashAlgorithm);

		virtual CryptographicFunction::return_type 
			operator()(CryptographicFunction::input_type input) const override;

	private:
		const ElipticalCurve curve;
		const HashAlgorithm hash_algo;
		const bool hash_before_signing;
	};

} //namespace pulse




#endif //__ORPHAN_SIGNING_H__