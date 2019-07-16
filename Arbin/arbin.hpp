#ifndef _ARBIN_H_
#define _ARBIN_H_

#include"nodo_arbol.hpp"
#include"lista.hpp"

template<class T> class ArBin
{
	protected:
		Nodo_Arbol<T> *raiz;	

		static bool Buscar(Nodo_Arbol<T>*,T);
		static Nodo_Arbol<T>* Buscar(T,Nodo_Arbol<T>*);
		static Nodo_Arbol<T>* construir_pre_in(Lista<T>&,Lista<T>);
		static Nodo_Arbol<T>* construir_pos_in(Lista<T>&,Lista<T>);
		static Nodo_Arbol<T>* BuscarMe(Nodo_Arbol<T>*,T,Nodo_Arbol<T>*);
		static Nodo_Arbol<T>* BuscarMa(Nodo_Arbol<T>*,T,Nodo_Arbol<T>*);
		static Nodo_Arbol<T>* Buscar_ant(Nodo_Arbol<T>*,Nodo_Arbol<T>*);
		static void PreOrden(Nodo_Arbol<T>*,Lista<T>&);
		static void InOrden(Nodo_Arbol<T>*,Lista<T>&);
		static void PostOrden(Nodo_Arbol<T>*,Lista<T>&);
		static Nodo_Arbol<T>* Copiar(Nodo_Arbol<T>*);
		static void Altura(Nodo_Arbol<T>*,int,int&);
		static bool Es_completo(Nodo_Arbol<T>*);		
		static bool Esta_lleno(Nodo_Arbol<T>*,int,int);		
		static void Esta_casi_lleno(Nodo_Arbol<T>*,int,int,bool&,bool&);
		static void Es_Ocurrencia(Nodo_Arbol<T>*,Nodo_Arbol<T>*,Nodo_Arbol<T>*,int&);
		static void Nivel(Nodo_Arbol<T>*, Lista<T>&)		
		static int Peso(Nodo_Arbol<T>*);		
		static void Destruir(Nodo_Arbol<T>*);
		static void NodosH(Nodo_Arbol<T>*,Lista<T>&);
		inline void Copiar(const ArBin<T>&);		
	public:
		inline ArBin(void);
		inline bool Es_vacia(void);
		inline T Raiz(void);
		ArBin(Lista<T>,Lista<T>,int);
		inline ArBin(const ArBin<T>&);
		inline Lista<T> PreOrden(void) const;
		inline Lista<T> InOrden(void) const;
		inline Lista<T> PostOrden(void) const;
		Lista<T> Nivel(void) const;
		inline Lista<T> NodosH(void) const;
		inline ArBin<T> Obt_hijiz(void) const;
		inline ArBin<T> Obt_hijde(void) const;
		inline T BuscarMe(T);
		inline T BuscarMa(T);
		inline bool Buscar(T) const;
		inline bool Es_Nulo(void) const;
		inline bool Es_completo(void) const;
		bool Esta_lleno(void) const;
		bool Esta_casi_lleno(void) const;		
		inline bool Es_isomorfo(const ArBin<T>&) const;		
		bool Es_Ocurrencia(const ArBin<T>&) const;			
		int Altura(void) const;
		inline int Peso(void) const;
		ArBin<T>& operator= (const ArBin<T>&);
		inline bool operator== (const ArBin<T>&) const;
		virtual ~ArBin(void);
};

template<class T> ArBin<T>::ArBin(void)
{
	raiz = NULL;
}

template<class T> ArBin<T>::ArBin(Lista<T> pre , Lista<T> in, int opc)
{
	Lista<T> apre;

	switch(opc)
	{
		case 1:
			apre = pre;
			raiz = construir_pre_in(apre,in);
		break;

		case 2:
			apre = pre;
			apre.invertir();
			raiz = construir_pos_in(apre,in);
		break;
	}
}

template<class T> ArBin<T>::ArBin(const ArBin<T> &a)
{
	raiz = Copiar(a.raiz);
}

template<class T> bool ArBin<T>::Es_vacia(void)
{
	return raiz == NULL;
}

template<class T> T ArBin<T>::Raiz(void)
{
	return raiz->cons_info();
}

template<class T> Lista<T> ArBin<T>::PreOrden(void) const
{
	Lista<T> l;
	PreOrden(raiz,l);
	l.invertir();
	return l;
}

template<class T> Lista<T> ArBin<T>::InOrden(void) const
{
	Lista<T> l;
	InOrden(raiz,l);
	l.invertir();
	return l;
}

