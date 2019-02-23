#include <memory>
#include <vector>
#include <string>
#include <iostream>

void func(int n) {
	std::allocator<std::string> alloc; //声明
	auto const p = alloc.allocate(n); //申请未构造的内存

	//测试构造使用
	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	std::cout << *(q-1) << std::endl;

	alloc.construct(q++, "hi");
	std::cout << *(q-1) << std::endl;
//	std::cout << *q << std::endl; //error! q指向未构造的内存!

	//释放我们真正构造的string
	std::cout << "destroy string..." << std::endl;
	while( q != p)
		alloc.destroy(--q); //只对真正构造了的元素进行destroy操作
	//一旦元素被销毁后，就可以重新使用这部分内存来保存其他string

	//也可以将其归还给系统。
	std::cout << "deallocate! " << std::endl;
	//alloc.deallocate(p, n-1); //
	alloc.deallocate(p, n); //n的大小必须与申请时一致!G
}




void f() {
	std::vector<int> vi = {1,2,3,4,5,6,7,8};	
	std::allocator<int> alloc;
	
	auto p = alloc.allocate(vi.size() *2);

	auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
	std::uninitialized_fill_n(q, vi.size(), 42);
	for(int i=0; i!= vi.size(); i++) 
		std::cout << *(p+i) << " ";
	std::cout << std::endl;


	for(int i=0; i!= vi.size(); i++) 
		alloc.destroy(p+i);
	alloc.deallocate(p, vi.size()*2);
}


int main() 
{
	func(100);	
	f();

	return 0;
}

