inventario = {}
#[('pasta', {'nombre':'colgate', 'precio': 27.6}), ('leche', {'nombre':'santaClara', 'precio': 25.0}), ('papel', {'nombre':'petalos', 'precio': 73.0})]
clientes = []
trabajadores = {}

def agregar_suministros(codigo, nombre, precio):
    inventario[codigo] = {'nombre': nombre, 'precio': precio} #me sorprende que para modificar esto no se utilice global

# Función para quitar suministros del inventario
def quitar_suministros(codigo):
    if codigo in inventario:
        inventario.pop(codigo)
        return True
    return False

def ordenar_suministros(criterio):
    items = list(inventario.items())
    
    print("Debug 2")
    print(items)
    print("Debug 2")
    
    def merge_sort(items, key):
        if len(items) > 1:
            mid = len(items) // 2
            left_half = items[:mid]
            right_half = items[mid:]

            merge_sort(left_half, key)
            merge_sort(right_half, key)

            i = j = k = 0
            while i < len(left_half) and j < len(right_half):
                if key(left_half[i]) < key(right_half[j]):
                    items[k] = left_half[i]
                    i += 1
                else:
                    items[k] = right_half[j]
                    j += 1
                k += 1

            while i < len(left_half):
                items[k] = left_half[i]
                i += 1
                k += 1

            while j < len(right_half):
                items[k] = right_half[j]
                j += 1
                k += 1

    if criterio == 'nombre':
        merge_sort(items, key=lambda item: item[1]['nombre'])
    elif criterio == 'codigo':
        merge_sort(items, key=lambda item: item[0])
    
    print("Debug 3")
    print(items)
    print("Debug 3")
    return items
#_______________________________________________________________________________

def buscar_producto(busqueda):#esta busqueda qué representa, segun yo debería llamarse producto, o suministro al menos
    #la varaible busqueda es algo que vamos a buscar, ese algo puede ser nombre o código
    for codigo, producto in inventario.items():
        if codigo == busqueda or producto['nombre'] == busqueda:
            return codigo #creo que el punto es regresar algo
    return None #podiamos haber regresado True
    

saldo_cuenta = 1000

def cobro_productos(lista_productos):
    global saldo_cuenta
    total = 0
    ticket = []
    for busqueda in lista_productos:
        codigo = buscar_producto(busqueda)
        if codigo:
            total += inventario[codigo]['precio']
            ticket.append(f"{codigo} - {inventario[codigo]['nombre']} - ${inventario[codigo]['precio']}")
        else:
            print(f"Producto no encontrado: {busqueda}")
    
    print("\nTicket de pago:")
    for linea in ticket:
        print(linea)
    print(f"\nTotal: ${total}\n")
    
    if total <= saldo_cuenta:
        cuenta_bancaria = input("Ingresa tu cuenta bancaria para realizar el pago: ")
        saldo_cuenta -= total
        print(f"\nSe ha realizado el cobro a la cuenta {cuenta_bancaria}\n")
        print(f"Saldo restante en la cuenta: ${saldo_cuenta}\n")
    else:
        print("No hay suficiente saldo en la cuenta para realizar el pago\n")

def atencion_clientes(codigo_producto, mensaje):
    global clientes
    clientes.append({'codigo_producto': codigo_producto, 'mensaje': mensaje})

#_______________________________________________________________________________

def alta_trabajador(codigo, nombre, apellido, puesto):
    trabajadores[codigo] = {'nombre': nombre, 'apellido': apellido, 'puesto': puesto}

def baja_trabajador(codigo):
    if codigo in trabajadores:
        trabajadores.pop(codigo)
        print(f"El trabajador con código {codigo} ha sido dado de baja.")
    else:
        print(f"No se encontró un trabajador con código {codigo}.")

def cambio_puesto(codigo, nuevo_puesto):
    if codigo in trabajadores:
        trabajadores[codigo]['puesto'] = nuevo_puesto
        return True
    else:
        print(f"No se encontró un trabajador con código {codigo}.")
        return False

#*******************************************************************************

def menu():
    print('\n---Sistema de Administración de Puma Abarrotero S.A. de C.V.---\n')
    print('Menú:')
    print('1. Administración de Inventario')
    print('2. Atención a Clientes')
    print('3. Administración de Personal')
    print('4. Salir\n')
    
    opcion = input('Selecciona una opción: ')
    
    if opcion == '1':
        menu_inventario()
    elif opcion == '2':
        menu_clientes()
    elif opcion == '3':
        menu_personal()
    elif opcion == '4':
        return
