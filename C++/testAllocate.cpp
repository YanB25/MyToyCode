#include <memory>
using std::allocator;
template<typename T>
class bar {
public:
	bar() { alloc.allocate(1); };
private:
	static allocator<T> alloc;
};

int main() {
	bar<int> b;
	return 0;
}
