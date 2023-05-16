# Función para agregar un libro
def agregar_libro(libros):
    titulo = input('Ingrese el título del libro: ')
    libros.append(titulo)
    print('Libro agregado:', titulo)

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
def ver_biblioteca(libros):
    print('\nLa biblioteca contiene los siguientes libros:\n')
    for libro in libros:
        print(libro)

# Menú principal
if __name__ == '__main__':
    while True:
        libros = [] #lista de libros local global
        print('\nBienvenido a la biblioteca, puede realizar las siguientes operaciones:\n')
        print('1 Agregar libro')
        print('2 Eliminar libro')
        print('3 Ordenar biblioteca')
        print('4 Ver biblioteca')
        print('5 Salir')
        opcion = input('\nIngrese la opción: ')
        
        if opcion == '1':
            agregar_libro(libros)
        elif opcion == '2':
            eliminar_libro(libros)
        elif opcion == '3':
            ordenar_biblioteca(libros)
        elif opcion == '4':
            ver_biblioteca(libros)
        elif opcion == '5':
            break