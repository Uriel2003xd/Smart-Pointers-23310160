/*
    ----------------------------------------Smart Pointer--------------------------------
    Nombre: Luis Uriel Arriaga Castañeda
    Registro: 23310160
    Grupo: 2P

    Un smart pointer (puntero inteligente) es un objeto que actúa como un puntero normal en un lenguaje de programación, 
    pero que también proporciona funcionalidades adicionales, como la gestión automática de la memoria. La gestión de la 
    memoria es una tarea crucial en la programación, especialmente en lenguajes como C++ donde la memoria debe ser asignada 
    y liberada manualmente.
    
    Los smart pointers se utilizan para evitar problemas comunes relacionados con la gestión manual de la memoria, 
    como fugas de memoria o accesos a memoria después de que se ha liberado. Estos problemas pueden ser difíciles 
    de detectar y solucionar, lo que hace que los smart pointers sean una herramienta valiosa para la escritura de 
    código robusto y seguro.

    En C++, cuando creas un objeto usando new, debes recordar liberar esa memoria más tarde con delete. 
    Pero a veces, es fácil olvidar liberar la memoria, lo que puede causar problemas como fugas de memoria.
    Aquí es donde entran en juego los smart pointers, o punteros inteligentes. Son como los punteros normales, 
    pero con superpoderes. Te ayudan a administrar la memoria automáticamente, lo que significa que no tienes 
    que preocuparte tanto por olvidarte de liberar la memoria.

*/
#include <iostream>
#include <memory> //librería <memory> para utilizar los smart pointers.


class MyClass { // Clase MyClass
public:
    MyClass(int value) : m_value(value) { // Constructor que inicializa el valor
        std::cout << "Constructora llamada value: " << m_value << std::endl; // Imprimimos un mensaje llamado constructor
    }

    ~MyClass() { // este es el Destructor
        std::cout << "Destructor pidió value: " << m_value << std::endl;// Destructor que imprime un mensaje al ser llamado
    }

    // Método para mostrar el valor
    void display() {
        std::cout << "Value: " << m_value << std::endl;
    }

private:
    int m_value; // Valor almacenado en MyClass
};

int main() {
    // Usando unique_ptr
    // Creamos un unique_ptr apuntando a un objeto MyClass creado con new
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));
    // Llamamos al método display() del objeto apuntado por uniquePtr
    uniquePtr->display();
    // Usando shared_ptr
    // Creamos un shared_ptr usando make_shared, que crea el objeto y devuelve un shared_ptr a él
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(10);
    // Creamos otro shared_ptr que apunta al mismo objeto que sharedPtr1
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1; // Incrementa el contador de referencia
    // Llamamos al método display() del objeto apuntado por sharedPtr1 y sharedPtr2
    sharedPtr1->display();
    sharedPtr2->display();
    // shared_ptr garantiza que la memoria sea liberada después de que ambos sharedPtr1 y sharedPtr2 se hayan quedado sin uso
    // Por lo que no hay necesidad de llamar a delete explícitament
    return 0;
}
