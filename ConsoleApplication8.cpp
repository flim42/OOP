#include <iostream>
#include <vector>
#include <typeinfo>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
using namespace std;

struct Leaks
{
	~Leaks()
	{
		_CrtDumpMemoryLeaks();
	}
}_leaks;

class BaseClass
{
public:
	BaseClass() {}
	virtual ~BaseClass() {}

	virtual BaseClass* clone()
	{
		BaseClass* copy = new BaseClass(*this);
		return copy;
	}
};

class Class2 : public BaseClass
{
public:
	Class2() {}
	~Class2() {}

	BaseClass* clone()
	{
		BaseClass* copy = new Class2(*this);
		return copy;
	}
};

void my_copy(BaseClass* obj, vector<BaseClass*>& dB)
{
	BaseClass* copy = obj->clone();
	dB.push_back(copy);
}

int main()
{
	BaseClass* obj1 = new BaseClass();
	BaseClass* obj2 = new Class2();

	vector<BaseClass*> DB;

	my_copy(obj1, DB);
	my_copy(obj2, DB);

	for (int i = 0; i < DB.size(); ++i)
	{
		cout << typeid(*(DB[i])).name() << endl;
		delete DB[i];
	}

	delete obj1;
	delete obj2;

	return 0;
}