template<class T> Lista<T> ArBin<T>::PostOrden(void) const
{
	Lista<T> l;
	PostOrden(raiz,l);
	l.invertir();
	return l;
}

template <class T> Lista<T> ArBin<T>::Nivel(void) const
{
	Lista<T> a;

	Nivel(raiz,a);
	return a;
}

template<class T> Lista<T> ArBin<T>::NodosH(void) const
{
	Lista<T> l;

	NodosH(raiz,l);
	l.invertir();
	return l;
}

template<class T> void ArBin<T>::Copiar(const ArBin<T> &a)
{
	raiz = Copiar(a.raiz); 
}

template<class T> ArBin<T> ArBin<T>::Obt_hijiz(void) const
{
	ArBin<T> A;

	A.raiz = copiar(raiz->cons_hijiz());
	return A;
}

template<class T> ArBin<T> ArBin<T>::Obt_hijde(void) const
{
	ArBin<T> A;

	A.raiz = copiar(raiz->cons_hijde());
	return A;
}

template<class T> int ArBin<T>::Altura(void) const
{
	int aux=1,aux2=-1;

	Altura(raiz,aux,aux2);
	return aux2;
} 

template<class T> int ArBin<T>::Peso(void) const
{
	return Peso(raiz);
}

template<class T> bool ArBin<T>::Es_Nulo(void) const
{
	return raiz == NULL;
}

template<class T> bool ArBin<T>::Es_completo(void) const
{
	return Es_completo(raiz);
}

template<class T>  bool ArBin<T>::Buscar(T e) const
{
	return Buscar(raiz,e);
}


template<class T> bool ArBin<T>::Esta_lleno(void) const
{
	int aux=1,aux2=-1;
	Altura(raiz,aux,aux2);
	return Esta_lleno(raiz,aux2,aux);
}

template<class T> bool ArBin<T>::Esta_casi_lleno(void) const
{
	int aux=1,aux2=-1;
	bool band=false, band2 = false;
	
	Altura(raiz,aux,aux2);
	if(!Esta_lleno())
		Esta_casi_lleno(raiz,aux2,aux,band,band2);

	return band2;
}

template<class T> T ArBin<T>::BuscarMe(T e)
{
	
	
	return BuscarMe(raiz,e,raiz)->cons_info();
}

template<class T> T ArBin<T>::BuscarMa(T e)
{
	
	
	return BuscarMa(raiz,e,raiz)->cons_info();
}

template<class T> bool ArBin<T>::Es_isomorfo(const ArBin<T> &A) const
{
	return A.PreOrden().obtlongitud() == PreOrden().obtlongitud(); 
}

template<class T> bool ArBin<T>::Es_Ocurrencia(const ArBin<T> &A) const
{
	bool band = false;
	int aux;
	
	aux = Peso(A.raiz);
	Es_Ocurrencia(A.raiz,raiz,A.raiz,aux);
	
	if(aux == 0)
		band = true;
	return band;
}

template<class T> bool ArBin<T>::Buscar(Nodo_Arbol<T> *a, T e)
{
	bool band = false;

	if(a != NULL and e != a->cons_info())
	{
		band = Buscar(a->cons_hijiz(),e);
		if(!band)
			band = Buscar(a->cons_hijde(),e);
	}
	else
	{
		if(a != NULL and e == a->cons_info())
			band = true;
	}
	
	return band;
}

template<class T>  Nodo_Arbol<T>* ArBin<T>::Buscar(T e, Nodo_Arbol<T> *a)
{
	Nodo_Arbol<T> *aux = NULL;

	if(a != NULL)
	{
		if(a->cons_info() == e)
			aux = a;
		else
		{
			aux = Buscar(e,a->cons_hijiz());
			if(aux == NULL)
				aux = Buscar(e,a->cons_hijde());
		}	
	}

	return aux;
}

template<class T> Nodo_Arbol<T>* ArBin<T>::BuscarMe(Nodo_Arbol<T> *a, T e, Nodo_Arbol<T> *m)
{
	
	Nodo_Arbol<T> *aux = m;

	if(a != NULL)
	{
		if(a->cons_info() < e)
		{
			aux = a;
			e = aux->cons_info();
		}

		aux = BuscarMe(a->cons_hijiz(),e,aux);
		aux = BuscarMe(a->cons_hijde(),aux->cons_info(),aux);
	} 
	
	return aux;
}

