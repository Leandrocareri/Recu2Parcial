#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED

typedef struct{
int id;
char marca[20];
int tipo;
float peso;
}eVehiculo;

//constructor base
eVehiculo* new_Vehiculo();
//constructor parametrizado
eVehiculo* new_VehiculoParam(int id, char* marca, int tipo, float peso);

//setters
int vehiculoSetId(eVehiculo* pVeh, int id);
int vehiculoSetMarca(eVehiculo* pVeh, char* marca);
int vehiculoSetTipo(eVehiculo* pVeh, int tipo);
int vehiculoSetPeso(eVehiculo* pVeh, float peso);

//getters
int vehiculo_getId(eVehiculo* this,int* id);
int vehiculo_getMarca(eVehiculo* this,char* marca);
int vehiculo_getTipo(eVehiculo* this,int* tipo);
int vehiculo_getPeso(eVehiculo* this,int* peso);

int controller_saveAsText(char* path , eVehiculo* pVehiculo);






#endif // VEHICULOS_H_INCLUDED
