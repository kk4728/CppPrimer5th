#include <string>
#include <vector>

class Screen{
public:
	typedef std::string::size_type pos;
	using POS = std::string::size_type;

	Screen() = default;

	Screen(pos ht, pos wd, char c) : 
		height(ht), width(ht), 
		contents(ht*wd, c) {}
	char get() const {
		return contents[cursor]; 
	}
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);

	void some_menber() const {
		++access_ctr;
		//error
	}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
	mutable size_t access_ctr;

};


class Window_mgr {	
private:
	std::vector<Screen> screens {Screen(24, 80, ' ')};
//	std::vector<Screen> screens1 {Screen(24, 80, ' '); }; // error

	
};
