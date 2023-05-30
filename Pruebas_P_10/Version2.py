# Función para agregar un libro
def agregar_libro(*books): #la variable books en esta funcion y la variable libros en el main son alias para el mismo objeto
    titulo = input('Ingrese el título del libro: ')
    books.append(titulo)
    print('Libro agregado:', titulo)
    #return books

# Función para eliminar un libro
def eliminar_libro(libros):
    titulo = input('Ingrese el título del libro: ')
    if titulo in libros:
        libros.remove(titulo)
        print('Libro eliminado:', titulo)
    else:
        print('Libro no encontrado')

# Función para ordenar la biblioteca
def ordenar_biblioteca(libros):
    libros.sort()
    print('\nLa biblioteca queda con el siguiente orden:\n')
    for libro in libros:
        print(libro)

# Función para ver la biblioteca
def ver_biblioteca(books): #el argumento recibido se puede llamar diferente
    print('\nLa biblioteca contiene los siguientes libros:\n')
    print(books)

# Menú principal
if __name__ == '__main__':
    libros = [] #lista de libros local 
    while True:
        print('\nBienvenido a la biblioteca, puede realizar las siguientes operaciones:\n')
        print('1 Agregar libro')
        print('2 Eliminar libro')
        print('3 Ordenar biblioteca')
        print('4 Ver biblioteca')
        print('5 Salir')
        opcion = input('\nIngrese la opción: ')
            
        if opcion == '1':
            agregar_libro(*libros)
            #libros=agregar_libro(libros)
            print(libros)
        elif opcion == '2':
            eliminar_libro()
        elif opcion == '3':
            ordenar_biblioteca()
        elif opcion == '4':
            ver_biblioteca(libros)
        elif opcion == '5':
            break


#nota nueva, *args es para tuplas(también para listas), **es para diccionarios.
#nota, una lista1 igual a otra lista2, si moficas cualquiera de las dos, modificas la otra