template<class T> Nodo_Arbol<T>* ArBin<T>::BuscarMa(Nodo_Arbol<T> *a, T e, Nodo_Arbol<T> *m)
{
	Nodo_Arbol<T> *aux = m;

	if(a != NULL)
	{
		if(a->cons_info() > e)
		{
			aux = a;
			e = aux->cons_info();
		}

		aux = BuscarMe(a->cons_hijiz(),e,aux);
		aux = BuscarMe(a->cons_hijde(),aux->cons_info(),aux);
	} 
	
	return aux;
}

template<class T> Nodo_Arbol<T>* ArBin<T>::Buscar_ant(Nodo_Arbol<T> *r, Nodo_Arbol<T> *b)
{
	Nodo_Arbol<T> *aux = NULL;

	if(r != NULL)
	{
		if(r->cons_hijiz() == b)
			aux = r;
		else
		{
			if(r->cons_hijde() == b)
				aux = r;
			else
			{
				aux = Buscar_ant(r->cons_hijiz(),b);
				if(aux == NULL)
					aux = Buscar_ant(r->cons_hijde(),b);
			}
		}
	}

	return aux;
}

template<class T> void ArBin<T>::Es_Ocurrencia(Nodo_Arbol<T> *a, Nodo_Arbol<T> *b, Nodo_Arbol<T> *aux, int &pes)
{
	if(a != NULL and b != NULL and pes > 0)
	{
		if(a->cons_info() == b->cons_info())
		{
			pes--;
			Es_Ocurrencia(a->cons_hijiz(),b->cons_hijiz(),aux,pes);
			if(pes > 0)			
				Es_Ocurrencia(a->cons_hijde(),b->cons_hijde(),aux,pes);	
		}
		else
		{
			pes = Peso(aux);
			Es_Ocurrencia(aux,b->cons_hijiz(),aux,pes);
			Es_Ocurrencia(aux,b->cons_hijde(),aux,pes);
		}
	}
}

template<class T> int ArBin<T>::Peso(Nodo_Arbol<T> *a)
{
	int aux=0;

	if(a != NULL)
	{
		aux = 1 + Peso(a->cons_hijiz());
		aux = aux + Peso(a->cons_hijde());
	}
	
	return aux;
}

template<class T> void ArBin<T>::Esta_casi_lleno(Nodo_Arbol<T> *a, int al, int acum, bool &ban, bool &band)
{

	if(a->cons_hijiz() != NULL and a->cons_hijde() != NULL)
	{
		Esta_casi_lleno(a->cons_hijiz(),al,acum+1,ban,band);
		if(band)
			Esta_casi_lleno(a->cons_hijde(),al,acum+1,ban,band);
	}
	else
	{
		if(a->cons_hijiz() == NULL and a->cons_hijde() == NULL and acum == al and !ban)
			band = true;
		else
		{
			if(a->cons_hijiz() == NULL and a->cons_hijde() == NULL and acum == al-1)
				ban = true;
			else
				band = false;
		}
	}
}

template<class T> bool ArBin<T>::Esta_lleno(Nodo_Arbol<T> *a, int al, int acum)
{
	bool band;

	if(a->cons_hijiz() != NULL and a->cons_hijde() != NULL)
	{
		band = Esta_lleno(a->cons_hijiz(),al,acum+1);
		if(band)
			band = Esta_lleno(a->cons_hijde(),al,acum+1);
	}
	else
	{
		if(a->cons_hijiz() == NULL and a->cons_hijde() == NULL and acum == al)
			band = true;
		else
			band = false;
	}

	return band;
}

template<class T> bool ArBin<T>::Es_completo(Nodo_Arbol<T> *a)
{	
	bool band;

	if(a->cons_hijiz() != NULL and a->cons_hijde() != NULL)
	{
		band = Es_completo(a->cons_hijiz());
		if(band)
			band = Es_completo(a->cons_hijde());
	}
	else
	{
		if(a->cons_hijiz() == NULL and a->cons_hijde() == NULL)
			band = true;
		else
			band = false;
	}

	return band;
}

template<class T> void ArBin<T>::Altura(Nodo_Arbol<T> *a, int acum , int &ni)
{
	if(a != NULL and (a->cons_hijiz() != NULL or a->cons_hijde() != NULL))
	{
		Altura(a->cons_hijiz(),acum+1,ni);
		Altura(a->cons_hijde(),acum+1,ni);
	}
	else
	{
		if(acum > ni)
			ni = acum;
	}

}

template<class T> Nodo_Arbol<T>* ArBin<T>::Copiar(Nodo_Arbol<T> *a)
{
	Nodo_Arbol<T> *aux;

	if(a != NULL)
	{
		aux = new Nodo_Arbol<T>;
		aux->mod_info(a->cons_info());
		aux->mod_hijiz(Copiar(a->cons_hijiz()));
		aux->mod_hijde(Copiar(a->cons_hijde()));
	}
	else
		aux = NULL;

	return aux;
}

