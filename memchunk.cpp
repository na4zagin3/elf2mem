#include <cstddef>
#include <vector>
#include <map>
#include <tuple>
#include "memchunk.h"

namespace memory {
	bool Chunk::isZero() { return zero; }

	std::vector<char> &Chunk::getContaint(){ return mem; }

	Chunk::Chunk(std::vector<char> mem) : mem(mem), zero(0), length(mem.size()) {}

	bool Memory::addChunk(size_t start_addr, Chunk chunk) {
		chunks.insert(std::make_pair(start_addr, chunk));
		return true;
	}

	std::pair<size_t, Chunk> Memory::popChunk(void) {
		auto it = chunks.begin();
		auto v = it->second;
		auto k = it->first;
		chunks.erase(k);
		return std::make_pair(k, v);
	}

	bool Memory::empty(void) { return chunks.empty(); }
}