#*******************************************************************************

def menu_inventario():
    print('\n---Administración de Inventario---\n')
    print('Menú:')
    print('1. Agregar suministros')
    print('2. Quitar suministros')
    print('3. Ordenar suministros\n')
    
    opcion = input('Selecciona una opción (deja en blanco para regresar al menú principal): ')
    
    if opcion == '':
        menu()
        return
    
    if opcion == '1':
        codigo = input('\nIngresa el código del suministro: ')
        nombre = input('Ingresa el nombre del suministro: ')
        precio = float(input('Ingresa el precio del suministro: '))
        agregar_suministros(codigo, nombre, precio)
        print(f'\nSuministro agregado: {codigo} - {nombre} - ${precio}\n')
        
    elif opcion == '2':
        busqueda = input('\nIngresa el código o el nombre del suministro: ')
        if quitar_suministros(busqueda):
            print('\nSuministro quitado\n')
        else:
            print('\nSuministro no encontrado\n')

    elif opcion == '3':
        if len(inventario) > 0:
            criterio = input('\nIngresa el criterio de orden (nombre o codigo): ')
            ordenados = ordenar_suministros(criterio)
            print("Debug 1")
            print(ordenados)
            print("Debug 1")
            for codigo, producto in ordenados:
                print(f"{codigo} - {producto['nombre']} - ${producto['precio']}")
            
        else:
            print("\nNo se ha ingresado ningún producto para ordenar. Agrega uno e intenta nuevamente.\n")
    
    menu_inventario()

#*******************************************************************************

def menu_clientes():
    print('\n---Atención a clientes---\n')
    print('Menú:')
    print('1. Cobro de productos')
    print('2. Atención a problemas\n')
    
    opcion = input('Selecciona una opción (deja en blanco para regresar al menú principal): ')
    
    if opcion == '':
        menu()
        return
    
    if opcion == '1':
        lista_productos = []
        
        while True:
            busqueda = input('\nAgrega los productos a tu lista (deja en blanco para terminar): ')
            
            if busqueda == '':
                break
            
            lista_productos.append(busqueda)
        
        cobro_productos(lista_productos)
        
    elif opcion == '2':
        codigo_producto = input('\nIngresa el código del producto: ')
        
        if not buscar_producto(codigo_producto): #si lo encuentra envia el código, si no lo encuentra envia None
            print("Producto no encontrado. Favor de ingresar un producto válido.")
            menu_clientes()
            #return
        
        mensaje = input('Ingresa tu queja o problema: ')
        
        atencion_clientes(codigo_producto, mensaje)
        
        print('\nQueja registrada\n')
    
    menu_clientes()

#*******************************************************************************

def menu_personal():
    print('\n---Administración de Personal---\n')
    print('Menú:')
    print('1. Altas')
    print('2. Bajas')
    print('3. Cambios de puesto\n')

    opcion = input('Selecciona una opción (deja en blanco para regresar al menú principal): ')

    if opcion == '':
        menu()
        return
    
    if opcion == '1':
        codigo = input('\nIngresa el código del trabajador: ')
        nombre = input('Ingresa el nombre del trabajador: ')
        apellido = input('Ingresa el apellido del trabajador: ')
        puesto = input('Ingresa el puesto del trabajador: ')

        alta_trabajador(codigo, nombre, apellido, puesto)

        print('\nTrabajador dado de alta\n')

    elif opcion == '2':
        codigo = input('\nIngresa el código del trabajador: ')

        baja_trabajador(codigo)

    elif opcion == '3':
        codigo = input('\nIngresa el código del trabajador: ')
        nuevo_puesto = input('Ingresa el nuevo puesto del trabajador: ')

        cambio_realizado = cambio_puesto(codigo, nuevo_puesto)

        if cambio_realizado:
            print(f"\nPuesto cambiado a {nuevo_puesto}\n")

    menu_personal()
        
menu()

#suministro es como producto, lo que pasa es que producto es como para lso clientes, el personal dice suminstro
#algo que me falta mencionar en el reporte es que iniciamos sin nada en el inventario