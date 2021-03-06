#pragma once
#include "tree/rooted.h"

template<class T> struct HLD:public RootedTree<T>{
	HLD(){}
	HLD(const Arr<pair<int, T>>& pi):RT(pi),cn(n),top(n){
		int ccn=0;
		func(void,dfs,int x){
			if(sz(ch[x]))
				swap(ch[x].front(), *max_element(ch[x].begin(),ch[x].end(), lam(tsz[a.fi]<tsz[b.fi],auto a,auto b)));
			cn[x]=ccn;
			for(int i=0;i<sz(ch[x]);i++){
				if(i) top[++ccn]=ch[x][i].fi;
				dfs(ch[x][i].fi);
			}
		};
		dfs(r);
		ord=RT::pre(),top[0]=r;
	}

	int iter(int a, int b, const auto& f, bool vtxw) {
		while(cn[a]!=cn[b])
			if(dpt[top[cn[a]]]<dpt[top[cn[b]]])
				f(ord[top[cn[b]]],ord[b]+1),b=p[top[cn[b]]].fi;
			else
				f(ord[top[cn[a]]],ord[a]+1),a=p[top[cn[a]]].fi;
		if(dpt[a]>dpt[b]) swap(a,b);
		f(ord[a]+!vtxw,ord[b]+1);
		return a;
	}
	int lca(int a, int b) { return iter(a,b,[&](int _, int __){},true); }

	Arr<int> cn,top,ord;  // chain number, top of the chain, vtx to preord
	using RT = RootedTree<T>;using RT::ch;using RT::dpt;using RT::n;using RT::p;using RT::r;using RT::tsz;
};

//<See Also>
// https://www.acmicpc.net/source/share/7cc26b5459334944930192c6e75fe019
// https://www.acmicpc.net/source/share/98c5f45fedcc4a579b5410e8ee33cd79
// https://codeforces.com/group/q4aFsZ9De9/contest/288125/submission/99012892
