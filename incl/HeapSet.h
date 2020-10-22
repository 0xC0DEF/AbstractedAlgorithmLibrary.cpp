#pragma once
#include "Core.h"

template<class T, bool mx=false>
struct HeapSet{
	void add(const T& x){a.push(mx?-x:x);}
	void del(const T& x){b.push(mx?-x:x);}
	void pop(){get();a.pop();}
	T get(){
		while(sz(b) and b.top()==a.top())
			b.pop(),a.pop();
		return mx?-a.top():a.top();
	}
	int size()const{return sz(a)-sz(b);}
	PQMIN(T) a,b;
};