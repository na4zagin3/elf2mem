#if !defined(MEMCHUNK_H_READ)
#define MEMCHUNK_H_READ
#include<cstddef>
#include<vector>
#include<map>
#include<tuple>

namespace memory {
class Chunk {
	private:
		bool zero_;
		size_t length_;
		std::vector<unsigned char> mem_;
	public:
		Chunk(size_t);
		Chunk(std::vector<unsigned char> mem);
		std::vector<unsigned char> &getContaint();
		bool isZero();
};
class Memory {
	private:
		size_t entry_;
		std::map<size_t, Chunk> chunks;
	public:
		void entry(size_t x) { entry_ = x; };
		size_t entry() { return entry_; };
		bool addChunk(size_t start_addr, Chunk chunk);
		std::pair<size_t, Chunk> popChunk(void);
		size_t firstAddress(void);
		bool empty(void);
};
}
#endif
