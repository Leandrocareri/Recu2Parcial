#include <stdio.h>
#include <stdlib.h>
#include "vehiculos.h"
#include <string.h>


eVehiculo* new_Vehiculo()
{
    eVehiculo* nuevoVehiculo;
    nuevoVehiculo = (eVehiculo*)malloc(sizeof(eVehiculo));
    if(nuevoVehiculo != NULL)
    {
        nuevoVehiculo->id = 0;
        strcpy(nuevoVehiculo->marca,"xx");
        nuevoVehiculo->tipo = 0;
        nuevoVehiculo->peso = 0;
    }
    return nuevoVehiculo;
}


eVehiculo* new_VehiculoParam(int id, char* marca, int tipo, float peso)
{
    eVehiculo* nuevoVehiculo;
    nuevoVehiculo = (eVehiculo*)malloc(sizeof(eVehiculo));
    if(nuevoVehiculo != NULL)
    {
        if(!(
                    vehiculoSetId(nuevoVehiculo,id) &&
                    vehiculoSetMarca(nuevoVehiculo,marca) &&
                    vehiculoSetTipo(nuevoVehiculo,tipo) &&
                    vehiculoSetPeso(nuevoVehiculo,peso)
                ))
        {
            free(nuevoVehiculo);
            nuevoVehiculo = NULL;
        }
    }
    return nuevoVehiculo;
}




int vehiculoSetId(eVehiculo* pVeh, int id)
{
    int todoOk=0;
    if(pVeh!=NULL && id>=0)
    {
        pVeh->id = id;
        todoOk=1;
    }
    else
    {
        printf("Id invalido\n");
    }
    return todoOk;
}


int vehiculoSetMarca(eVehiculo* pVeh, char* marca)
{
    int todoOk = 0;
    char auxCadena[20];
    if(pVeh!= NULL && marca!=NULL && strlen(marca)<20 && strlen(marca)>2)
    {
        strcpy(auxCadena,marca);
        strcpy(pVeh->marca,auxCadena);
        todoOk=1;
    }
    else
    {
        printf("Marca invalido\n");
    }
    return todoOk;
}


int vehiculoSetTipo(eVehiculo* pVeh, int tipo)
{
    int todoOk=0;
    if(pVeh!=NULL && tipo>=0)
    {
        pVeh->tipo = tipo;
        todoOk=1;
    }
    else
    {
        printf("Tipo invalido\n");
    }
    return todoOk;
}


int vehiculoSetPeso(eVehiculo* pVeh, float peso)
{
    int todoOk=0;
    if(pVeh!=NULL && peso>0)
    {
        pVeh->peso=peso;
        todoOk=1;
    }
    else
    {
        printf("Peso invalido\n");
    }
    return todoOk;
}


int vehiculo_getId(eVehiculo* this,int* id)
{
	int todoOk=0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk=1;
	}
	return todoOk;
}


int vehiculo_getMarca(eVehiculo* this,char* marca)
{
	int todoOk = 0;

	if(this != NULL && marca!= NULL)
	{
		strcpy(marca,this->marca);
		todoOk=1;
	}
	return todoOk;
}

int vehiculo_getTipo(eVehiculo* this,int* tipo)
{
	int todoOk=0;

	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		todoOk=1;
	}
	return todoOk;
}


int vehiculo_getPeso(eVehiculo* this,int* peso)
{
	int todoOk=0;

	if(this != NULL && peso != NULL)
	{
		*peso = this->peso;
		todoOk=1;
	}
	return todoOk;
}




int controller_saveAsText(char* path , eVehiculo* pVehiculo)
{
    int todoOk = 0;
    if(path != NULL && pVehiculo != NULL)
    {
    	FILE* f = fopen(path,"w");

    	if(f != NULL)
    	{
    		int auxId;
    		char auxMarca[20];
    		int auxTipo;
    		float auxPeso;

			for(int i=0; i<1; i++)
			{
				eVehiculo* auxVeh;

				vehiculo_getId(auxVeh,&auxId);
				vehiculo_getMarca(auxVeh,auxMarca);
				vehiculo_getTipo(auxVeh,auxTipo);
				vehiculo_getPeso(auxVeh,&auxPeso);

				fprintf(f,"%d,%s,%d,%.2f\n",auxId,auxMarca,auxTipo,auxPeso);
			}
			fclose(f);
			todoOk = 1;
		}
    }
	return todoOk;
}
