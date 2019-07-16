#ifndef _NODO_H_
#define _NODO_H_

//Librerias usadas en la clase
#include <iostream>
using namespace std;

//Clase nodo
template<class T> class Nodo
{
	//Atributos de la clase
	private:
		T info;
		Nodo<T> *prox;
	//Metodos publicos de la clase
	public:
		//Constructor por defecto
		inline Nodo<T>(void);
		//Consultores
		inline Nodo<T>* consultarprox(void) const;
		inline T consultarinfo(void) const;
		//Modificadores
		inline void modificarprox(Nodo<T>*);
		inline void modificarinfo(T);

};

//Desarrollo del constructor por defecto
template<class T> Nodo<T>::Nodo(void)
{
	//Inicializacion del apuntador
	prox = NULL;
}

//Desarrollo del consultor prox
template<class T> Nodo<T>* Nodo<T>::consultarprox(void) const
{
	//Retorno del apuntador del siguiente nodo
	return prox;
}

//Desarrollo del consultor info
template<class T> T Nodo<T>::consultarinfo(void) const
{
	//Retorno de la informacion del nodo
	return info;

}

//Desarrollo del modificador prox
template<class T> void Nodo<T>::modificarprox(Nodo<T> *n)
{
	//Asignacion de la nueva direccion
	prox = n;
}

//Desarrollo del modificador info
template<class T> void Nodo<T>::modificarinfo(T n)
{
	//Asignacion de la nueva informacion del nodo
	info = n;
}

#endif
