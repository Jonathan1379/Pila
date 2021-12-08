#ifndef LISTADOBLELIGADA_H
#define LISTADOBLELIGADA_H

#include <iostream>

using namespace std;
template <class T>
class listadobleligada
{
    public:
        listadobleligada();
        ~listadobleligada();

        bool empty();

        //insertar
        void push_front(const T &dato);
        void push_back(const T &dato);
        size_t size();
        void insert(const T &dato,size_t p);

        //imprimir
        void print();
        void print_reverse();
        T* front();
        T* back();
        T* find(const T &dato);
        listadobleligada& operator<<(const T &dato)
        {
            push_back(dato);
            return *this;
        }

        //eliminar

        void pop_back();
        void pop_front();
        void erase(size_t p);
        void remove_if(const T &dato);

        T* operator[](size_t p)
        {
            size_t pos=0;
            Nodo *temp=head;

            while(temp!=nullptr){

                if(p==pos){
                    return &temp->dato;
                }
                temp=temp->sig;
                pos++;
            }

            return nullptr;
        }

    private:
        struct Nodo {

            T dato;
            Nodo *sig;
            Nodo *ant;

            Nodo(const T &dato, Nodo *sig=nullptr, Nodo *ant=nullptr):dato(dato),sig(sig),ant(ant){}
        };

        Nodo *head;
        Nodo *tail;
        size_t cont;
};

template <class T>
listadobleligada<T>::listadobleligada()
{
    head=nullptr;
    tail=nullptr;
    cont =0;
}

template <class T>
listadobleligada<T>::~listadobleligada()
{
 //Eliminar todos los nodos

 while(!empty())
 {
     pop_front();

 }


}
template <class T>
bool listadobleligada<T>::empty()
{
    return cont==0;
}
template <class T>
void listadobleligada<T>::push_front(const T &dato)
{
    Nodo *nodo=new Nodo(dato,head);
    if(cont==0){
        head=nodo;
        tail=nodo;

    }else{
        head->ant=nodo;
        head=nodo;
    }
    cont++;
}
template <class T>
void listadobleligada<T>::push_back(const T &dato)
{
    Nodo *nodo=new Nodo(dato,nullptr,tail);
    if(cont==0){
        head=nodo;
        tail=nodo;
    }else{
        tail->sig=nodo;
        tail=nodo;
    }
    cont++;
}
template <class T>
size_t listadobleligada<T>::size()
{
    return cont;
}
template <class T>
void listadobleligada<T>::print()
{
    Nodo *temp= head;
    while(temp!=nullptr)
    {
        cout<<temp->dato<<endl;
        temp=temp->sig;
    }
}
template <class T>
T* listadobleligada<T>::find(const T &dato)
{
  Nodo *nodo=new Nodo(dato);
  Nodo *temp=head;
  while(temp!=nullptr)
  {
    if(nodo->dato == temp->dato){
        return &temp->dato;
    }
    temp=temp->sig;
  }
return nullptr;
}
template <class T>
void listadobleligada<T>::print_reverse()
{
    Nodo *temp=tail;
    while(temp!=nullptr)
    {
        cout<<temp->dato<<endl;
        temp=temp->ant;
    }

}
template <class T>
T* listadobleligada<T>::front()
{
    if(empty()){
        return nullptr;
    }else{
        return &head->dato;
    }
}
template <class T>
T* listadobleligada<T>::back()
{
    if(empty()){
        return nullptr;
    }else{
        return &tail->dato;
    }
}
template <class T>
void listadobleligada<T>::pop_front()
{
    if(empty()){
        cout<<"Lista vacia"<<endl;


    }else if(cont==1){
        delete head;
        head=nullptr;
        tail=nullptr;
        cont--;

    }else{
        Nodo *temp=head->sig;

        head->sig->ant = nullptr;
        delete head;
        head=temp;

        cont--;
    }




}

template <class T>
void listadobleligada<T>::pop_back()
{
    if(empty()){
        cout<<"Lista vacia"<<endl;


    }else if(cont==1){

        delete tail;
        head=nullptr;
        tail=nullptr;
        cont--;


    }else{

        Nodo *temp=tail->ant;

        temp->sig=nullptr;

        delete tail;
        tail=temp;
        cont--;



    }



}
template <class T>
void listadobleligada<T>::insert(const T &dato,size_t p)
{
    if(p>=cont){

        cout<<"No valida"<<endl;
    }else if(p==0){
        push_front(dato);
    }else{
        Nodo *temp=head->sig;

        size_t pos=1;

        while(temp != nullptr){
                if(p==pos){

                        Nodo *nodo=new Nodo(dato);

                        nodo->sig=temp;
                        nodo->ant=temp->sig;

                        temp->ant->sig=nodo;
                        nodo->sig->ant=nodo;

                        cont++;
                        break;

                }
                temp=temp->sig;
                pos++;
        }


    }



}
template <class T>
void listadobleligada<T>::erase(size_t p)
{
    if(p>=cont){
        cout<<"No valida"<<endl;
    }else if(p==0){
        pop_front();
    }else if(p==cont-1){
        pop_back();
    }else{
        Nodo *temp=head->sig;
        size_t pos=1;
         while(temp != nullptr){
                if(p==pos){

                    temp->ant->sig=temp->sig;
                    temp->sig->ant=temp->ant;
                    delete temp;
                    cont--;
                    break;
                }
                temp=temp->sig;
                pos++;
        }
    }
}

template <class T>
void listadobleligada<T>::remove_if(const T &dato)
{
         Nodo *temp=head;
         while(temp != nullptr){
                if(temp->dato==dato){
                        if(temp->ant==nullptr){
                            pop_front();
                            temp=head;

                        }else if(temp->sig==nullptr){
                            pop_back();
                            break;
                        }else{
                            Nodo *aux=temp->sig;

                             temp->ant->sig=temp->sig;
                             temp->sig->ant=temp->ant;
                             delete temp;
                             temp=aux;
                             cont--;
                        }
                }else{
                    temp=temp->sig;
                }
        }
    }




#endif // LISTADOBLELIGADA_H
