#include <iostream>
#include <string>

using namespace std;

// PRODUCTOS ABSTRACTOS: BUTTON Y CHECKBOX
class Button {
public:
    virtual ~Button() = default;
    virtual void Draw() const = 0;
};

class CheckBox {
public:
    virtual ~CheckBox() = default;
    virtual void Draw() const = 0;
};

// PRODUCTOS CONCRETOS: WINDOWS
class WinButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando Button Windows" << endl;
    }
};

class WinCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando CheckBox Windows" << endl;
    }
};

// PRODUCTOS CONCRETOS: MAC
class MacButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando Button Mac" << endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando CheckBox Mac" << endl;
    }
};

// PRODUCTOS CONCRETOS: LINUX (Extension solicitada)
class LinuxButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando Button Linux" << endl;
    }
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando CheckBox Linux" << endl;
    }
};

// FABRICA ABSTRACTA: GUIFACTORY
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual Button* CrearButton() const = 0;
    virtual CheckBox* CrearCheckBox() const = 0;
};

// FABRICAS CONCRETAS: WINDOWS, MAC Y LINUX
class WinFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new WinButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new WinCheckBox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new MacButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new MacCheckBox();
    }
};

class LinuxFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new LinuxButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new LinuxCheckBox();
    }
};

// CLIENTE: APPLICATION
void Aplicacion(const GUIFactory& f, int os) {
    (void)os; // Identificador de SO (1: Windows, 2: Mac, 3: Linux)
    Button* boton = f.CrearButton();
    CheckBox* check = f.CrearCheckBox();

    boton->Draw();
    check->Draw();

    delete boton;
    delete check;
}

// FUNCION PRINCIPAL
int main() {
    cout << "Cliente: Windows" << endl;
    GUIFactory* f1 = new WinFactory();
    Aplicacion(*f1, 1); // 1 - Windows
    delete f1;
    cout << endl;

    cout << "Cliente: Mac" << endl;
    GUIFactory* f2 = new MacFactory();
    Aplicacion(*f2, 2); // 2 - Mac
    delete f2;
    cout << endl;

    cout << "Cliente: Linux" << endl;
    GUIFactory* f3 = new LinuxFactory();
    Aplicacion(*f3, 3); // 3 - Linux
    delete f3;

    return 0;
}