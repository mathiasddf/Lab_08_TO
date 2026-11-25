#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// PRODUCTO ABSTRACTO: RECETA (equivalente a Toy en Object.cpp)
class Receta {
protected:
    string nombre;
    string lugarOrigen;
    string dificultad;
    int tiempoMinutos;
    int porciones;
    float costoEstimado;
    vector<string> ingredientes;

public:
    virtual ~Receta() {}

    virtual void prepararIngredientes() = 0;
    virtual void combinarIngredientes() = 0;
    virtual void cocinar() = 0;
    virtual void emplatar() = 0;
    virtual void mostrarReceta() = 0;
};

// PRODUCTO CONCRETO 1: ROCOTO RELLENO
class RocotoRelleno : public Receta {
public:
    RocotoRelleno() {
        nombre = "Rocoto Relleno con Pastel de Papa";
        lugarOrigen = "Arequipa, Peru";
        dificultad = "Media";
        tiempoMinutos = 75;
        porciones = 4;
        costoEstimado = 38.50f;
        ingredientes = {
            "4 rocotos frescos desvenados",
            "500g carne de res picada a cuchillo",
            "2 cebollas rojas, ajo y aji panca",
            "Mani tostado, pasas y aceitunas",
            "Queso paria en laminas y leche evaporada"
        };
    }

    void prepararIngredientes() override {
        cout << "  [1] Desvenando rocotos y hervir 3 veces con azucar y vinagre." << endl;
    }
    void combinarIngredientes() override {
        cout << "  [2] Sofriendo aderezo de cebolla, carne, mani tostado y pasas." << endl;
    }
    void cocinar() override {
        cout << "  [3] Rellenando rocotos, cubriendo con queso y horneando a 180 C por 30 min." << endl;
    }
    void emplatar() override {
        cout << "  [4] Sirviendo caliente junto a una porcion de pastel de papa." << endl;
    }

    void mostrarReceta() override {
        cout << "\n------------------------------------------------------------" << endl;
        cout << " RECETA       : " << nombre << endl;
        cout << " LUGAR ORIGEN : " << lugarOrigen << endl;
        cout << " DIFICULTAD   : " << dificultad << " | TIEMPO: " << tiempoMinutos << " min | PORCIONES: " << porciones << endl;
        cout << " COSTO APROX. : S/. " << fixed << setprecision(2) << costoEstimado << endl;
        cout << " INGREDIENTES :" << endl;
        for (const auto& ing : ingredientes) {
            cout << "   - " << ing << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
};

// PRODUCTO CONCRETO 2: CEVICHE CLASICO
class CevicheClasico : public Receta {
public:
    CevicheClasico() {
        nombre = "Ceviche Clasico de Pescado";
        lugarOrigen = "Costa del Peru";
        dificultad = "Facil";
        tiempoMinutos = 25;
        porciones = 2;
        costoEstimado = 32.00f;
        ingredientes = {
            "400g filete de pescado blanco fresco en cubos",
            "8 limones frescos recien exprimidos",
            "1 cebolla roja en pluma y aji limo picado",
            "Culantro fresco, sal y pimienta",
            "Camote glaseado, choclo desgranado y cancha serrana"
        };
    }

    void prepararIngredientes() override {
        cout << "  [1] Cortando pescado fresco en cubos y cebolla roja en corte pluma." << endl;
    }
    void combinarIngredientes() override {
        cout << "  [2] Sazonando pescado con sal, aji limo y culantro picado." << endl;
    }
    void cocinar() override {
        cout << "  [3] Agregando jugo de limon frio para coccion citrica inmediata (3 min)." << endl;
    }
    void emplatar() override {
        cout << "  [4] Emplatando sobre hoja de lechuga con camote, choclo y cancha." << endl;
    }

    void mostrarReceta() override {
        cout << "\n------------------------------------------------------------" << endl;
        cout << " RECETA       : " << nombre << endl;
        cout << " LUGAR ORIGEN : " << lugarOrigen << endl;
        cout << " DIFICULTAD   : " << dificultad << " | TIEMPO: " << tiempoMinutos << " min | PORCIONES: " << porciones << endl;
        cout << " COSTO APROX. : S/. " << fixed << setprecision(2) << costoEstimado << endl;
        cout << " INGREDIENTES :" << endl;
        for (const auto& ing : ingredientes) {
            cout << "   - " << ing << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
};

// PRODUCTO CONCRETO 3: PIZZA NAPOLITANA
class PizzaNapolitana : public Receta {
public:
    PizzaNapolitana() {
        nombre = "Pizza Napolitana Artesanal";
        lugarOrigen = "Napoles, Italia";
        dificultad = "Media";
        tiempoMinutos = 90;
        porciones = 4;
        costoEstimado = 42.00f;
        ingredientes = {
            "500g harina de fuerza, agua, sal y levadura fresca",
            "200g salsa de tomate San Marzano triturado",
            "250g queso mozzarella fior di latte",
            "Hojas de albahaca fresca",
            "Aceite de oliva extra virgen"
        };
    }

    void prepararIngredientes() override {
        cout << "  [1] Amasando masa madre y dejando fermentar; triturando tomates." << endl;
    }
    void combinarIngredientes() override {
        cout << "  [2] Estirando disco de masa y cubriendo con salsa y mozzarella." << endl;
    }
    void cocinar() override {
        cout << "  [3] Horneando a alta temperatura (250 C) hasta dorar bordes." << endl;
    }
    void emplatar() override {
        cout << "  [4] Decorando con hojas de albahaca fresca y aceite de oliva." << endl;
    }

    void mostrarReceta() override {
        cout << "\n------------------------------------------------------------" << endl;
        cout << " RECETA       : " << nombre << endl;
        cout << " LUGAR ORIGEN : " << lugarOrigen << endl;
        cout << " DIFICULTAD   : " << dificultad << " | TIEMPO: " << tiempoMinutos << " min | PORCIONES: " << porciones << endl;
        cout << " COSTO APROX. : S/. " << fixed << setprecision(2) << costoEstimado << endl;
        cout << " INGREDIENTES :" << endl;
        for (const auto& ing : ingredientes) {
            cout << "   - " << ing << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
};

// FABRICA: RECETAFACTORY (equivalente a ToyFactory.cpp)
class RecetaFactory {
public:
    static Receta* createReceta(int type) {
        Receta* receta = nullptr;

        switch (type) {
            case 1:
                receta = new RocotoRelleno();
                break;
            case 2:
                receta = new CevicheClasico();
                break;
            case 3:
                receta = new PizzaNapolitana();
                break;
            default:
                cout << "  [!] Tipo de receta invalido, ingresa otra opcion." << endl;
                return nullptr;
        }

        cout << "\n>> Iniciando preparacion en RecetaFactory..." << endl;
        receta->prepararIngredientes();
        receta->combinarIngredientes();
        receta->cocinar();
        receta->emplatar();

        return receta;
    }
};

// CLIENTE (main)
int main() {
    int type;
    cout << "============================================================" << endl;
    cout << "        FABRICA DE RECETAS DE COCINA (PATRON FACTORY)" << endl;
    cout << "============================================================" << endl;

    while (true) {
        cout << "\nSelecciona una receta (1: Rocoto Relleno | 2: Ceviche | 3: Pizza Napolitana | 0: Salir): ";
        cin >> type;

        if (!type) {
            break;
        }

        Receta* r = RecetaFactory::createReceta(type);
        if (r) {
            r->mostrarReceta();
            delete r;
        }
    }

    cout << "Saliendo del recetario..." << endl;
    return 0;
}