#ifndef _NODO_ARBOL_H_
#define _NODO_ARBOL_H_

#include<iostream>
using namespace std;

template<class T> class Nodo_Arbol
{
	private:
		T info;
		Nodo_Arbol<T> *hijiz;
		Nodo_Arbol<T> *hijde;
	public:
		Nodo_Arbol(void);
		Nodo_Arbol(T,Nodo_Arbol<T>*,Nodo_Arbol<T>*);
		Nodo_Arbol(const Nodo_Arbol&);
		inline Nodo_Arbol<T>* cons_hijiz(void) const;
		inline Nodo_Arbol<T>* cons_hijde(void) const;
		inline T cons_info(void) const;
		inline void mod_hijiz(Nodo_Arbol<T>*);
		inline void mod_hijde(Nodo_Arbol<T>*);
		inline void mod_info(T);
		~Nodo_Arbol(void);
};

template<class T> Nodo_Arbol<T>::Nodo_Arbol(void)
{
	hijiz = NULL;
	hijde = NULL;
}

template<class T> Nodo_Arbol<T>::Nodo_Arbol(T e, Nodo_Arbol<T> *hd, Nodo_Arbol<T> *hi)
{
	info = e;
	hijiz = hi;
	hijde = hd;
}

template<class T> Nodo_Arbol<T>::Nodo_Arbol(const Nodo_Arbol &a)
{
	info = a.info;
	hijiz = a.hijiz;
	hijde = a.herde;
}

template<class T> Nodo_Arbol<T>* Nodo_Arbol<T>::cons_hijiz(void) const
{
	return hijiz;
}

template<class T> Nodo_Arbol<T>* Nodo_Arbol<T>::cons_hijde(void) const
{
	return hijde;
}

template<class T> T Nodo_Arbol<T>::cons_info(void) const
{
	return info;
}

template<class T> void Nodo_Arbol<T>::mod_hijiz(Nodo_Arbol<T> *hi)
{
	hijiz = hi;
}


template<class T> void Nodo_Arbol<T>::mod_hijde(Nodo_Arbol<T> *hd)
{
	hijde = hd;
}
		
template<class T> void Nodo_Arbol<T>::mod_info(T e)
{
	info =  e;
}

template<class T> Nodo_Arbol<T>::~Nodo_Arbol(void)
{
	hijiz = NULL;
	hijde = NULL;
}

#endif
