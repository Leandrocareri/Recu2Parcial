#include <stdio.h>
#include <stdlib.h>
#include "vehiculos.h"
#include <string.h>


int main()
{

    eVehiculo* vehiculo1 = NULL;
        vehiculo1 = new_VehiculoParam(1,"Renault",2,3300);


    if(controller_saveAsText("vehiculo.csv",vehiculo1))
				{
					printf("Se guardo el archivo en modo texto correctamente\n");
				}
				else
				{
					printf("Error al guardar el archivo en modo texto \n");
				}
				system("pause");







    return 0;
}
