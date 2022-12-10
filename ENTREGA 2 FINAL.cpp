#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void Agregar();
void Lista();
void Archivo();
void Eliminar();
void Modificar();

int jgo, * juego, * genero, * cdj, * anio, * prunt, * total, * subt;
string* nombre, * gene, * cara;
int main()
{
    int opc;
    cout << "1.- AGREGAR ARTICULO" << endl;
    cout << "2.- LISTA DE ARTICULOS" << endl;
    cout << "3.- LIMPIAR PANTALLA" << endl;
    cout << "4.- MODIFICAR ARTICULO" << endl;
    cout << "5.- ELIMINAR ARTICULO" << endl;
    cout << "6.- SALIR" << endl;

    cin >> opc;

    switch (opc)
    {
    case 1:
        Agregar();
        return main();
        break;

    case 2:
        Lista();
        return main();

    case 3:
        system("cls");
        return main();
        break;

    case 4:
        Modificar();
        return main();
        break;

    case 5:
        Eliminar();
        return main();
        break;

    case 6:
        Archivo();
        break;
    }
}

void Agregar()
{
    cout << "Escriba cuantos juegos desea registrar" << endl;
    cin >> jgo;
    prunt = new int[jgo];
    anio = new int[jgo];
    cdj = new int[jgo];
    total = new int[jgo];
    gene = new string[jgo];
    cara = new string[jgo];
    nombre = new string[jgo];

    for (int i = 0; i < jgo; i++)
    {
        cout << "ID del juego : " << i + 1 << endl;
        while (getchar() != '\n');
        cout << "Ingrese nombre del juego : " << endl;
        getline(cin, nombre[i]);
        cout << "Ingrese el genero del juego : " << endl;
        getline(cin, gene[i]);
        cout << "Ingrese descripcion del juego : " << endl;
        getline(cin, cara[i]);
        cout << "Ingrese la cantidad de juegos en existencia : " << endl;
        cin >> cdj[i];
        cout << "Ingrese precio unitario del juego : " << endl;
        cin >> prunt[i];
        cout << "Ingrese el anio de lanzamiento: " << endl;
        cin >> anio[i];
    }
}

void Lista()
{
    
    for (int i = 0; i < jgo; i++)
    {
        if (jgo == 0)
        {
            cout << "Registro eliminado" << i + 1 << endl;
        }
        else
        {
            cout << "ID del juego: " << i + 1 << endl;
            cout << "JUEGO:" << nombre[i] << endl;
            cout << "GENERO:" << gene[i] << endl;
            cout << "CARACTERISTICAS:" << cara[i] << endl;
            cout << "JUEGOS EXISTENTES:" << cdj[i] << endl;
            cout << "PRECIO UNITARIO:" << prunt[i] << endl;
            total[i] = (prunt[i] * .16) + prunt[i];
            cout << "PRECIO TOTAL: " << total[i] << endl;
            cout << "AÑO DE LANZAMIENTO: " << anio[i] << endl;
        }
    }
}

void Archivo()
{
    ofstream archivo;
    string nombrearchivo;
    string texto;
    int texto2;
    nombrearchivo = "juegos";

    archivo.open("juegos.txt", ios::out);

    if (archivo.fail())
    {
        cout << "Error no se pudo crear el archivo";
        exit(1);
    }
    for (int i = 0; i < jgo; i++)
    {
        if (anio[i] == 0)
        {

        }
        else
        {
            texto = nombre[i];
            archivo << texto << '\n';
            texto = gene[i];
            archivo << texto  << '\n';
            texto = cara[i];
            archivo << texto << '\n';
            texto2 = cdj[i];
            archivo << texto2 << '\n';
            texto2 = prunt[i];
            archivo << texto2  <<'\n';
            texto2 = total[i];
            archivo << texto2  << '\n';
            texto2 = anio[i];
            archivo << texto2 <<'\n';
        }
    }
    archivo.close();
}

void Eliminar()
{
    int j;
    cout << "Ingrese el juego a eliminar ";
    cin >> j;
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        cout << "Eliminar juego : " << j + 1 << endl;

        prunt[i] = 0;
        anio[i] = 0;
        cdj[i] = 0;
        subt[i] = 0;
        gene[i] = " ";
        cara[i] = " ";
        nombre[i] = " ";
    }
}

void Modificar()
{
    int j, opcion;
    cout << "Ingrese el ID del juego a modificar";
    cin >> j;
    j = j - 1;
    cout << "ingrese que desea modificar " << endl;
    cout << "1. - Nombre del juego" << endl;
    cout << "2. - genero " << endl;
    cout << "3.- caracteristicas" << endl;
    cout << "4. - Cantidad de juegos en exitencia" << endl;
    cout << "5. - Precio unitario" << endl;
    cout << "6. - anio de lanzamiento" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            cout << "Ingrese nombre del juego: " << endl;
            getline(cin, nombre[i]);
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            cout << "Ingrese el genero: " << endl;
            getline(cin, gene[i]);

        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            cout << "Ingrese la descripcion del juego: " << endl;
            getline(cin, cara[i]);
        }
    case 4:
        for (int i = j; i == j; i++)
        {
            cout << "Ingrese la cantidad del juegos existentes : " << endl;
            cin >> cdj[i];
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            cout << "Ingrese precio unitario del juego: " << endl;
            cin >> prunt[i];
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            for (int anio = 1000; anio < 2023; anio++)
                cout << "anio de lanzamiento: " << endl;
            cin >> anio[i];
        }
    }
}