template<class T> void ArBin<T>::PreOrden(Nodo_Arbol<T> *aux, Lista<T> &l)
{
	if(aux != NULL)
	{
		l.insertar(1,aux->cons_info());
		PreOrden(aux->cons_hijiz(),l);
		PreOrden(aux->cons_hijde(),l);
	}
}

template<class T> void ArBin<T>::InOrden(Nodo_Arbol<T> *aux, Lista<T> &l)
{
	if(aux != NULL)
	{
		InOrden(aux->cons_hijiz(),l);
		l.insertar(1,aux->cons_info());
		InOrden(aux->cons_hijde(),l);
	}
}

template<class T> void ArBin<T>::PostOrden(Nodo_Arbol<T> *aux, Lista<T> &l)
{
	if(aux != NULL)
	{
		PostOrden(aux->cons_hijiz(),l);
		PostOrden(aux->cons_hijde(),l);
		l.insertar(1,aux->cons_info());
	}
}

template <class T> 
void ArBin<T>::Nivel(Nodo_Arbol<T> *r, Lista<T> &a)
{
	Lista<T> l;
	Cola<Nodo_Arbol<T>* > aux;
	Nodo_Arbol<T> *ptr;
	
	if(r != NULL)
	{
		ptr = r;
		l.insertar(1,ptr->cons_info());
		if(ptr->cons_hijiz() != NULL)
		{
			aux.encolar(ptr->cons_hijiz());
		}
		if(ptr->cons_hijde() != NULL)
		{
			aux.encolar(ptr->cons_hijde());
		}
		
		while(!aux.es_vacia())
		{
			l.insertar(1,aux.frente()->cons_info());
			
			ptr = aux.frente();
			aux.desencolar();
			if(ptr->cons_hijiz() != NULL)
			{
				aux.encolar(ptr->cons_hijiz());
			}
			if(ptr->cons_hijde() != NULL)
			{
				aux.encolar(ptr->cons_hijde());
			}
		}
		l.invertir();
	}
	a = l;
}

template<class T> void ArBin<T>::NodosH(Nodo_Arbol<T> *a, Lista<T> &l)
{
	if(a != NULL)
	{
		if(a->cons_hijiz() == NULL and a->cons_hijde() == NULL)
			l.insertar(1,a->cons_info());
		else
		{
			NodosH(a->cons_hijiz(),l);
			NodosH(a->cons_hijde(),l);
		}
	}
} 

template<class T> Nodo_Arbol<T>* ArBin<T>::construir_pre_in(Lista<T> &pre, Lista<T> in)
{
	Nodo_Arbol<T> *aux = NULL;
	Lista<T> aux1;

	if(!in.es_vacia())
	{
		aux = new Nodo_Arbol<T>;
		aux->mod_info(pre.consultar(1));
		pre.eliminar(1);
		in.separar(aux1,in.localizar(aux->cons_info()));
		aux->mod_hijiz(construir_pre_in(pre,aux1));
		aux->mod_hijde(construir_pre_in(pre,in));	
	}

	return aux;	
}

template<class T> Nodo_Arbol<T>* ArBin<T>::construir_pos_in(Lista<T> &pos , Lista<T> in)
{
	Nodo_Arbol<T> *aux = NULL;
	Lista<T> aux1;

	if(!in.es_vacia())
	{
		aux = new Nodo_Arbol<T>;
		aux->mod_info(pos.consultar(1));
		pos.eliminar(1);
		in.separar(aux1,in.localizar(aux->cons_info()));
		aux->mod_hijde(construir_pos_in(pos,in));
		aux->mod_hijiz(construir_pos_in(pos,aux1));	
	}

	return aux;
}

template<class T> ArBin<T>& ArBin<T>::operator= (const ArBin<T> &a)
{
	raiz = Copiar(a.raiz);
	return *this;
}


template<class T> bool ArBin<T>::operator== (const ArBin<T> &A) const
{
	return PreOrden() == A.PreOrden();
}
 
template<class T> ArBin<T>::~ArBin(void)
{
	Destruir(raiz);
	delete raiz;
}

template<class T> void ArBin<T>::Destruir(Nodo_Arbol<T> *a)
{
	if(a != NULL)
	{
		Destruir(a->cons_hijiz());
		delete a->cons_hijiz();
		Destruir(a->cons_hijde());
		delete a->cons_hijde();
	}
}

#endif
