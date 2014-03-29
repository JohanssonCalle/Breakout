// BaseClass.h

#pragma once

class BaseClass {
public:
	BaseClass();
	virtual ~BaseClass();

private:
	int m_some_data;
protected:
	int m_some_more_data;
};

class DerivedClass : public BaseClass {
public:
	DerivedClass();
	~DerivedClass();

	void Method();
};

class SuperClass : public DerivedClass {
public:
	SuperClass();
	~SuperClass();
};