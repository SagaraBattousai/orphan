
#include <iostream>
#include <vector>
#include <cstddef>

#include <orphan/orphan-keccak.h>

int main()
{
	const char *s = "Hello World";

	const std::byte *bytes = reinterpret_cast<const std::byte*>(s);

	std::vector<std::byte> byte_vector{ bytes, bytes + 11 };

	std::vector<std::byte> hash = orphan::Keccak256(byte_vector);

	for (auto h : hash)
	{
		std::cout << std::hex << (int)h;
	}

	std::cout << std::endl;

	return 0;
}